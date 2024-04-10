#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

const int MASK = 36;
const int N = 200010;

int n, k, q, pt[7], s[MASK][N + N], t[MASK][N + N];

void updateMin (int idx, int p, int v) {
  for (s[idx][p += n] = v; p > 1; p >>= 1) {
    s[idx][p >> 1] = min(s[idx][p], s[idx][p ^ 1]);
  }
}

void updateMax (int idx, int p, int v) {
  for (t[idx][p += n] = v; p > 1; p >>= 1) {
    t[idx][p >> 1] = max(t[idx][p], t[idx][p ^ 1]);
  }
}

int getMin (int idx, int l, int r) {
  int ans = INT_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = min(ans, s[idx][l++]);
    if (r & 1) ans = min(ans, s[idx][--r]);
  }
  return ans;
}

int getMax (int idx, int l, int r) {
  int ans = INT_MIN;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, t[idx][l++]);
    if (r & 1) ans = max(ans, t[idx][--r]);
  }
  return ans;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", pt + j);
    }
    for (int mask = 0; mask < 1 << k; ++mask) {
      int cur = 0;
      for (int j = 0; j < k; ++j) {
        if (mask & 1 << j) cur += pt[j];
        else cur -= pt[j];
      }
      updateMin(mask, i, cur);
      updateMax(mask, i, cur);
    }
  }
  cin >> q;
  while (q--) {
    int cmd; scanf("%d", &cmd);
    if (cmd == 1) {
      int at; scanf("%d", &at); --at;
      for (int j = 0; j < k; ++j) scanf("%d", pt + j);
      for (int mask = 0; mask < 1 << k; ++mask) {
        int cur = 0;
        for (int j = 0; j < k; ++j) {
          if (mask & 1 << j) cur += pt[j];
          else cur -= pt[j];
        }
        updateMin(mask, at, cur);
        updateMax(mask, at, cur);
      }
    } else {
      int l, r, ans = 0; scanf("%d %d", &l, &r); --l;
      for (int mask = 0; mask < 1 << k; ++mask) {
        ans = max(ans, getMax(mask, l, r) - getMin(mask, l, r));
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}