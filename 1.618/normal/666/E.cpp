/*
result of thinking: Pure.

CF666E
prT1~TmSAMSAM0-
parent tree.
pr

start coding: 12:00
AC: 17:15
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
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

namespace Sgt {
  int lc[850005], rc[850005], maxi[850005], argmax[850005], V;

  void up(int u) {
    if (maxi[lc[u]] >= maxi[rc[u]])
      maxi[u] = maxi[lc[u]], argmax[u] = argmax[lc[u]];
    else
      maxi[u] = maxi[rc[u]], argmax[u] = argmax[rc[u]];
  }

  void ins(int &u, int l, int r, int pos) {
    if (!u)
      u = ++V;
    if (l == r) {
      maxi[u]++;
      argmax[u] = l;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
      ins(lc[u], l, mid, pos);
    else
      ins(rc[u], mid + 1, r, pos);
    up(u);
  }

  int merge(int x, int y, int l, int r) {
    if (!x || !y)
      return x ^ y;
    if (l == r) {
      maxi[x] += maxi[y];
    } else {
      int mid = (l + r) >> 1;
      lc[x] = merge(lc[x], lc[y], l, mid);
      rc[x] = merge(rc[x], rc[y], mid + 1, r);
      up(x);
    }
    return x;
  }

  // (max, -argmax)
  P query(int u, int l, int r, int ql, int qr) {
    if (!u)
      return {0, -max(ql, l)};
    if (ql <= l && r <= qr)
      return {maxi[u], -argmax[u]};
    int mid = (l + r) >> 1;
    P res = {-1, -1};
    if (ql <= mid)
      chmax(res, query(lc[u], l, mid, ql, qr));
    if (mid < qr)
      chmax(res, query(rc[u], mid + 1, r, ql, qr));
    return res;
  }
}

#define maxn 500005
#define maxV 100010
#define maxq 500005
int n, m, q;
char s[maxn], t[50005];
int root[maxV], len[maxV], par[16][maxV], nxt[maxV][26], lst, V;

void extend(int c) {
  if (nxt[lst][c] && len[lst] + 1 == len[nxt[lst][c]]) {
    lst = nxt[lst][c];
    return;
  }
  int cur = ++V, p = lst;
  len[cur] = len[lst] + 1;
  while (~p && !nxt[p][c]) {
    nxt[p][c] = cur;
    p = par[0][p];
  }
  if (p == -1) {
    par[0][cur] = 0;
  } else {
    int q = nxt[p][c];
    if (p == lst) {
      par[0][cur] = par[0][q];
      memcpy(nxt[cur], nxt[q], sizeof(nxt[q]));
      while (~p && nxt[p][c] == q) {
        nxt[p][c] = cur;
        p = par[0][p];
      }
      par[0][q] = cur;
    } else if (len[p] + 1 == len[q]) {
      par[0][cur] = q;
    } else {
      int foo = ++V;
      par[0][foo] = par[0][q];
      memcpy(nxt[foo], nxt[q], sizeof(nxt[q]));
      len[foo] = len[p] + 1;
      while (~p && nxt[p][c] == q) {
        nxt[p][c] = foo;
        p = par[0][p];
      }
      par[0][q] = par[0][cur] = foo;
    }
  }
  lst = cur;
}

struct Query {
  int l, r, pl, pr, id;
  bool operator < (const Query &b) const {
    return pr < b.pr;
  }
} qs[maxq];
vector<int> tbd[maxV];
P ans[maxq];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%s", s + 1);
  n = strlen(s + 1);
  scanf("%d", &m);
  par[0][0] = -1;
  for (int i = 1; i <= m; i++) {
    lst = 0;
    scanf("%s", t + 1);
    int tl = strlen(t + 1);
    for (int j = 1; j <= tl; j++) {
      extend(t[j] - 'a');
      Sgt::ins(root[lst], 1, m, i);
    }
  }
  par[0][0] = 0;
  for (int i = 1; i <= 15; i++) {
    for (int u = 0; u <= V; u++) {
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &qs[i].l, &qs[i].r, &qs[i].pl, &qs[i].pr);
    qs[i].id = i;
  }
  sort(qs + 1, qs + q + 1);
  for (int i = 1, u = 0, l = 0; i <= q; i++) {
    for (int j = qs[i - 1].pr + 1; j <= qs[i].pr; j++) {
      while (u && !nxt[u][s[j] - 'a'])
        u = par[0][u], l = len[u];
      if (nxt[u][s[j] - 'a'])
        l++;
      u = nxt[u][s[j] - 'a'];
    }
    if (l <= qs[i].pr - qs[i].pl)
      ans[qs[i].id] = {0, -qs[i].l};
    else {
      int foo = u;
      for (int j = 15; j >= 0; j--) {
        if (len[par[j][foo]] >= qs[i].pr - qs[i].pl + 1)
          foo = par[j][foo];
      }
      tbd[foo].push_back(i);
    }
  }
  static int topo[maxV];
  for (int i = 1; i <= V; i++)
    topo[i] = i;
  sort(topo + 1, topo + V + 1, [](int x, int y) { return len[x] > len[y]; });
  for (int i = 1; i <= V; i++) {
    int u = topo[i];
    for (auto j : tbd[u]) {
      ans[qs[j].id] = Sgt::query(root[u], 1, m, qs[j].l, qs[j].r);
    }
    root[par[0][u]] = Sgt::merge(root[par[0][u]], root[u], 1, m);
  }
  for (int i = 1; i <= q; i++) {
    printf("%d %d\n", -ans[i].second, ans[i].first);
  }
  return 0;
}