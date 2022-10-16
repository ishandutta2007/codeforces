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

const int N = 4000005;

int dp[N], sum[N], n, mod;
int d[N];

int main() {
  cin >> n >> mod;
  dp[1] = 1, sum[1] = 1;
  for (int z = 2; z <= n; z++) {
    int L = z, R = z * 2;
    d[L] = (d[L] + dp[1]) % mod;
    if (R <= n) d[R] = (d[R] + mod - dp[1]) % mod;
  }
  for (int i = 2; i <= n; i++) {
    d[i] = (d[i] + d[i - 1]) % mod;
    dp[i] = (sum[i - 1] + d[i]) % mod;
    sum[i] = (sum[i - 1] + dp[i]) % mod;
    for (int z = 2; i * z <= n; z++) {
      int L = z * i, R = z * (i + 1);
      d[L] = (d[L] + dp[i]) % mod;
      if (R <= n) d[R] = (d[R] + mod - dp[i]) % mod;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}