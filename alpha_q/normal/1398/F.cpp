#include <bits/stdc++.h>

using namespace std;

const int LG = 20;
const int N = 1000003;

char s[N];
int n, f[N], sp[LG][N], lg[N];

inline int get (int l, int r) {
  int x = lg[r - l + 1];
  return max(sp[x][l], sp[x][r - (1 << x) + 1]);
}

int main() {
  for (int i = 2; i < N; ++i) {
    lg[i] = 1 + lg[i >> 1];
  }
  scanf("%d %s", &n, s + 1);
  int lastZero = n + 1, lastOne = n + 1;
  for (int i = n; i >= 1; --i) {
    if (s[i] == '?') {
      f[i] = 1 + f[i + 1];
    } else {
      if (s[i] == '0') {
        f[i] = lastOne - i;
        lastZero = i;
      } else {
        f[i] = lastZero - i;
        lastOne = i;
      }
    }
    sp[0][i] = f[i];
  }
  for (int j = 1; j < LG; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      sp[j][i] = max(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
    }
  }
  for (int x = 1; x <= n; ++x) {
    int ans = 0;
    for (int i = 1; i <= n;) {
      if (f[i] >= x) {
        ++ans, i += x;
        continue;
      }
      int lo = i, hi = n + 1;
      while (lo < hi) {
        int mid = lo + hi >> 1;
        if (get(i, mid) < x) lo = mid + 1;
        else hi = mid;
      }
      if (lo <= n) ++ans, i = lo + x;
      else break;
    }
    printf("%d ", ans);
  }
  cout << '\n';
  return 0;
}