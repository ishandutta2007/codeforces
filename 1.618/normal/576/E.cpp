/*
result of thinking: Lost.

(,)[+1,]
dfsdsu.


start coding: 21:00
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 500005
#define maxm 500005
#define maxq 500005
bool Mbe;

struct Dsu {
  int par[maxn], hei[maxn], stkOpr[maxn], k;
  bool w[maxn], stkLen[maxn];

  P fin(int u) {
    if (!par[u])
      return {u, 0};
    P ret = fin(par[u]);
    return {ret.first, ret.second ^ w[u]};
  }

  bool uni(int u, int v, int d = 1) {
    auto pu = fin(u), pv = fin(v);
    u = pu.first, v = pv.first;
    d ^= pu.second ^ pv.second;
    if (u == v) {
      stkOpr[++k] = 0;
      stkLen[k] = false;
      return !d;
    }
    if (hei[u] > hei[v])
      swap(u, v);
    stkOpr[++k] = u;
    stkLen[k] = false;
    par[u] = v;
    w[u] = d;
    if (hei[u] == hei[v])
      hei[v]++, stkLen[k] = true;
    return true;
  }

  void undo() {
    int u = stkOpr[k];
    if (stkLen[k])
      hei[par[u]]--;
    w[u] = 0, par[u] = 0;
    k--;
  }
} dsu[51];

// qs: (edge_id, col)
int n, m, k, q, a[maxm], b[maxm], pre[maxm], col[maxm];
P qs[maxq];
vector<int> dat[1048585];

void add(int u, int l, int r, int ql, int qr, int x) {
  if (ql > qr)
    return;
  if (ql <= l && r <= qr) {
    // push_backpush_back.
    dat[u].push_back(x);
    return;
  }
  int mid = (l + r) >> 1;
  if (ql <= mid)
    add(u << 1, l, mid, ql, qr, x);
  if (mid < qr)
    add(u << 1 | 1, mid + 1, r, ql, qr, x);
}

void dfs(int u, int l, int r) {
  for (auto i : dat[u]) {
    if (qs[i].second)
      dsu[qs[i].second].uni(a[qs[i].first], b[qs[i].first]);
  }
  if (l == r) {
    if (dsu[qs[l].second].uni(a[qs[l].first], b[qs[l].first])) {
      puts("YES");
      dsu[qs[l].second].undo();
      col[qs[l].first] = qs[l].second;
    } else {
      puts("NO");
      dsu[qs[l].second].undo();
      qs[l].second = col[qs[l].first];
    }
  } else {
    int mid = (l + r) >> 1;
    dfs(u << 1, l, mid);
    dfs(u << 1 | 1, mid + 1, r);
  }
  for (auto i : dat[u]) {
    if (qs[i].second)
      dsu[qs[i].second].undo();
  }
}

bool Med;
int main() {
  // printf("%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 1; i <= m; i++)
    scanf("%d%d", a + i, b + i);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qs[i].first, &qs[i].second);
    if (pre[qs[i].first])
      add(1, 1, q, pre[qs[i].first] + 1, i, pre[qs[i].first]);
    pre[qs[i].first] = i;
  }
  for (int i = 1; i <= m; i++) {
    if (pre[i])
      add(1, 1, q, pre[i] + 1, q, pre[i]);
  }
  dfs(1, 1, q);
  return 0;
}