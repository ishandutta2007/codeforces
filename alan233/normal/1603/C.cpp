// Author: wlzhouzhuan
#pragma GCC optimize(2, 3, "Ofast")
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

const int N = 100005;
const int mod = 998244353;

//map<int, pii> dp[N];

pii dp[2][N];
pii operator + (pii a, pii b) {
  return {(a.fir + b.fir) % mod, (a.sec + b.sec) % mod};
}
int a[N];
int n;

void solve() {
  n = read();
  rep(i, 1, n) a[i] = read();
  int now = 1;
  int ans = 0;
  per(i, n, 1) {
    now ^= 1;
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
//      cerr << "l = " << l << " r = " << r << '\n';
      dp[now][a[i] / l] = make_pair(0, 0);
//      cerr << "!\n";
    } 
    
//    cerr << "!\n";
    
    dp[now][a[i]] = dp[now][a[i]] + make_pair(1, 0);
    
//    cerr << "!\n";
    
    if (i != n) for (int l = 1, r; l <= a[i + 1]; l = r + 1) {
      r = a[i + 1] / (a[i + 1] / l);
      int x = a[i + 1] / l;
      pii y = dp[now ^ 1][x];
      int t = (a[i] + x - 1) / x;
      dp[now][a[i] / t] = dp[now][a[i] / t] + make_pair(y.fir, (y.sec + 1ll * y.fir * (t - 1) % mod));
    }
    for (int l = 1, r; l <= a[i]; l = r + 1) {
      r = a[i] / (a[i] / l);
      ans = (ans + dp[now][a[i] / l].sec) % mod;
    }
//    printf("ans = %d\n", ans);
  } 
  printf("%d\n", ans); 
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}

/*
1
3
5 4 3
*/