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

const int N = 300005;

int X[N], Y[N], x[N], y[N];
vector<int> numX[N], numY[N];
int n, m, qwq;

void solve() {
  n = read(), m = read(), qwq = read();
  rep(i, 1, n) numX[i].clear();
  rep(i, 1, m) numY[i].clear();
  rep(i, 1, n) X[i] = read(); // ordered
  rep(i, 1, m) Y[i] = read(); // ordered
  rep(i, 1, qwq) {
    x[i] = read(), y[i] = read();
    int t1 = upper_bound(X + 1, X + n + 1, x[i]) - X - 1;
    int t2 = upper_bound(Y + 1, Y + m + 1, y[i]) - Y - 1;
//    printf("i = %d, t1 = %d, t2 = %d\n", i, t1, t2);
    if (X[t1] == x[i] && Y[t2] == y[i]) continue;
    if (X[t1] == x[i]) numY[t2].pb(t1);
    if (Y[t2] == y[i]) numX[t1].pb(t2);
  } 
  ll ans = 0;
  rep(i, 1, n) {
    sort(numX[i].begin(), numX[i].end());
//    printf("i = %d, ", i);
//    for (auto v: numX[i]) printf("%d ", v);
//    puts(""); 
    int lst = 0, haha = 0, pairs = 0;
    for (auto v: numX[i]) {
      if (v == lst) ++haha, ans += pairs;
      else lst = v, pairs += haha, haha = 1, ans += pairs;
    }
  }
//  printf("now ans = %lld\n", ans); 
  rep(i, 1, m) {
    sort(numY[i].begin(), numY[i].end());
    int lst = 0, haha = 0, pairs = 0;
    for (auto v: numY[i]) {
      if (v == lst) ++haha, ans += pairs;
      else lst = v, pairs += haha, haha = 1, ans += pairs;
    }
  }
  print(ans, '\n');
}

int main() {
  int T = read();
  while (T--) {
    solve();
  }
  return 0;
}

/*
2
2 2 4
0 1000000
0 1000000
1 0
1000000 1
999999 1000000
0 999999
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8
*/