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
#define SZ(x) ((x.size()))
#define int long long
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

struct E {
  int u, v, w;
  friend bool operator < (const E &x, const E &y) {
    if (x.w != y.w) return x.w < y.w;
    else if (x.u != y.u) return x.u < y.u;
    else return x.v < y.v;
  }
};
map<int, int> mp[N];
set<E> gl;
map<E, int> times; 
set<E> adj[N];
int n, m, q;

void add(int u) {
  int cnt = 0;
  for (auto i: adj[u]) {
    if (++cnt > 3) break;
    if (times[i]++ == 1) gl.insert(i);
  }
}
void del(int u) {
  int cnt = 0;
  for (auto i: adj[u]) {
    if (++cnt > 3) break;
    if (--times[i] == 1) gl.erase(i);
  }
}
void add(int u, int v, int w) {
  del(u), del(v), mp[u][v] = w;
  adj[u].insert({u, v, w});
  adj[v].insert({u, v, w}); 
  add(u), add(v);
}
void del(int u, int v, int w) {
  del(u), del(v), mp[u][v] = 0;
  adj[u].erase({u, v, w});
  adj[v].erase({u, v, w});
  add(u), add(v);
}
bool chk(E u, E v) {
  return u.u == v.u || u.u == v.v || u.v == v.u || u.v == v.v;
}
bool chk(E u, E v, E w) {
  set<int> _;
  _.insert(u.u);
  _.insert(u.v);
  _.insert(v.u);
  _.insert(v.v);
  _.insert(w.u);
  _.insert(w.v);
  return _.size() == 3;
}
int query() {
  vector<E> tmp;
  for (int i = 0; i < 6 && !gl.empty(); i++) {
    tmp.pb(*gl.begin()), gl.erase(gl.begin());
  }
//  cerr << "!\n";
  int ans = 0;
  if (chk(tmp[0], tmp[1], tmp[2])) ans = tmp[0].w + tmp[1].w + tmp[3].w;
  else ans = tmp[0].w + tmp[1].w + tmp[2].w;
//  cerr << "!!\n";
  rep(i, 0, SZ(tmp) - 1) {
    rep(j, i + 1, SZ(tmp) - 1) {
      if (!chk(tmp[i], tmp[j])) {
        ckmin(ans, tmp[i].w + tmp[j].w);
      }
    }
  }
  for (auto v: tmp) gl.insert(v);
  return ans;
}

signed main() {
  n = read(), m = read();
  rep(i, 1, m) {
    int u = read(), v = read(), w = read();
    if (u > v) swap(u, v);
    add(u, v, w);
  }
  print(query(), '\n');
  q = read();
  while (q--) {
    int opt = read(), u = read(), v = read(), w;
    if (u > v) swap(u, v);
    if (opt == 0) del(u, v, mp[u][v]);
    else w = read(), add(u, v, w);
    print(query(), '\n');
  }
  return 0;
}