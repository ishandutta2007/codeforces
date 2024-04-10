#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define TIME 1e3 * clock() / CLOCKS_PER_SEC
using ll = long long;
using uint = unsigned int;
using ld = long double;
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
constexpr int N = 1e5 + 5;
int n, R, mch[N];
ll k, sup, inf;
int dep[N], sz[N], mx[N], fa[N], f[N];
vector<int> e[N], pt[N];
vector<pii> ans;
struct dat {
  int u, v, w;
  bool operator < (const dat &x) const {return w < x.w;}
};
vector<dat> buc[N];
void findroot(int id, int ff, int tot) {
  sz[id] = 1;
  for(int it : e[id]) {
    if(it == ff) continue;
    findroot(it, id, tot), sz[id] += sz[it];
    mx[id] = max(mx[id], sz[it]);
  }
  mx[id] = max(mx[id], tot - sz[id]);
  if(mx[id] < mx[R]) R = id;
}
void init(int id, int ff, int anc) {
  fa[id] = ff, sz[id] = 1;
  sup += (dep[id] = dep[ff] + 1);
  f[id] = id;
  for(int it : e[id]) {
    if(it == ff) continue;
    init(it, id, anc), sz[id] += sz[it];
    if(f[it] && f[id]) buc[anc].push_back({f[id], f[it], dep[id]}), f[id] = 0;
    else if(f[it]) f[id] = f[it];
  }
  inf += sz[id] & 1;
}
void build(int id, int ff, int anc) {
  if(!mch[id]) pt[anc].push_back(id);
  for(int it : e[id]) {
    if(it == ff) continue;
    build(it, id, anc);
  }
}
bool Med;
int main() {
  fprintf(stderr, "%.3lf MB\n", (&Mbe - &Med) / 1048576.0);
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> k;
  for(int i = 1; i < n; i++) {
    int u = read(), v = read();
    e[u].push_back(v), e[v].push_back(u);
  }
  mx[0] = N, findroot(1, 0, n);
  set<pii> s;
  for(int it : e[R]) {
    init(it, R, it);
    s.insert({sz[it], it});
    sort(buc[it].begin(), buc[it].end());
  }
  if(k > sup || k - sup & 1 || k < inf) puts("NO"), exit(0);
  puts("YES");
  auto append = [&](int u, int v) {
    mch[u] = mch[v] = 1;
    ans.push_back({u, v});
  };
  k = sup - k;
  while(k > 0) {
    pii t = *--s.end();
    s.erase(--s.end());
    int id = t.second;
    dat dec = buc[id].back();
    buc[id].pop_back();
    if(k >= 2 * dec.w) {
      k -= 2 * dec.w;
      append(dec.u, dec.v);
      t.first -= 2, s.insert(t);
    }
    else {
      int ind = -1;
      if(dep[dec.u] == dec.w) ind = dec.u;
      else if(dep[dec.v] == dec.w) ind = dec.v;
      else ind = fa[dep[dec.u] < dep[dec.v] ? dec.u : dec.v]; // add check dep[dec.u] < dep[dec.v]
      while(dec.w * 2 > k) ind = fa[ind], dec.w--;
      k = 0, append(dec.u, ind);
    }
  }
  s.clear();
  pt[R].push_back(R), s.insert({1, R});
  for(int it : e[R]) {
    build(it, R, it);
    if(!pt[it].empty()) s.insert({pt[it].size(), it});
  }
  while(!s.empty()) {
    pii x = *--s.end(), y = *----s.end();
    s.erase(--s.end()), s.erase(--s.end());
    append(pt[x.second].back(), pt[y.second].back());
    pt[x.second].pop_back(), pt[y.second].pop_back();
    if(--x.first) s.insert(x);
    if(--y.first) s.insert(y);
  }
  for(pii it : ans) cout << it.first << " " << it.second << "\n";
  cerr << TIME << " ms\n";
  return 0;
}
/*
2022/10/12
author: Alex_Wei
start coding at 7:52
finish debugging at 13:57
*/