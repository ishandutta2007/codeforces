#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int M = 205;
const int N = 100010;
const int MOD = 998244353;

int n, a[N];
int f[2][2][M], sum[2][2][M];

inline int get (int at, int ord, int l, int r) {
  if (l > r) return 0;
  int yo = sum[at][ord][r] - sum[at][ord][l - 1];
  if (yo < 0) yo += MOD;
  return yo;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int pre = 0, now = 1;
  for (int last = 1; last <= 200; ++last) {
    f[1][1][last] = 1;
    sum[1][1][last] = last;
  }
  for (int at = n; at >= 1; --at) {
    swap(pre, now);
    for (int ord = 0; ord < 2; ++ord) {
      for (int last = 1; last <= 200; ++last) {
        int &ret = f[now][ord][last];
        ret = 0;
        if (a[at] == -1) {
          if (ord) {
            ret = get(pre, 0, last + 1, 200) + get(pre, 1, 1, last);
            if (ret >= MOD) ret -= MOD;
          } else {
            ret = f[pre][1][last] + get(pre, 0, last + 1, 200);
            // if (at == 2 and ord == 0 and last == a[1]) cout << ret << endl;
            if (ret >= MOD) ret -= MOD;
          }
        } else {
          if (ord or a[at] >= last) {
            ret = f[pre][last >= a[at]][a[at]];
          }
        }
        // if (at == n and ord) cout << last << " --> " << f[now][ord][last] << endl;
        sum[now][ord][last] = ret + sum[now][ord][last - 1];
        if (sum[now][ord][last] >= MOD) sum[now][ord][last] -= MOD;
      }
    }
  }
  int ans = 0;
  if (a[1] == -1) {
    for (int i = 1; i <= 200; ++i) {
      ans += f[pre][0][i];
      if (ans >= MOD) ans -= MOD;
    }
  } else ans = f[pre][0][a[1]];
  printf("%d\n", ans);
  return 0;
}