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

const int N_ = 55, M_ = 1050;

int M, N;
char T[N_][M_];
char tmp[M_];

modint S[M_][M_], bell[M_];

int _grp[M_];
int grp(int x) {
  return x == _grp[x] ? x : (_grp[x] = grp(_grp[x]));
}

int main() {
#ifdef IN_MY_COMPUTER
  freopen("e.in", "r", stdin);
#endif
  scanf("%d%d", &M, &N);
  for(int i = 1; i <= N; i++) {
    scanf("%s", T[i]);
  }

  for(int b = 0; b < M; b++) {
    _grp[b] = b;
  }

  for(int p = 0; p < M; p++) {
    for(int q = p+1; q < M; q++) {
      bool good = true;
      for(int i = 1; i <= N; i++) {
        good &= (T[i][p] == T[i][q]);
      }
      if(good) {
        int x = grp(p), y = grp(q);
        _grp[x] = y;
      }
    }
  }

  map<int, int> freq;
  for(int b = 0; b < M; b++) {
    freq[grp(b)] += 1;
  }

  S[0][0] = 1;
  bell[0] = 1;
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= i; j++) {
      S[i][j] = S[i-1][j-1] + S[i-1][j] * j;
      bell[i] += S[i][j];
    }
  }

  modint ans = 1;
  for(auto it : freq) {
    ans *= bell[it.second];
  }

  printf("%d\n", *ans);


  return 0;
}