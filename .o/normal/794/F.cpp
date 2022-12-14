#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MOD = (int)1e9 + 7;

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }

  int operator* () { return v; }
};

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500;
const int A = 10;

int N, Q;
long long D[N_][A];

const int LEAF = 1<<17;
struct node {
  long long d[A];
  int t[A]; // lazy  .

  node() {
    for(int i = 0; i < A; i++) {
      t[i] = i;
    }
  }
};

node tree[LEAF + LEAF + 10];

void push (int x) {
  for(int y : {x*2, x*2+1}) {
    if(y < LEAF+LEAF) {
      for(int i = 0; i < A; i++) tree[y].t[i] = tree[x].t[tree[y].t[i]];
    }
  }
  vector<ll> tmp(A);
  for(int i = 0; i < A; i++) {
    tmp[tree[x].t[i]] += tree[x].d[i];
  }
  for(int i = 0; i < A; i++) {
    tree[x].t[i] = i;
    tree[x].d[i] = tmp[i];
  }
}

void merge (int x) {
  for(int i = 0; i < A; i++) {
    tree[x].d[i] = 0;
  }
  for(int y : {2*x, 2*x+1}) {
    for(int i = 0; i < A; i++) {
      tree[x].d[ tree[y].t[i] ] += tree[y].d[i];
    }
  }
}

void upd (int nd, int nl, int nr, int l, int r, int x, int y) {
  push(nd);

  if(nl == l && nr == r) {
    tree[nd].t[x] = y;
    return;
  }

  int nm = (nl + nr) >> 1;
  if(l <= nm) {
    upd(nd*2, nl, nm, l, min(nm, r), x, y);
  }
  if(r > nm) {
    upd(nd*2+1, nm+1, nr, max(nm+1, l), r, x, y);
  }

  merge(nd);
}

vector<ll> get (int nd, int nl, int nr, int l, int r) {
  vector<ll> ret(A);

  push(nd);

  if(nl == l && nr == r) {
    for(int i = 0; i < A; i++) ret[i] = tree[nd].d[i];
    return ret;
  }

  int nm = (nl + nr) >> 1;
  if(l <= nm) {
    vector<ll> r1 = get(nd*2, nl, nm, l, min(nm, r));
    for(int i = 0; i < A; i++)
      ret[i] += r1[i];
  }
  if(r > nm) {
    vector<ll> r2 = get(nd*2+1, nm+1, nr, max(nm+1, l), r);
    for(int i = 0; i < A; i++)
      ret[i] += r2[i];
  }

  return ret;
}

void init (int nd, int nl, int nr) {
  if(nl == nr) {
    for(int i = 0; i < A; i++) tree[nd].d[i] = D[nl][i];
    return;
  }
  int nm = (nl + nr) >> 1;
  init(nd*2, nl, nm);
  init(nd*2+1, nm+1, nr);
  merge(nd);
}

int main() {
  scanf("%d%d", &N, &Q);
  for(int i = 1; i <= N; i++) {
    int x; scanf("%d", &x);
    for(ll p = 1; x > 0; x /= 10, p *= 10) {
      D[i][x % 10] += p;
    }
  }

  init(1, 1, N);

  for(int q = 0; q < Q; q++) {
    int type; scanf("%d", &type);
    if(type == 1) {
      int l, r, x, y; scanf("%d%d%d%d", &l, &r, &x, &y);
      if(x == y) continue;

      upd(1, 1, N, l, r, x, y);
    }else {
      int l, r; scanf("%d%d", &l, &r);
      vector<ll> a = get(1, 1, N, l, r);
      ll ret = 0;
      for(int i = 1; i < A; i++) ret += i * a[i];

      printf("%lld\n", ret);

    }
  }

  return 0;
}