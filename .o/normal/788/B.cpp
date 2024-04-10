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

const int N_ = 1000500, lgN_ = 17, Q_ = 100500;

const int LEAF = 131072;

int N, M;

ll loops, deg[N_];

int grp[N_], num_components;

int get(int x) {
  if(grp[x] == x) return x;
  return grp[x] = get(grp[x]);
}

bool merge(int a, int b) {
  a = get(a); b = get(b);
  grp[a] = b;
  return a != b;
}

bool in[N_];

ll ans;

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++) grp[i] = i;
  num_components = N;

  for(int i = 1; i <= M; i++) {
    int u, v; scanf("%d%d", &u, &v);
    in[u] = in[v] = true;
    if(u == v) {
      loops += 1;
    }else {
      deg[u] += 1;
      deg[v] += 1;
      if(merge(u, v))
        num_components -= 1;
    }
  }

  set<int> s;
  for(int i = 1; i <= N && s.size() <= 1; i++)
    if(in[i]) s.insert(get(i));

  if(s.size() == 1) {
    for(int i = 1; i <= N; i++) {
      ans += deg[i] * (deg[i]-1) / 2;
    }
    ans += loops * (M - loops) + loops * (loops-1) / 2;
  }
  
  printf("%lld\n", ans);


  return 0;
}