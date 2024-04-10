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

const int N_ = 200500;

int N; long long MAXT;
vector<int> rev[N_];
int A[N_], T[N_];

int go (int ans = -1) {
  priority_queue< pii > pq;

  int ret = 0;
  long long sumt = 0;
  for(int s = N; s > 0; s--) {
    for(int i : rev[s]) {
      pq.emplace(T[i], i);
      sumt += T[i];
    }
    while(pq.size() > s) {
      int i = pq.top().second; pq.pop();
      sumt -= T[i];
    }
    if(sumt <= MAXT) {
      ret = max(ret, (int)pq.size());
      if(pq.size() == ans) {
        printf("%d\n%d\n", ans, ans);
        while(!pq.empty()) {
          printf("%d ", pq.top().second);
          pq.pop();
        }
        exit(0);
      }
    }
  }
  return ret;
}
int main() {
#ifdef IN_MY_COMPUTER
  freopen("d.in", "r", stdin);
#endif
  scanf("%d%lld", &N, &MAXT);
  for(int i = 1; i <= N; i++) {
    int a, t; scanf("%d%d", &a, &t);
    rev[a].push_back(i);
    A[i] = a; T[i] = t;
  }

  int ans = go();
  if(ans == 0) {
    puts("0\n0");
    return 0;
  }
  go(ans);
  return 0;
}