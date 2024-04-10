/*
start thinking:
BULB:
result of thinking: Lost.

 trie, ( [l, r], ...)
, .
 XOR , tag[u]  u  XOR , down 
tag[u] .
 O(polylog)  OR,  all0/1[u]  u 
 0/1,  u .  OR x ,  x  1
,  n log^2 n.
,  extract  Trie  O(log n) 
O(log^2 n) .

start coding: 13:00
AC: 16:22 nxtd

, .
 extract  [l, r] ,  sgt .
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
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

// Trie  hei >= 0 .
struct Node {
  int chi[2], tag, siz, all0, all1;
  void ini() {
    chi[0] = chi[1] = tag = siz = all0 = all1 = 0;
  }
} a[4000005]; int root;
queue<int> V;

int newNode() {
  int ret = V.front();
  V.pop();
  a[ret].ini();
  return ret;
}

void up(int u, int hei) {
  int lc = a[u].chi[0], rc = a[u].chi[1];
  auto _lc = a[lc], _rc = a[rc];
  a[u].siz = _lc.siz + _rc.siz;

  auto foo = (_lc.all0 | _lc.all1) & _lc.tag;
  _lc.all0 ^= foo, _lc.all1 ^= foo;
  foo = (_rc.all0 | _rc.all1) & _rc.tag;
  _rc.all0 ^= foo, _rc.all1 ^= foo;

  a[u].all0 = _lc.all0 & _rc.all0;
  if (!rc)
    a[u].all0 |= 1 << hei;
  a[u].all1 = _lc.all1 & _rc.all1;
  if (!lc)
    a[u].all1 |= 1 << hei;
}

void down(int u, int hei) {
  int &lc = a[u].chi[0], &rc = a[u].chi[1];
  auto foo = (a[u].all0 | a[u].all1) & a[u].tag;
  a[u].all0 ^= foo, a[u].all1 ^= foo;
  if (a[u].tag >> hei & 1)
    swap(lc, rc);
  a[u].tag &= ~(1 << hei);
  if (lc)
    a[lc].tag ^= a[u].tag;
  if (rc)
    a[rc].tag ^= a[u].tag;
  a[u].tag = 0;
}

int join(int u, int v, int hei) {
  if (!u || !v)
    return u ^ v;
  if (u == v)
    return u;
  if (hei == -1) {
    a[u].siz = 1;
    V.push(v);
    return u;
  }
  down(u, hei), down(v, hei);
  a[u].chi[0] = join(a[u].chi[0], a[v].chi[0], hei - 1);
  a[u].chi[1] = join(a[u].chi[1], a[v].chi[1], hei - 1);
  up(u, hei);
  V.push(v);
  return u;
}

int ins(int u, int hei, int x, int v, int vhei) {
  if (hei == vhei)
    return join(u, v, hei);
  if (!u)
    u = newNode();
  down(u, hei);
  a[u].chi[x >> hei & 1] = ins(a[u].chi[x >> hei & 1], hei - 1, x, v, vhei);
  up(u, hei);
  return u;
}

int extract(int u, int l, int r, int hei, int ql, int qr, int path,
      vector<tuple<int, int, int>> &res) {
  if (ql <= l && r <= qr) {
    res.push_back({u, hei, path});
    return 0;
  }
  down(u, hei);
  int mid = (l + r) >> 1;
  if (ql <= mid && a[u].chi[0])
    a[u].chi[0] = extract(a[u].chi[0], l, mid, hei - 1, ql, qr, path, res);
  if (mid < qr && a[u].chi[1])
    a[u].chi[1] = extract(a[u].chi[1], mid + 1, r, hei - 1, ql, qr,
                          path | (1 << hei), res);
  if (a[u].chi[0] || a[u].chi[1]) {
    up(u, hei);
    return u;
  } else {
    V.push(u);
    return 0;
  }
}

void OR(int u, int hei, int x) {
  if (hei == -1 || !x)
    return;
  down(u, hei);
  if (x == ((a[u].all0 | a[u].all1) & x)) {
    a[u].tag ^= x & a[u].all0;
    return;
  }
  if (x >> hei & 1) {
    a[u].chi[1] = join(a[u].chi[1], a[u].chi[0], hei - 1);
    a[u].chi[0] = 0;
  }
  if (a[u].chi[0])
    OR(a[u].chi[0], hei - 1, x & ~(1 << hei));
  if (a[u].chi[1])
    OR(a[u].chi[1], hei - 1, x & ~(1 << hei));
  up(u, hei);
}

void getxor(int l, int r, int x) {
  vector<tuple<int, int, int>> foo;
  root = extract(root, 0, 1048575, 19, l, r, 0, foo);
  for (auto i : foo) {
    int u = get<0>(i), hei = get<1>(i), path = get<2>(i);
    a[u].tag ^= x & ((1 << (hei + 1)) - 1);
    root = ins(root, 19, path ^ (x & ~((1 << (hei + 1)) - 1)), u, hei);
  }
}

void getor(int l, int r, int x) {
  vector<tuple<int, int, int>> foo;
  root = extract(root, 0, 1048575, 19, l, r, 0, foo);
  for (auto i : foo) {
    int u = get<0>(i), hei = get<1>(i), path = get<2>(i);
    OR(u, hei, x & ((1 << (hei + 1)) - 1));
    root = ins(root, 19, path | (x & ~((1 << (hei + 1)) - 1)), u, hei);
  }
}

void getand(int l, int r, int x) {
  getxor(0, 1048575, 1048575);
  getor(r ^ 1048575, l ^ 1048575, x ^ 1048575);
  getxor(0, 1048575, 1048575);
}

int query(int l, int r) {
  vector<tuple<int, int, int>> foo;
  root = extract(root, 0, 1048575, 19, l, r, 0, foo);
  int ans = 0;
  for (auto i : foo) {
    int u = get<0>(i), hei = get<1>(i), path = get<2>(i);
    ans += a[u].siz;
    root = ins(root, 19, path, u, hei);
  }
  return ans;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  for (int i = 1; i <= 4000000; i++)
    V.push(i);
  a[0].all0 = a[0].all1 = 1048575;
  int n, q;
  scanf("%d%d", &n, &q);
  while (n--) {
    int x;
    scanf("%d", &x);
    int u = newNode();
    a[u].siz = 1;
    root = ins(root, 19, x, u, -1);
  }
  while (q--) {
    int fl, l, r, x;
    scanf("%d", &fl);
    if (fl <= 3) {
      scanf("%d%d%d", &l, &r, &x);
      if (fl == 1)
        getand(l, r, x);
      else if (fl == 2)
        getor(l, r, x);
      else
        getxor(l, r, x);
    } else {
      scanf("%d%d", &l, &r);
      printf("%d\n", query(l, r));
    }
  }
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}