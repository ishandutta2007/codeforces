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

int N;
vector<int> gph[N_];
int deg[N_];

int conv (int l) {
  if(l <= 0) return l;
  while(~l & 1) l >>= 1;
  return l;
}

int T[N_];

void dfs (int u, int p = -1) {
  if(gph[u].size() == 1) {
    T[u] = 0;
    return;
  }

  vector<int> cands;
  for(auto v : gph[u]) if(v != p) {
    dfs(v, u);
    cands.push_back(T[v] + 1);
  }
  sort(cands.begin(), cands.end());
  cands.resize(unique(cands.begin(), cands.end()) - cands.begin());

  if(p == -1) {
    switch(cands.size()) {
      case 1:
        T[u] = *cands.begin();
        break;
      case 2:
        T[u] = *cands.begin() + *cands.rbegin();
        break;
      default:
        throw u;
    }
  }else {
    if(cands.size() >= 2) throw u;
    T[u] = *cands.begin();
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N-1; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
    deg[u] += 1;
    deg[v] += 1;
  }

  int root = max_element(deg+1, deg+N+1) - deg;
  if(deg[root] <= 2) {
    printf("%d\n", conv(N-1));
    return 0;
  }

  try {
    dfs(root);
    printf("%d\n", conv(T[root]));
  }
  catch (int u) {
    try {
      dfs(u);
      printf("%d\n", conv(T[u]));
    }
    catch (int v) {
      printf("-1\n");
      return 0;
    }
  }

  return 0;
}