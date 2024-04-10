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

const int N_ = 200500;

int N, K;
vector<int> gph[N_];
int par[N_];
int sz[N_];
int level[N_];

void dfs (int u, int p = -1) {
  sz[u] = 1;
  for(int v : gph[u]) if(v != p) {
    level[v] = level[u] + 1;
    dfs(v, u);
    sz[u] += sz[v];
    par[v] = u;
  }
}

vector<ll> tot;

vector<ll> solve (int lca) {
  vector<ll> cur(K);

  vector<ll> ret(K);

  int h = level[lca] % K;
  ret[h] = 1;
  for(int v : gph[lca]) if(v != par[lca]) {
    vector<ll> ch = solve(v);
    for(int t = 0; t < K; t++) {
      for(int u = 0; u < K; u++) {
        cur[t] += ret[u] * ch[(t - u + K) % K];
      }
    }
    for(int t = 0; t < K; t++) {
      ret[t] += ch[t];
    }
  }

  //  


  for(int i = 0; i < K; i++)
    tot[(i - 2 * h + 2 * K) % K] += cur[i];
  return ret;
}


int main() {
  scanf("%d%d", &N, &K);
  for(int i = 1; i < N; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
  }

  dfs(1);

  ll ans = 0;

  for(int u = 2; u <= N; u++) {
    int p = par[u];
    ans += (ll)sz[u] * (N - sz[u]);
  }

  // sum ceil(d(u, v) / k) * k =
  // ceil(x / k) * k = x + (k == 0 ? 0 : k - x % k)

  // d(u, v) = level[u] + level[v] - level[lca(u, v)]
  // lca  ->   level % k   
  tot.resize(K);
  solve(1);

  for(int i = 1; i < K; i++)
    ans += tot[i] * (K - i);
  assert(ans % K == 0);
  ans /= K;
  printf("%lld\n", ans);
  return 0;
}