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
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 200500;

int MOD, N;
int A[N_];

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  modint inv() {
    modint ret = 1, p = v;
    int q = MOD - 2;
    while(q > 0) {
      if(q & 1) ret = ret * p;
      p = p * p;
      q >>= 1;
    }
    return ret;
  }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }
  modint operator/ (modint x) { return x.inv() * v; }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }
  modint& operator/= (const modint x) { return *this = (*this / x); }

  int& operator* () { return v; }

  bool operator< (const modint x) const { return v < x.v; }
};

typedef pair<modint, modint> pr;
pr get(vector<modint> a) {
  if(a.empty()) {
    return pr(0, 1);
  }
  if(a.size() == 1) {
    return pr(a[0], 1);
  }

  if(a.size() > MOD / 2) {
    vector<modint> b;
    for(int i = 0, j = 0; i < MOD; i++) {
      if(a[j] == i) {
        j++;
      }else {
        b.push_back(i);
      }
    }
    pr r = get(b);
    return pr(r.first - r.second, modint(0) - r.second);
  }

  modint rs;

  vector<modint> d;
  set<modint> sd;
  set<modint> sa;
  for(auto x : a) {
    modint y = x - a[0];
    d.push_back(y);
    sa.insert(x);
    sd.insert(y);
  }

  int r = 0;
  for(auto y : d) {
    modint z = y + d[1];
    if(sd.find(z) == sd.end()) r += 1;
  }
  rs = d[1] / r;

  vector<modint> cand;
  for(auto x : a) {
    modint p = x - rs;
    if(sa.find(p) == sa.end()) cand.push_back(x);
  }
  if(cand.size() == 1)
    return pr(cand[0], rs);
  else {
    puts("-1");
    exit(0);
  }
}

int main() {
  scanf("%d%d", &MOD, &N);

  vector<modint> a(N);
  for(auto &x : a) {
    int v; scanf("%d", &v);
    x = v;
  }
  sort(a.begin(), a.end());

  pr ret = get(a);
  printf("%d %d\n", *ret.first, *ret.second);

  return 0;
}