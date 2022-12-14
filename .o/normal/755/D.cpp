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
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = (int)1e6 + 5;

int N, K;

int nxt (int x) {
  x += K;
  if(x > N) x -= N;
  return x;
}

int tree[N_];

void upd (int x, int v) {
  for(; x <= N; x += x & -x) tree[x] += v;
}

int get (int x) {
  int ret = 0;
  if(x > N) {
    for(int y = N; y > 0; y -= y & -y) ret += tree[y];
    x -= N;
  }
  for(; x > 0; x -= x & -x) ret += tree[x];
  return ret;
}

int main() {
  scanf("%d%d", &N, &K);
  K = min(K, N-K);
  int cur = 1, prv = (N-K+1);
  ll ans = 1;
  for(int step = 1; step <= N; step++) {
    ans += get(cur+K-1) - get(cur);
    ans += get(prv+K-1) - get(prv);
    ans += 1;
    printf("%lld ", ans);
    upd(cur, +1);
    prv = cur;
    cur = nxt(cur);
  }
  return 0;
}