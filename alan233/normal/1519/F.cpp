// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int pw5[] = {1, 5, 25, 125, 625, 3125};

int dp[7][15625][5];
int tem[15625][6];
int a[6], b[6], c[6][6], n, m;
int inf;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int zip = 0;
  for (int i = 0; i < m; i++) scanf("%d", &b[i]), zip += pw5[i] * b[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      scanf("%d", &c[i][j]);
  for (int i = 0; i <= zip; i++) {
    int tmp = i;
    for (int j = m - 1; j >= 0; j--) 
      tem[i][j] = tmp / pw5[j], tmp %= pw5[j];
  }
  memset(dp, 0x3f, sizeof(dp)), inf = dp[0][0][0];
  dp[0][zip][a[0]] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = zip; j >= 0; j--) {
      for (int k = a[i]; k >= 0; k--) {
        if (dp[i][j][k] == inf) continue;
        // printf("dp[%d][%d][%d] = %d\n", i, j, k, dp[i][j][k]);
        for (int o = 0; o < m; o++)
          for (int num = 1; num <= tem[j][o] && num <= k; num++)
            ckmin(dp[i][j - pw5[o] * num][k - num], dp[i][j][k] + c[i][o]);
      }
      ckmin(dp[i + 1][j][a[i + 1]], dp[i][j][0]);
    }
  }
  int ans = inf;
  for (int j = 0; j <= zip; j++) ckmin(ans, dp[n][j][0]);
  if (ans >= inf) ans = -1;
  printf("%d\n", ans);
  return 0;
}