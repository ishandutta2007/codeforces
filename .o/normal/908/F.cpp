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

int N;
vector<ll> X, Y;
ll ans = 0;

int main() {
#ifdef IN_MY_COMPUTER
  freopen("f.in", "r", stdin);
#endif

  scanf("%d", &N);

  ll q = -ll(2e9);
  for(int i = 1; i <= N+1; i++) {
    ll p; char c[2]; 
    if(i <= N) {
      scanf("%lld%s", &p, c);
    }else {
      p = ll(2e9);
      *c = 'G';
    }
    if(*c != 'G') {
      (*c == 'B' ? X : Y).push_back(p);
    }else {
      // [q, p]
      if(i > N || q < -ll(1e9)) {
        if(!X.empty()) ans += (i > N ? X.back() : p) - (q < -ll(1e9) ? X.front() : q);
        if(!Y.empty()) ans += (i > N ? Y.back() : p) - (q < -ll(1e9) ? Y.front() : q);
      }else {
        auto go = [&q, &p](vector<ll> &pos) {
          ll ret = -ll(1e15);
          ll px = q;
          pos.push_back(p);
          for(ll x : pos) {
            ret = max(ret, x - px);
            px = x;
          }
          pos.pop_back();
          return ret;
        };
        ans += 3 * (p - q) - max(p - q, go(X) + go(Y));
      }
      
      q = p;
      X.clear(); Y.clear();
    }
  }

  printf("%lld\n", ans);
  return 0;
}