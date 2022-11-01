#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  cin >> n >> m;
  int x = 1, y = 1;
  while (m > 1) {
    for (int i = 1, j = n; i <= n; ++i, --j) {
      printf("%d %d\n", i, y);
      printf("%d %d\n", j, y + m - 1);
    }
    m -= 2, ++y;
  }
  if (m) {
    int i, j;
    for (i = 1, j = n; i < j; ++i, --j) {
      printf("%d %d\n", i, y);
      printf("%d %d\n", j, y);
    }
    if (i == j) printf("%d %d\n", i, y);
  }
  return 0;
}