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
const int Q_ = 100500;

int N, M, Q;

vector<int> gph[N_];

int comp[N_];
vector<int> ver[N_];
int diam[N_];
int farthest[N_];
vector<int> roots;
vector<long long> fth[N_], sumfth[N_];

pii dfs0 (int u, int r) {
  pii ret = pii(-1, u);
  comp[u] = r;
  ver[r].push_back(u);
  for(int v : gph[u]) {
    if(!comp[v]) ret = max(ret, dfs0(v, r));
  }
  ret.first += 1;
  return ret;
}

pii dfs1 (int u, int p = -1) {
  pii ret = pii(-1, u);
  for(int v : gph[u]) {
    if(v != p) {
      ret = max(ret, dfs1(v, u));
    }
  }
  ret.first += 1;
  return ret;
}

void go (int u, int p = -1, int d = 0) {
  farthest[u] = max(farthest[u], d);
  for(int v : gph[u]) if(v != p) {
    go(v, u, d+1);
  }
}

map<pii, double> ans;

double solve (int u, int v) {
  if(ver[u].size() > ver[v].size()) swap(u, v);

  long long bj = 0, bm = 0;

  int d = max(diam[u], diam[v]);
  int j = (int)ver[v].size() - 1;
  for(ll f : fth[u]) {
    while(j >= 0 && fth[v][j] >= d - f - 1) j--;
    j += 1;
    bj += ll(d) * ll(j) + ll(f + 1) * ll(ver[v].size() - j) + sumfth[v][j];
  }

  bm = ll(ver[u].size()) * ll(ver[v].size());
  return (double)bj / bm;
}

int main() {
  scanf("%d%d%d", &N, &M, &Q);
  for(int i = 1; i <= M; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
  }

  for(int r = 1; r <= N; r++) if(!comp[r]) {
    roots.push_back(r);
    ver[r].clear();
    pii c1 = dfs0(r, r);
    pii c2 = dfs1(c1.second); // (dst, ver)
    for(auto p : {c1, c2}) {
      go(p.second);
    }
    for(int v : ver[r]) fth[r].push_back(farthest[v]);
    assert(ver[r].size() == fth[r].size());
    diam[r] = c2.first;
    sort(fth[r].begin(), fth[r].end());
    long long sf = accumulate(fth[r].begin(), fth[r].end(), 0ll);
    for(int f : fth[r]) {
      sumfth[r].push_back(sf);
      sf -= f;
    }
  }

  while(Q--) {
    int u, v; scanf("%d%d", &u, &v);
    u = comp[u]; v = comp[v];
    if(u > v) swap(u, v);
    double ret = -1;
    if(u < v) {
      auto it = ans.find(pii(u, v));
      if(it != ans.end()) {
        ret = it->second;
      }else {
        ans[pii(u, v)] = ret = solve(u, v);
      }
    }
    printf("%.20lf\n", ret);
  }
  return 0;
}