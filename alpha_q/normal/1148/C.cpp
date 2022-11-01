#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m, p[N], at[N];
pair <int, int> ans[5 * N];

inline void _swap (int i, int j) {
  at[p[i]] = j, at[p[j]] = i;
  swap(p[i], p[j]);
  ans[++m] = {i, j};
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
    at[p[i]] = i;
  }
  int mid = n >> 1;
  for (int i = 1; i <= n; ++i) {
    // y --> x
    int x = i, y = at[i];
    if (x == y) {
      continue;
    }
    if (abs(x - y) >= mid) {
      _swap(x, y);
      continue;
    }
    if (x <= mid and y <= mid) {
      _swap(x, n);
      _swap(y, n);
      _swap(x, n);
      continue;
    }
    if (x > mid and y > mid) {
      _swap(x, 1);
      _swap(y, 1);
      _swap(x, 1);
      continue;
    }
    if (x > y) swap(x, y);
    _swap(x, n);
    _swap(n, 1);
    _swap(1, y);
    _swap(n, 1);
    _swap(x, n);
  }
  cout << m << '\n';
  for (int i = 1; i <= m; ++i) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}