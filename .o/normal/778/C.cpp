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

const int N_ = 1000500;
const int C_ = 1050;

int N;

int children[N_][26];
int sz[N_];
int *rev[N_];

void merge (int b, int s, int &gen, int &ans) {
  for(int x = 0; x < 26; x++) {
    int &bv = children[b][x];
    int &sv = children[s][x];
    if(sv == 0) continue;
    if(bv == 0) rev[bv = ++gen] = &bv; else --ans;
    merge(bv, sv, gen, ans);
  }
}

int ans[N_];

void solve (int u, int d) {
  sz[u] = 1;
  for(int x = 0; x < 26; x++) {
    int v = children[u][x];
    if(v != 0) {
      solve(v, d+1);
      sz[u] += sz[v];
    }
  }

  int m = *max_element(children[u], children[u] + 26, [&](const int &v1, const int &v2) {
    return sz[v1] < sz[v2];
  });

  if(sz[m] == 0) return;

  int gen = N+5;
  ans[d] -= 1;
  for(int x = 0; x < 26; x++) {
    int v = children[u][x];
    if(v != 0 && v != m) {
      ans[d] -= 1;
      merge(m, v, gen, ans[d]);
    }
  }

  for(int i = N+6; i <= gen; i++) {
    *rev[i] = 0;
  }
}

int main() {
  scanf("%d", &N);
  for(int e = 0; e < N-1; e++) {
    int u, v; char x[2];
    scanf("%d%d%s", &u, &v, x);
    children[u][*x - 'a'] = v;
  }

  fill(ans+1, ans+N+1, N);
  solve(1, 1);

  int *p = min_element(ans+1, ans+N+1);
  printf("%d\n%ld\n", *p, p-ans);
  return 0;
}