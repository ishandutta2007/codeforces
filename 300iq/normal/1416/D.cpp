#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>

using namespace std;

typedef long long ll;

#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const int N = 2e5 + 7;

int dsu[N];
vector <int> st[N];

int get(int v) {
  if (v == dsu[v]) {
    return v;
  } else {
    return dsu[v] = get(dsu[v]);
  }
}

void uni(int u, int v) {
  u = get(u), v = get(v);
  if (st[u].size() > st[v].size()) {
    swap(u, v);
  }
  for (int x : st[u]) {
    st[v].push_back(x);
  }
  dsu[u] = v;
}


pair <int, int> t[4 *N ];

void build(int v, int l, int r, vector <int> &p) {
  if (r - l == 1) {
    t[v] = make_pair(p[l], l);
  } else {
    int m = (l + r) / 2;
    build(v * 2 + 1, l, m, p);
    build(v * 2 + 2, m, r, p);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

void upd(int v, int l, int r, int i) {
  if (r - l == 1) {
    t[v] = make_pair(0, i);
  } else {
    int m = (l + r) / 2;
    if (i < m) upd(v * 2 + 1, l, m, i);
    else upd(v * 2 + 2, m, r, i);
    t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
  }
}

pair <int, int> get(int v, int l, int r, int tl, int tr) {
  if (tl >= r || tr <= l) {
    return make_pair(-1, 0);
  }
  if (tl >= l && tr <= r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    return max(get(v * 2 + 1, l, r, tl, tm), get(v * 2 + 2, l, r, tm, tr));
  }
}

int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector <int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    dsu[i] = i;
    st[i].push_back(i);
  }
  vector <pair <int, int> > e;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    e.push_back({a, b});
  }
  vector <pair <int, int> > qs(q);
  vector <int> when(m, q);
  vector <int> f;
  for (int i = 0; i < q; i++) {
    cin >> qs[i].first >> qs[i].second;
    if (qs[i].first == 2) {
      when[qs[i].second - 1] = i;
    } else {
      f.push_back(i);
    }
  }
  vector <int> l(q), r(q);
  reverse(f.begin(), f.end());
  vector <int> ord;
  for (int i = 0; i < m; i++) ord.push_back(i);
  sort(ord.begin(), ord.end(), [&] (int a, int b) {
    return when[a] > when[b];
  });
  int ptr = -1;
  for (int i : ord) {
    while (ptr + 1 < (int) f.size() && f[ptr + 1] > when[i]) {
      ptr++;
      int when = f[ptr];
      int ok = get(qs[when].second - 1);
      l[when] = st[ok][0], r[when] = st[ok].back();
    }
    int u = e[i].first, v = e[i].second;
    if (get(u) != get(v)) {
      uni(u, v);
    }
  }
  int root = get(0);
  while (ptr + 1 < (int) f.size()) {
    ptr++;
    int when = f[ptr];
    int root = get(qs[when].second - 1);
    l[when] = st[root][0], r[when] = st[root].back();
  }
  vector <int> od;
  for (int i = 0; i < n; i++) {
    if (dsu[i] == i) {
      for (int x : st[i]) {
        od.push_back(x);
      }
    }
  }
  vector <int> pos(n);
  vector <int> ok;
  for (int i = 0; i < n; i++) {
    pos[od[i]] = i;
    ok.push_back(p[od[i]]);
  }
  build(0, 0, n, ok);
  reverse(f.begin(), f.end());
  for (int i : f) {
    int a = pos[l[i]], b = pos[r[i]];
    auto p = get(0, a, b + 1, 0, n);
    cout << p.first << '\n';
    upd(0, 0, n, p.second);
  }
}