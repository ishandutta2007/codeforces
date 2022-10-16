// Author: wlzhouzhuan
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

int n, a[15], len;

int dp[15][2][2][2];
int dfs(int len, int up, int pre1, int pre2) {
//  printf("len = %d, up = %d, pre1 = %d, pre2 = %d\n", len, up, pre1, pre2);
  if (!len) return !pre1 && !pre2;
  if (dp[len][pre1][pre2][up] != -1) return dp[len][pre1][pre2][up];
  int maxx = (up ? a[len] : 9), ans = 0;
  for (int i = 0; i <= 9; i++) {
    for (int j = 0; j <= 9; j++) {
      int go = i + j;
      if (pre1) go -= 10;
      if (go == maxx) ans += dfs(len - 1, up && (go == maxx), pre2, 0);
      ++go;
      if (go == maxx) ans += dfs(len - 1, up && (go == maxx), pre2, 1);
    }
  }
  return dp[len][pre1][pre2][up] = ans;
}
void solve() {
  memset(dp, -1, sizeof(dp));
  n = read();
  len = 0;
  while (n > 0) a[++len] = n % 10, n /= 10;
  print(dfs(len, 1, 0, 0) - 2, '\n');
}
int main() {
  int T = read();
  while (T--) solve();
  return 0;
}