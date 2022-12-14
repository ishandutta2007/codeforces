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
#include <unordered_map>
#include <unordered_set>
 
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const ll MOD = (ll)1e9 + 7;

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
  modint operator/ (modint x) { return *this * x.inv(); }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }
  modint& operator/= (const modint x) { return *this = (*this / x); }

  int operator* () { return v; }

  modint inv() {
    modint ret = 1, cur = v;
    int p = MOD - 2;
    while(p > 0) {
      if(p & 1) ret = ret * cur;
      cur = cur * cur;
      p >>= 1;
    }
    return ret;
  }
};

int K, VA, VB;
modint PA, PB, invPB;

const int K_ = 1050;

modint tb[K_][K_];
bool chk[K_][K_];

modint get (int a, int k) {
  modint& ret = tb[a][k];
  if(!chk[a][k]) {
    chk[a][k] = true;
    ret = (k+a < K) ? PA * get(a+1, k) + PB * get(a, k+a)
                    : modint(a+k) + invPB - 1;
  }
  return ret;
}

int main() {
#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif
  scanf("%d%d%d", &K, &VA, &VB);

  PA = modint(VA) / modint(VA + VB);
  PB = modint(VB) / modint(VA + VB);
  invPB = modint(1) / PB;

  printf("%d\n", *get(1, 0));
  return 0;
}