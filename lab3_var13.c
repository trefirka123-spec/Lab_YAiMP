#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_natural_string(const char *str) {
    if (str[0] =='\0' || str[0] == '0' || str[0] == '-') {
 return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_integer_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
     start += 1;
    }

    if (str[start] == '\0') {
 return 0;
    }

    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_float_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
     start += 1;
    }
    
    if (str[start] == '\0') {
 return 0;
    }
    
    int dot_count = 0;
    int digit_count = 0;
    
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return 0;
            }
        } 
        else if (str[i] >= '0' && str[i] <= '9') {
            digit_count++;
        } 
        else {
            return 0;
        }
    }

    if (digit_count == 0) {
        return 0;
    }

    return 1;
}

int main() {
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;

    while (1) {
        printf("Введите N: ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
     continue;
        }
        if (is_natural_string(N_str)) {
         N = atoi(N_str);
     free(N_str);
     break;
        } else {
     free(N_str); 
     printf("Чичло должно быть натуральным!\n");
        }
    }

    while (1) {
        printf("Введите M: ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str); 
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
     free(M_str);
            break;
        } else {
     printf("Чичло должно быть натуральным!\n");
     free(M_str); 
 }
    }
    
    float *Matrix = malloc(M * N * sizeof(*Matrix));
    
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         char *element = NULL;
         float value;
         
         while (1) {
          printf("Введите элемент [%i][%i]: ", i, j);
          if (scanf("%ms", &element) != 1) {
                  printf("Ошибка чтения.\n");
                  free(element);
           continue;
          }
          if (is_float_string(element)) {
               value = atof(element);
           free(element);
           break;
          } else {
           free(element); 
           printf("Некорректный ввод!\n");
          }
     }
        Matrix[i*M + j] = value;
    }
    }

    //

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i > j && Matrix[i * M + j] < 0) {
                count++;
            }
        }
    }

    printf("Отрицательных элементов под главной диагональю: %d\n", count);

    for (int i = 0; i < N; i++) {
        double S = 5.0;
        for (int j = 0; j < M; j++) {
            double a = Matrix[i * M + j];
            S += sin(a) + a / 7.0;
        }
        printf("S для строки %d = %f\n", i + 1, S);
    }

    free(Matrix);
    return 0;
}