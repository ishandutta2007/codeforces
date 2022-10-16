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

vector<pii> E;
int n, m;
int fuck[N];

void solve() {
  n = read(), m = read();
  rep(i, 1, n) fuck[i] = 0;
  rep(i, 1, m) {
    int u = read(), _ = read(), v = read();
    fuck[_] = 1;
  }
  rep(i, 1, n) if (!fuck[i]) {
    rep(j, 1, n) {
      if (i != j) printf("%d %d\n", i, j);
    }
    break;
  }
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}