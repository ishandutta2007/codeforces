#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int t, d;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &d);
    if (d >= 1 and d <= 3) {
      puts("N");
      continue;
    }
    long double disc = sqrtl(d * (d - 4));
    long double a = 0.5 * (d + disc);
    long double b = 0.5 * (d - disc);
    // assert(a >= 0 and b >= 0);
    printf("Y %0.16f %0.16f\n", (double) a, (double) b);
  }
  return 0;
}