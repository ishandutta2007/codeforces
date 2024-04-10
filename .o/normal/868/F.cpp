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

const int N_ = 100500, K_ = 22;

int N, K, A[N_];

int freq[N_], freq_time[N_];
int TIME, fl, fr;
ll sum;
void add(int x) {
  /*if(freq_time[x] != TIME) {
    freq_time[x] = TIME;
    freq[x] = 0;
  }*/
  sum += freq[x]++;
}
void del(int x) {
  /*if(freq_time[x] != TIME) {
    freq_time[x] = TIME;
    freq[x] = 0;
  }*/
  sum -= --freq[x];
}
void move(int l, int r) {
  while(fl < l) del(A[++fl]);
  while(fr > r) del(A[fr--]);
  while(fl > l) add(A[fl--]);
  while(fr < r) add(A[++fr]);
}

ll tb[K_][N_];

void go (ll *prv, ll *cur, int l, int r, int x, int y) {
  int m = (l + r) >> 1;

  //TIME += 1;
  //sum = 0;
  //for(int i = x; i <= m; i++) add(A[i]);
  move(x, m);

  pli t(1e18, -1);
  for(int i = x; i <= y && i < m; i++) {
    move(i, m);
    t = min(t, make_pair(prv[i] + sum, i));
  }

  cur[m] = t.first;
  if(l < m) {
    go(prv, cur, l, m-1, x, t.second);
  }
  if(m < r) {
    go(prv, cur, m+1, r, t.second, y);
  }
}

int main() {
  scanf("%d%d", &N, &K);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }

  fill(tb[0]+1, tb[0]+N+1, ll(1e18));
  for(int k = 1; k <= K; k++) {
    go(tb[k-1], tb[k], 1, N, 0, N-1);
  }
  printf("%lld\n", tb[K][N]);
  return 0;
}