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

int N, K, M;

const int N_ = 85;
int tb[N_][N_][N_][N_];
bool visited[N_][N_][N_][N_];
vector<pii> gph[N_];

int solve (int k, int u, int l, int r) {
  int &val = tb[k][u][l][r];
  if(visited[k][u][l][r]) return val;
  if(k == 0) return 0;
  visited[k][u][l][r] = true;
  val = (int)2e9;
  for(pii e : gph[u]) {
    int v, c; tie(v, c) = e;
    int cand = (int)1e9;
    if(u < v && v <= r) {
      cand = min(solve(k-1, v, u+1, v), solve(k-1, v, v, r));
    }else if(l <= v && v < u) {
      cand = min(solve(k-1, v, l, v), solve(k-1, v, v, u-1));
    }
    val = min(val, cand + c);
  }
  return val;
}
int main() {
  scanf("%d%d%d", &N, &K, &M);
  for(int i = 1; i <= M; i++) {
    int u, v, c; scanf("%d%d%d", &u, &v, &c);
    gph[u].push_back(pii(v, c));
  }

  int ans = (int)1e9;
/*  for(int k = 1; k < K; k++) {
    for(int u = 1; u <= N; u++) {
      for(int l = 1; l <= N; l++) {
        for(int r = l; r <= N; r++) {
          int &val = tb[k][u][l][r];
          val = (int)2e9;
          for(pii e : gph[u]) {
            int v, c; tie(v, c) = e;
            int cand = (int)1e9;
            if(u < v && v <= r) {
              cand = min(tb[k-1][v][u+1][v], tb[k-1][v][v][r]);
            }else if(l <= v && v < u) {
              cand = min(tb[k-1][v][l][v], tb[k-1][v][v][u-1]);
            }
            val = min(val, cand + c);
          }
        }
      }
    }
  }*/

  for(int u = 1; u <= N; u++) {
    int cand = min(solve(K-1, u, 1, u), solve(K-1, u, u, N)); //min(tb[K-1][u][1][u], tb[K-1][u][u][N]);
    ans = min(ans, cand);
  }

  if(ans < (int)1e9)
    printf("%d\n", ans);
  else
    puts("-1");

  return 0;
}