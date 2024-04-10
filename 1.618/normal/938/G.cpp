/*
start thinking: 18:00
BULB: 18:15
result of thinking: Pure.

start coding: 14:00
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

#define maxn 200005
#define maxm 200005
#define maxq 200005

namespace Basis {
  int x[30], stkLen[maxm + maxq], kLen, kOpr;
  pair<int*, int> stkOpr[maxm + maxq];

  void ins(int y) {
    for (int i = 29; i >= 0; i--) {
      if (y >> i) {
        if (!x[i]) {
          stkLen[++kLen] = 1;
          stkOpr[++kOpr] = {x + i, 0};
          x[i] = y;
          return;
        }
        y ^= x[i];
      }
    }
    stkLen[++kLen] = 0;
  }

  void undo() {
    while (stkLen[kLen]--) {
      *stkOpr[kOpr].first = stkOpr[kOpr].second;
      kOpr--;
    }
    kLen--;
  }

  int minXor(int y) {
    for (int i = 29; i >= 0; i--) {
      if ((y >> i & 1) && x[i])
        y ^= x[i];
    }
    return y;
  }
}

int n;

namespace Dsu {
  int par[maxn], hei[maxn], stkLen[maxm + maxq], w[maxn], kLen, kOpr;
  pair<int*, int> stkOpr[(maxm + maxq) * 3];

  void ini(int n) {
    for (int i = 1; i <= n; i++)
      par[i] = i;
  }

  // (root, w to root)
  P fin(int u) {
    if (par[u] == u)
      return {u, 0};
    auto p = fin(par[u]);
    return {p.first, p.second ^ w[u]};
  }

  void uni(int u, int v, int d) {

    // cout << "Dsu::uni " << u << " " << v << " " << d << endl;
    // system("pause");

    auto pu = fin(u), pv = fin(v);
    u = pu.first, v = pv.first, d ^= pu.second ^ pv.second;
    if (u == v) {
      Basis::ins(d);
      stkLen[++kLen] = 1;
      stkOpr[++kOpr] = {NULL, 0};
      return;
    }
    if (hei[u] < hei[v]) {
      stkLen[++kLen] = 2;
      stkOpr[++kOpr] = {par + u, u};
      stkOpr[++kOpr] = {w + u, 0};
      par[u] = v;
      w[u] = d;
    } else if (hei[u] == hei[v]) {
      stkLen[++kLen] = 3;
      stkOpr[++kOpr] = {par + u, u};
      stkOpr[++kOpr] = {w + u, 0};
      stkOpr[++kOpr] = {hei + v, hei[v]};
      par[u] = v;
      w[u] = d;
      hei[v]++;
    } else {
      stkLen[++kLen] = 2;
      stkOpr[++kOpr] = {par + v, v};
      stkOpr[++kOpr] = {w + v, 0};
      par[v] = u;
      w[v] = d;
    }

    // cout << "par: ";
    // for (int i = 1; i <= n; i++) {
    //   cout << par[i] << " ";
    // }
    // cout << endl;
    // cout << "w: ";
    // for (int i = 1; i <= n; i++) {
    //   cout << w[i] << " ";
    // }
    // cout << endl;
    // cout << "hei: ";
    // for (int i = 1; i <= n; i++) {
    //   cout << hei[i] << " ";
    // }
    // cout << endl;
    // system("pause");
    
  }

  void undo() {

    // cout << "Dsu::undo" << endl;
    // system("pause");

    while (stkLen[kLen]--) {
      if (stkOpr[kOpr].first == NULL)
        Basis::undo();
      else
        *stkOpr[kOpr].first = stkOpr[kOpr].second;
      kOpr--;
    }
    kLen--;
  }
}

int m, q;
// Edge: ((u, v), d)
vector<pair<P, int>> dat[524295];
P qs[maxq];
// st[(u, v)]: (d, st_time)
map<P, P> st;

void add(int u, int l, int r, int ql, int qr, pair<P, int> x) {

  // if (u == 1) {
  //   cout << x.first.first << " " << x.first.second << " " << x.second << " "
  //        << ql << " " << qr << endl;
  //   system("pause");
  // }

  if (ql <= l && r <= qr) {
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

  // cout << "dfs " << u << " " << l << " " << r << endl;
  // system("pause");

  for (auto e : dat[u]) {
    Dsu::uni(e.first.first, e.first.second, e.second);
  }
  if (l == r) {
    if (qs[l].first) {
      printf("%d\n", 
        Basis::minXor(Dsu::fin(qs[l].first).second ^ Dsu::fin(qs[l].second).second));
    }
  } else {
    int mid = (l + r) >> 1;
    dfs(u << 1, l, mid);
    dfs(u << 1 | 1, mid + 1, r);
  }
  for (int i = 0; i < (int)dat[u].size(); i++)
    Dsu::undo();
  
  // cout << "dfs end " << u << " " << l << " " << r << endl;
  // system("pause");

}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    st[{u, v}] = {d, 0};
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int fl, u, v, d;
    scanf("%d", &fl);
    if (fl == 1) {
      scanf("%d%d%d", &u, &v, &d);
      st[{u, v}] = {d, i};
    } else if (fl == 2) {
      scanf("%d%d", &u, &v);
      add(1, 0, q, st[{u, v}].second, i - 1, {{u, v}, st[{u, v}].first});
      st.erase({u, v});
    } else {
      scanf("%d%d", &u, &v);
      qs[i] = {u, v};
    }
  }
  for (auto i : st) {
    add(1, 0, q, i.second.second, q, {{i.first.first, i.first.second}, 
      i.second.first});
  }

  // for (int i = 0; i <= q; i++) {
  //   cout << qs[i].first << " " << qs[i].second << endl;
  // }
  // system("pause");

  Dsu::ini(n);
  dfs(1, 0, q);
  return 0;
}