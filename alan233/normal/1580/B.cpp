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

struct FastMod {
  typedef unsigned long long ULL;
  typedef __uint128_t LLL;
  ULL b, m;
  void init(ULL b) { this->b = b, m = ULL((LLL(1) << 64) / b); }
  ULL operator()(ULL a){
    ULL q = (ULL)((LLL(m) * a) >> 64);
    ULL r = a - q * b;
    return r >= b ? r - b : r;
  }
} M;
inline int mul(int a, int b) { return M(1ull * a * b); }

int C[105][105], f[105]; // f  

// dp[len][dep][num]  len ,  dep,  num  d  
int dp[105][105][105]; 
int n, m, k, p;

int dfs(int len, int dep, int num) {
  if (len < num) return 0;
//  printf("dfs %d %d %d\n", len, dep, num);
  if (!len) return num == 0;
  if (dep == m) {
    if (num != 1) return 0;
    return f[len];
  }
  if (~dp[len][dep][num]) return dp[len][dep][num];
  // int &ans = dp[len][dep][num]; ans = 0;
  ll ans = 0;
  rep(l, 0, len - 1) {
    rep(j, max(0, num + l - len + 1), min(num, l)) {
      ans += mul(mul(C[len - 1][l], dfs(l, dep + 1, j)), dfs(len - 1 - l, dep + 1, num - j));
    }
  }
  return dp[len][dep][num] = ans % p;
}

int main() {
  mset(dp, -1);
  cin >> n >> m >> k >> p;
  M.init(p);
  if (m - 1 + k > n) {
    puts("0");
    return 0;
  }
  rep(i, 0, n) {
    C[i][0] = 1;
    rep(j, 1, i)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % p;
  }
  f[0] = 1;
  rep(i, 1, n) {
    rep(j, 0, i - 1)
      f[i] = (f[i] + 1ll * C[i - 1][j] * f[j] % p * f[i - 1 - j]) % p;
//    printf("f[%d] = %d\n", i, f[i]);
  }
  cout << dfs(n, 1, k) << '\n';
  return 0;
}