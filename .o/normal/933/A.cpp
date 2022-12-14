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

int ans;

const int N_ = 2050;
int A[N_];
int pref[N_][2], suff[N_][2];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("a.in", "r", stdin);
#endif
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    int a; scanf("%d", &a); a -= 1;
    A[i] = a;
    pref[i][a] += 1;
    suff[i][a] += 1;
  }

  for(int i = 1; i <= N; i++) {
    pref[i][0] += pref[i-1][0];
    pref[i][1] += pref[i-1][1];
  }

  for(int i = N; i > 0; i--) {
    suff[i][0] += suff[i+1][0];
    suff[i][1] += suff[i+1][1];
  }

  for(int i = 1; i <= N; i++) {
    ans = max(ans, pref[i][0] + suff[i+1][1]);

    int cur = 0;
    for(int j = i; j <= N; j++) {
      if(A[j] == 0) cur += 1; else cur = max(cur, pref[j][1] - pref[i-1][1]);
      ans = max(ans, pref[i-1][0] + suff[j+1][1] + cur);
    }
  }

  printf("%d\n", ans);

  return 0;
}