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

const int N = 2005;
const int inf = 1e9;

char tmp[N];
int go[N][N];
int n, m;

ll a[N], f[N], g[N];
ll sqr(ll x) { return x * x; }
void solve(ll *dp) {
  static int q[N], ql, qr;
  ql = 1, qr = 0;
  auto slope = [&](int x, int y) {
    return (a[x] + sqr(x) - a[y] - sqr(y)) / 2. / (x - y);
  };
  
  rep(i, 0, n) {
    while (ql < qr && slope(q[qr - 1], q[qr]) >= slope(q[qr], i)) qr--;
    q[++qr] = i;
    while (ql < qr && slope(q[ql], q[ql + 1]) <= i) ql++;
    /*
    printf("i = %d, ", i);
    rep(_, ql, qr) printf("%d ", q[_]);
    puts("");
    */
    dp[i] = a[q[ql]] + sqr(i - q[ql]);
  }
}

int main() {
  n = read(), m = read();
  rep(i, 0, n) {
    scanf("%s", tmp);
    rep(j, 0, m) {
      if (tmp[j] == '1') go[i][j] = 0;
      else go[i][j] = inf;
    }
  }
  rep(i, 0, n) {
    rep(j, 1, m) ckmin(go[i][j], go[i][j - 1] + 1);
    per(j, m - 1, 0) ckmin(go[i][j], go[i][j + 1] + 1); 
  }
  ll ans = 0;
  rep(j, 0, m) {
    rep(i, 0, n) a[i] = sqr(go[i][j]);
    solve(f);
    reverse(a, a + n + 1);
    solve(g);
    reverse(g, g + n + 1);
    rep(i, 0, n) {
      ans += min(f[i], g[i]);
//      printf("(%d %d)", f[i], g[i]);
    }
//    puts("");
//    system("pause");
  }
  print(ans, '\n');
  return 0;
}