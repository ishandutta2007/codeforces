#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 100010;

int n, k, a[N];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  int sub = 0;
  for (int i = 1, j = 1; i <= k; ++i) {
    while (j <= n and a[j] - sub == 0) ++j;
    if (j > n) puts("0");
    else {
      printf("%d\n", a[j] - sub);
      sub = a[j];
    } 
  }
  return 0;
}