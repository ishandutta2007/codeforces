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

const int N = 1000005;

char tem[N];
int n, m;

void solve() {
  n = read(), m = read();
  vector<vector<int>> a(n + 2, vector<int> (m + 2));
  vector<vector<int>> pre(n + 2, vector<int> (m + 2));
  vector<vector<int>> dp(n + 2, vector<int> (m + 2));
  rep(i, 1, n) {
    scanf("%s", tem + 1);
    rep(j, 1, m) {
      a[i][j] = tem[j] == '1';
    }
  }
  int ans[2]; ans[0] = ans[1] = 0;
  rep(j, 1, m) {
    rep(i, 1, n) {
      dp[i][j] = a[i][j];
      if (j >= 2) dp[i][j] += pre[i][j - 2];
      pre[i][j] = max({pre[i - 1][j - 1], pre[i + 1][j - 1], dp[i][j]});
      ckmax(ans[(i + j) & 1], dp[i][j]);
    }
  }
  print(ans[0] + ans[1], '\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}