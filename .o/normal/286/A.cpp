#include <stdio.h>

int N;

int main() {
 scanf("%d", &N);
 if(N % 4 == 2 || N % 4 == 3) return 0 & puts("-1");

 for(int i = 0; i < N / 2; i++) {
   printf("%d ", (i % 2) ? (N - i + 1) : (i + 2) );
 }

 if(N % 4 == 1) printf("%d ", N / 2 + 1);

 for(int i = N / 2 - 1; i >= 0; i -= 2) {
  printf("%d %d ", i, N - i);
 }
 
 return 0;
}