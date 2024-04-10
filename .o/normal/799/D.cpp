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

int A, B, H, W, N;
int C[N_];

int ans = int(1e9);

void go() {
  int P = (A + H-1) / H;
  int Q = (B + W-1) / W;
  for(int t = 0; t <= N; t++) {
    bool good = false;
    vector<ll> sz;
    double pc = 1;
    sz.push_back(1ll);
    for(int i = 1; i <= t; i++) {
      int c = C[i];
      pc *= c;
      vector<ll> nsz = sz;
      for(ll z : sz) nsz.push_back(z * c);
      sort(nsz.begin(), nsz.end());
      nsz.resize(unique(nsz.begin(), nsz.end()) - nsz.begin());
      sz = nsz;
    }

    ll mz = sz.back();
    for(ll z : sz) {
      if(z >= P && mz/z >= Q) good = true;
    }
    if(pc > 2e15) { //  1e5  ?
      good = true;
    }

    if(good) {
      ans = min(ans, t);
      return;
    }
  }
}

int main() {
  scanf("%d%d%d%d%d", &A, &B, &H, &W, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &C[i]);
  }
  sort(C+1, C+N+1, greater<int>());

  go();
  swap(A, B);
  go();

  if(ans == (int)1e9) {
    ans = -1;
  }
  printf("%d\n", ans);
  return 0;
}