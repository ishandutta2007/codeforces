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

const int N = 200005;

struct DSU {
  int f[N];
  void init(int n) { iota(f + 1, f + n + 1, 1); }
  int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
  void merge(int x, int y) {
    f[find(x)] = find(y);
  }
  bool test(int x, int y) {
    return find(x) != find(y);
  }
} f1, f2;
 
vector<pii> ans;
int n, m1, m2;
 
int main() {
  n = read(), m1 = read(), m2 = read();
  f1.init(n), f2.init(n);
  rep(i, 1, m1) {
    int u = read(), v = read();
    f1.merge(u, v);
  }
  rep(i, 1, m2) {
    int u = read(), v = read();
    f2.merge(u, v);
  }
  rep(i, 1, n) {
    if (f1.test(1, i) && f2.test(1, i)) {
      ans.pb({1, i});
      f1.merge(1, i), f2.merge(1, i);
    } 
  }
  int j = 1;
  rep(i, 1, n) {
    if (!f1.test(1, i)) continue; 
    while (j <= n && !f2.test(1, j)) j++;
    if (j <= n) ans.pb({i, j}), f1.merge(i, j), f2.merge(i, j);
  }
  print(SZ(ans), '\n');
  for (auto it: ans) print(it.fir, ' '), print(it.sec, '\n');
  return 0;
}