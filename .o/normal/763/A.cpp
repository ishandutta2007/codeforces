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

const int N_ = 200500;

int N;
pii E[N_];
int C[N_];
int deg[N_];

int main() {
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int u, v; scanf("%d%d", &u, &v);
    E[i] = pii(u, v);
  }
  for(int i = 1; i <= N; i++) {
    scanf("%d", &C[i]);
  }


  int tot = 0;
  for(int i = 1; i < N; i++) {
    int u, v;
    tie(u, v) = E[i];
    if(C[u] != C[v]) {
      deg[u] += 1;
      deg[v] += 1;
      tot += 1;
    }
  }

  for(int i = 1; i <= N; i++) {
    if(tot == deg[i]) {
      printf("YES\n%d\n", i);
      return 0;
    }
  }

  puts("NO");
  return 0;
}