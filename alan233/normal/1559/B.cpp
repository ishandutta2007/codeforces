// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
#pragma GCC target("avx", "avx2")
#ifdef xay
#define D(...) fprintf(stderr, "[D]" __VA_ARGS__)
#else
#define D(...) ((void)0)
#endif
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
const int N = 1005;
char a[N];
int dp[N][2], from[N][2], n;
void solve() {
  mset(dp, 0x3f); dp[0][0] = dp[0][1] = 0;
  scanf("%d%s", &n, a + 1);
  rep(i, 1, n) {
    if (a[i] != 'B') {
      if (dp[i - 1][0] + 1 <= dp[i - 1][1])
        dp[i][0] = dp[i - 1][0] + 1, from[i][0] = 0;
      else
        dp[i][0] = dp[i - 1][1], from[i][0] = 1;
    }
    if (a[i] != 'R') {
      if (dp[i - 1][0] <= dp[i - 1][1] + 1)
        dp[i][1] = dp[i - 1][0], from[i][1] = 0;
      else
        dp[i][1] = dp[i - 1][1] + 1, from[i][1] = 1;
    }
  }
  int st = (dp[n][0] <= dp[n][1] ? 0 : 1);
  stack<char> stk;
  for (int i = n; i >= 1; i--) {
    stk.push(st ? 'B' : 'R');
    st = from[i][st];
  }
  while (!stk.empty()) {
    putchar(stk.top()); stk.pop();
  }
  putchar('\n');
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}