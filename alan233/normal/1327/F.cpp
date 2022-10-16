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

const int N = 500005;
const int mod = 998244353;
 
inline void add(int &x, int y) { if ((x += y) >= mod) x -= mod; }
inline void sub(int &x, int y) { if ((x -= y) < 0) x += mod; }

int L[N], R[N], X[N];
int dp[N], n, K, m;
int cov[N], pos[N];

int main() {
  n = read(), K = read(), m = read();
  for (int i = 1; i <= m; i++) L[i] = read(), R[i] = read(), X[i] = read();
  int ans = 1;
  for (int bit = 0; bit < K; bit++) {
    for (int i = 1; i <= n; i++) cov[i] = pos[i] = dp[i] = 0;
    for (int i = 1; i <= m; i++) {
      if (X[i] >> bit & 1) cov[L[i]]++, cov[R[i] + 1]--;
      else ckmax(pos[R[i]], L[i]);
    }
    for (int i = 1; i <= n; i++)
      cov[i] += cov[i - 1], ckmax(pos[i], pos[i - 1]);
    int sum = 1; dp[0] = 1;
    int j = 0;
    for (int i = 1; i <= n; i++) {
//      printf("pos[%d] = %d, cov[%d] = %d\n", i, pos[i], i, cov[i]);
      if (!cov[i]) dp[i] = sum, add(sum, dp[i]);
      else dp[i] = 0;
      while (j < pos[i]) sub(sum, dp[j]), j++;
    }
//    printf("bit = %d, sum = %d\n", bit, sum);
    ans = 1ll * ans * sum % mod;
  }
  print(ans, '\n');
  return 0;
}