#include <stdio.h>
#include <math.h>

int main () {
  int n;
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n);
    int p;
    int a;
    scanf("%d", &p);
    for (int j = 0; j < n-1; j++) {
      scanf("%d", &a);
      p = p & a;
    }
    printf("%d\n", p);
  }
}