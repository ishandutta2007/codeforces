#include <stdio.h>
#include <math.h>

int main () {
  int k;
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &k);
    int a = (int) sqrt(k-1);
    int b = k - pow(a, 2);
    if (b <= a) {
      printf("%d %d\n", b, a+1);
    }
    else {
      printf("%d %d\n", a+1, 2*a+2-b);
    }
  }
}