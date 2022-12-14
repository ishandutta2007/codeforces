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

const int N_ = 1050, K_ = 1000500;
const int MAXN = 1e5 + 5;

int N, K; bool D[N_];

const int M = 1000;

int tb_[M * 2 + 100];
bool visited_[M * 2 + 100];
int *tb = tb_ + M + 50;
bool *visited = visited_ + M + 50;

int main() {
  scanf("%d%d", &N, &K);
  fill(tb-M-1, tb+M+1, (int)1e9);
  for(int i = 1; i <= K; i++) {
    int v; scanf("%d", &v);
    tb[v-N] = 1;
  }


  // sum(x) / sum(1000) = n / 1000
  // sum(x) / count = n
  // sum(x) = n * count
  // sum(x - n) = 0

  int ans = -1;

  for(int rep = 0; rep <= 2*M; rep++) {
    int u = -(int)1e9;
    for(int i = -M; i <= M; i++) {
      if(!visited[i]) {
        if(u == -(int)1e9 || tb[u] > tb[i]) u = i;
      }
    }

    if(u == -(int)1e9) {
      ans = -1;
      break;
    }

    if(u == 0) {
      ans = tb[0];
      break;
    }

    visited[u] = true;
    for(int c = 0; c <= M; c++) if(tb[c - N] == 1) {
      int v = u + (c - N);
      if(-M <= v && v <= M)
        tb[v] = min(tb[v], tb[u] + 1);
    }
  }

  if(ans == (int)1e9)
    ans = -1;
  printf("%d\n", ans);

  return 0;
}