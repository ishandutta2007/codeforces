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

const int N = 2025;
const int mod = 998244353;

int dp[N], n, k;

void brute1() {
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++)
      dp[j] = (dp[j] + dp[j - i]) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + dp[i]) % mod;
  print(ans, '\n');
  exit(0);
}
void brute2() {
  dp[0] = 1;
  for (int i = 1; i * (i + 1) / 2 <= n; i++) {
    int x = i * (i + 1) / 2;
    for (int j = x; j <= n; j++)
      dp[j] = (dp[j] + dp[j - x]) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + dp[i]) % mod;
  print(ans, '\n');
  exit(0);
}

int a[N], len, ans;
inline bool check() {
  static int b[N], c[N], lenb, lenc;
  lenb = len, lenc = 0;
  rep(i, 1, len) b[i] = a[i];
  rep(j, 1, k - 2) {
    int k1 = 0;
    per(i, lenb, 1) {
      ++k1;
      if (j <= k - 2 && k1 > 22) return false;
      while (b[i]--) {
        c[++lenc] = k1;
        if (lenc > n) return false;
      }
    }
    lenb = lenc, lenc = 0;
    rep(i, 1, lenb) b[i] = c[i];
  }
  int _ = 0;
  rep(i, 1, lenb) _ += b[i] * (lenb + 1 - i);
  return _ <= n;
}
bool brute3(int sum, int las) {
  if (sum && !check()) return 0;
  if (sum) ans++;
  for (int i = las; sum + i <= 64; i++) {
    a[++len] = i;
    bool t = brute3(sum + i, i);
    len--;
    if (!t) break;
  }
  return 1;
}

int main() {
  n = read(), k = read();
  if (k == 1) brute1();
  if (k == 2) brute2();
  brute3(0, 1), print(ans, '\n');
  return 0;
}