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

const ll MOD = 998244353;

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

const int N_ = 2050;

int N, A, B;

modint pp[N_], pq[N_];

modint prob[N_][N_], inner[N_];

modint tb[N_];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("f.in", "r", stdin);
#endif
  scanf("%d%d%d", &N, &A, &B);

  modint P = modint(A) / modint(B);
  modint Q = modint(1) - P;

  pp[0] = pq[0] = 1;
  for(int i = 1; i <= N; i++) {
    pp[i] = pp[i-1] * P;
    pq[i] = pq[i-1] * Q;
  }

  for(int j = 0; j <= N; j++) {
    prob[0][j] = 1;
  }
  for(int i = 1; i <= N; i++) {
    prob[i][0] = prob[i-1][0];
    for(int j = 1; j <= N; j++) {
      prob[i][j] = prob[i][j-1] * pp[i] + prob[i-1][j] * pq[j];
    }
  }

  for(int i = 2; i <= N; i++) {
    tb[i] = i*(i-1)/2;
    for(int j = 1; j < i; j++) {
      modint p = prob[j][i-j] * (modint(1) - inner[j]);
      inner[i] += p;
      tb[i] += p * (tb[j] + tb[i-j] - ((i-j)*(i-j-1)/2));
    }
    tb[i] /= inner[i];
  }

  printf("%d\n", *tb[N]);
  return 0;
}