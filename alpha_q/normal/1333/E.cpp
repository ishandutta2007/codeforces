#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n, ans[N][N], g[4][4] = {{4, 3, 6, 12}, {7, 5, 9, 15}, {14, 1, 11, 10}, {13, 8, 16, 2}};

int main() {
  cin >> n;
  if (n < 3) {
    cout << "-1\n";
    return 0;
  }
  if (n == 3) {
    cout << "1 2 4\n5 3 8\n9 6 7\n";
    return 0;
  }
  int ro = 1, at = 0;
  if (n & 1) {
    for (int j = n; j >= 1; --j) {
      ans[ro][j] = ++at;
    }
    ++ro;
  }
  while (ro <= n - 4) {
    for (int j = 1; j <= n; ++j) {
      ans[ro][j] = ++at;
    }
    ++ro;
    for (int j = n; j >= 1; --j) {
      ans[ro][j] = ++at;
    }
    ++ro;
  }
  for (int j = 1; j <= n - 4; ++j) {
    ans[ro][j] = ++at;
  }
  ++ro;
  for (int j = n - 4; j >= 1; --j) {
    ans[ro][j] = ++at;
  }
  ++ro;
  if (n > 4) ans[ro][1] = ++at;
  ++ro;
  for (int j = 1; j <= n - 4; ++j) {
    ans[ro][j] = ++at;
  }
  --ro;
  for (int j = n - 4; j > 1; --j) {
    ans[ro][j] = ++at;
  }
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ans[n - 3 + i][n - 3 + j] = at + g[i][j];
    }
  }
  if (n == 5) swap(ans[4][1], ans[5][1]);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", ans[i][j]);
    }
    puts("");
  }
  return 0;
}