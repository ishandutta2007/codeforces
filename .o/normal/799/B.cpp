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

const int N_ = 200500;

int N;
int P[N_],A[N_],B[N_];
vector<pii> prices[3];
int pos[3];
bool used[N_];

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &P[i]);
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]); A[i] -= 1;
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &B[i]); B[i] -= 1;
  }
  for(int i = 1; i <= N; i++) {
    int d[] = {0,0,0};
    d[A[i]] = 1;
    d[B[i]] = 1;
    for(int c = 0; c < 3; c++) if(d[c]) {
      prices[c].push_back(pii(P[i], i));
    }
  }

  for(int c=0;c<3;c++) {
    sort(prices[c].begin(), prices[c].end());
  }

  int M; scanf("%d", &M);
  while(M--) {
    int c; scanf("%d", &c);
    c -= 1;
    int ans = -1;
    while(pos[c] < prices[c].size()) {
      int p, i; tie(p, i) = prices[c][pos[c]++];
      if(!used[i]) {
        ans = p;
        used[i] = true;
        break;
      }
    }
    printf("%d ", ans);
  }
  return 0;
}