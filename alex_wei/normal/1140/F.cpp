#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
// using lll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
inline ll read() {
  ll x = 0, sgn = 0;
  char s = getchar();
  while(!isdigit(s)) sgn |= s == '-', s = getchar();
  while(isdigit(s)) x = x * 10 + s - '0', s = getchar();
  return sgn ? -x : x;
}
inline void print(ll x) {
  if(x < 0) return putchar('-'), print(-x);
  if(x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
bool Mbe;
constexpr int V = 3e5;
constexpr int N = 6e5 + 5;
ll ans;
int q, fa[N], a[N], b[N];
int find(int x) {return fa[x] == x ? x : find(fa[x]);}
map<pii, int> mp;
vector<pii> val[N << 1];
void modify(int l, int r, int ql, int qr, int x, pii v) {
  if(ql <= l && r <= qr) return val[x].push_back(v), void();
  int m = l + r >> 1;
  if(ql <= m) modify(l, m, ql, qr, x << 1, v);
  if(m < qr) modify(m + 1, r, ql, qr, x << 1 | 1, v);
}
void query(int l, int r, int x) {
  vector<int> upd;
  for(pii it : val[x]) {
    int u = find(it.first), v = find(it.second);
    if(u == v) continue;
    ans -= 1ll * a[u] * b[u] + 1ll * a[v] * b[v];
    if(a[u] + b[u] < a[v] + b[v]) swap(u, v);
    fa[v] = u, a[u] += a[v], b[u] += b[v], upd.push_back(v);
    ans += 1ll * a[u] * b[u];
  }
  int m = l + r >> 1;
  if(l == r) print(ans), putchar(' ');
  else {
    int m = l + r >> 1;
    query(l, m, x << 1), query(m + 1, r, x << 1 | 1);
  }
  reverse(upd.begin(), upd.end());
  for(int it : upd) {
    int f = fa[it];
    ans -= 1ll * a[f] * b[f];
    fa[it] = it, a[f] -= a[it], b[f] -= b[it];
    ans += 1ll * a[f] * b[f] + 1ll * a[it] * b[it];
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> q;
  for(int i = 1; i <= V; i++) fa[i] = i, a[i] = 1;
  for(int i = V + 1; i <= V + V; i++) fa[i] = i, b[i] = 1;
  for(int i = 1; i <= q; i++) {
    int x = read(), y = read() + V;
    auto pt = mp.find({x, y});
    if(pt == mp.end()) mp[{x, y}] = i;
    else modify(1, q, pt->se, i - 1, 1, {x, y}), mp.erase(pt);
  }
  for(auto it : mp) modify(1, q, it.se, q, 1, it.fi);
  query(1, q, 1);
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/2
author: Alex_Wei
start coding at 9:24
finish debugging at 9:33
*/