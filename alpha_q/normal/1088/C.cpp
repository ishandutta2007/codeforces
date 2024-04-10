#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int N = 2010;
const int M = 100005;

int n, a[N];

bool check() {
  for (int i = 1; i <= n; ++i) {
    a[i] += M;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      a[j] %= (a[i] - i + 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] != i - 1) return 0;
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  printf("%d\n", n + 1);
  printf("1 %d %d\n", n, M);
  for (int i = 1; i <= n; ++i) {
    printf("2 %d %d\n", i, a[i] + M - i + 1);
  }
  // assert(check());
  return 0;
}