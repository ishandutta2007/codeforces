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

const int N = 3000005;
const int mod = 1e9 + 7;

int fac[N], ifac[N];
int qpow(int a, int b = mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
void init(int n) {
  fac[0] = 1; rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = qpow(fac[n]); per(i, n, 1) ifac[i - 1] = 1ll * ifac[i] * i % mod;
}
int C(int n, int m) {
  if (n < m || m < 0) return 0;
  else return 1ll * fac[n] * ifac[n - m] % mod * ifac[m] % mod;
}

int dp[N][3], inv3 = qpow(3);
int n, q;

int main() {
  n = read(), q = read();
  init(3 * n + 1);
  dp[0][0] = dp[0][1] = dp[0][2] = n;
  for (int x = 1; x <= 3 * n; x++) {
    int sum = C(3 * n + 1, x + 1);
    dp[x][2] = (sum - 2ll * dp[x - 1][2] - dp[x - 1][1] + 3ll * mod) % mod * inv3 % mod;
    dp[x][1] = (dp[x][2] + dp[x - 1][2]) % mod;
    dp[x][0] = (dp[x][1] + dp[x - 1][1]) % mod;
  }
  while (q--) { int x = read(); print(dp[x][0], '\n'); }
  return 0;
}