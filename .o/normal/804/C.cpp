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

#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 300500;
const int M_ = 300500;

int N, M;
vector<int> ice[M_];
vector<int> gph[N_];
int ans[M_], ans0;
int chk[M_];

void solve(int u, int p = -1) {
  for(int t : ice[u]) chk[ans[t]] = u;
  int c = 1;
  for(int t : ice[u]) if(ans[t] == 0) {
    while(chk[c] == u) c += 1;
    ans[t] = c++;
    ans0 = max(ans0, ans[t]);
  }
  for(int v : gph[u]) {
    if(v != p) solve(v, u);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++) {
    int s; scanf("%d", &s);
    ice[i].resize(s);
    for(int j = 0; j < s; j++) {
      int t; scanf("%d", &t);
      ice[i][j] = t;
    }
  }

  for(int i = 1; i < N; i++) {
    int u, v; scanf("%d%d", &u, &v);
    gph[u].push_back(v);
    gph[v].push_back(u);
  }

  solve(1);

  if(ans0 == 0) ans0 = 1;
  printf("%d\n", ans0);
  for(int i = 1; i <= M; i++) {
    if(ans[i] == 0) ans[i] = 1;
    printf("%d ", ans[i]);
  }

  return 0;
}