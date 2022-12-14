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

const int N_ = 10500;

int N;
int f[N_];
int par[N_];

int get(int u) {
  return (par[u] == u) ? u : (par[u] = get(par[u]));
}

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) par[i] = i;
  for(int i = 1; i <= N; i++) {
    scanf("%d", &f[i]);
    int u = get(i), v = get(f[i]);
    par[u] = v;
  }

  set<int> s;
  for(int i = 1; i <= N; i++) s.insert(get(i));
  printf("%lu\n", s.size());
  return 0;
}