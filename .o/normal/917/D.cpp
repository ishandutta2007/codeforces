// https://s3-ap-northeast-1.amazonaws.com/ojuz-attach/contest/kriii4/editorial.pdf
// :fan:

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


int N;

vector<int> gph[105];
int sz[105];

modint tb[105][105][105];
modint tmp[105][105];
// tb[u][e][m]: u ,  e ,  u   m

void go(int u, int p = -1) {
  sz[u] = 1;
  tb[u][0][1] = 1;

  for(int v : gph[u]) if(v != p) {
    go(v, u);
    for(int e1 = 0; e1 < sz[u]; e1++) {
      for(int e2 = 0; e2 < sz[v]; e2++) {
        for(int m1 = 1; m1 <= sz[u]; m1++) {
          for(int m2 = 1; m2 <= sz[v]; m2++) {
            tmp[e1 + e2][m1] += tb[u][e1][m1] * tb[v][e2][m2] * m2;
            tmp[e1 + e2 + 1][m1 + m2] += tb[u][e1][m1] * tb[v][e2][m2];
          }
        }
      }
    }

    sz[u] += sz[v];

    for(int e = 0; e <= sz[u]; e++) {
      for(int m = 1; m <= sz[u]; m++) {
        tb[u][e][m] = tmp[e][m];
        tmp[e][m] = 0;
      }
    }
  }
}

modint fac[105] = {1,};

modint comb (int n, int k) {
  return fac[n] / fac[k] / fac[n-k];
}

modint ans[105];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif

  scanf("%d", &N);
  for(int i = 0; i < N-1; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
  }

  for(int i = 1; i <= N; i++) {
    fac[i] = fac[i-1] * i;
  }

  go(1);

  modint invN = modint(1) / modint(N);
  modint coef = invN;
  for(int e = N-1; e >= 0; e--) {
    modint sum = 0;
    for(int m = 1; m <= N; m++) {
      sum += tb[1][e][m] * m;
    }
    ans[e] += coef * sum;
    for(int e2 = e-1; e2 >= 0; e2--) {
      ans[e2] -= ans[e] * comb(e, e2);
    }
    coef *= N;
  }

  for(int i = 0; i < N; i++) {
    printf("%d%c", *ans[i], (i+1 < N) ? ' ' : '\n');
  }

  return 0;
}