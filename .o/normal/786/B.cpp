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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 100500, lgN_ = 17, Q_ = 100500;

const int LEAF = 131072;

int N, Q, S;

vector<pii> gph_[LEAF * 2 * 2 + 10];

vector<pii> *gph = gph_ + LEAF * 2 + 5;

long long ans_[LEAF * 4 + 10];
long long *ans = ans_ + LEAF * 2 + 5;

int main() {
  scanf("%d%d%d", &N, &Q, &S);
  for(int i = 1; i < LEAF+LEAF; i++) {
    if(i >= LEAF) {
      gph[i].push_back(pii(-i, 0));
      gph[-i].push_back(pii(i, 0));
    }
    if(i > 1) {
      gph[-i].push_back(pii(-(i / 2), 0));
      gph[i / 2].push_back(pii(i, 0));
    }
  }

  for(int q = 1; q <= Q; q++) {
    int t; scanf("%d", &t);
    int l, r, v, w;
    if(t == 1) {
      scanf("%d%d%d", &v, &l, &w);
      r = l;
    }else {
      scanf("%d%d%d%d", &v, &l, &r, &w);
    }

    int sgn = (t <= 2) ? 1 : -1;
    auto add = [&v, &w, &t, &sgn](int x) {

      if(t <= 2)
        gph[(v + LEAF) * sgn].push_back(pii(x * sgn, w));
      else
        gph[x * sgn].push_back(pii((v + LEAF) * sgn, w));
    };

    l += LEAF; r += LEAF;
    while(l <= r) {
      if(l & 1) {
        add(l);
      }
      if(~r & 1) {
        add(r);
      }
      l = (l + 1) >> 1;
      r = (r - 1) >> 1;
    }
  }

  fill(ans-LEAF*2, ans+LEAF*2+1, (ll)1e18);

  priority_queue<pli, vector<pli>, greater<pli> > pq;
  pq.push(pii(0, S + LEAF));
  ans[S + LEAF] = 0;

  while(!pq.empty()) {
    int u; long long c;
    tie(c, u) = pq.top(); pq.pop();
    if(c > ans[u]) continue;
    for(pii e : gph[u]) {
      if(c + e.second < ans[e.first]) {
        ans[e.first] = c + e.second;
        pq.push(pli(ans[e.first], e.first));
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    printf("%lld ", ans[i + LEAF] == (ll)1e18 ? -1 : ans[i + LEAF]);
  }

  return 0;
}