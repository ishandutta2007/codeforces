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

const int N_ = 100;

int N;
char S[N_];

int tb[N_][N_][N_];
int D[N_];
int C[N_], CP[3][N_];

int main() {
  scanf("%d%s", &N, S);
  for(int i = 0; i <= N; i++) {
    D[i] = (S[i] == 'V') ? 0 : (S[i] == 'K') ? 1 : 2;
  }
  for(int k = 0; k < 3; k++) {
    C[k] = count(D, D+N+1, k);
    CP[k][0] = (D[0] == k);
    for(int i = 1; i <= N; i++)
      CP[k][i] = CP[k][i-1] + (D[i] == k);
//    printf("%d ",C[k]);
  }

  for(int i = 0; i <= C[0]; i++) {
    for(int j = 0; j <= C[1]; j++) {
      for(int k = 0; k <= C[2]; k++) tb[i][j][k] = (int)1e9;
    }
  }

  tb[0][0][0] = 0;
  for(int i = 0; i <= C[0]; i++) {
    for(int j = 0; j <= C[1]; j++) {
      for(int k = 1; k <= C[2]; k++) {
        for(int pi = 0; pi <= i; pi++) for(int pj = 0; pj <= j; pj++) {
          int v = tb[pi][pj][k-1];
          int g[3] = {0, 0, 0};
          int p[] = {pi, pj, k-1}, now[] = {i, j, k}, f = 0;
          for(int x = 0; x <= N; x++) {
            int s = CP[D[x]][x];
            if(s <= p[D[x]]) v += f;
            else if(s <= now[D[x]]) {
              f += 1; g[D[x]] += 1;
              v += g[0] * (D[x] == 1);
              v += g[2] * (D[x] == 0 || D[x] == 1);
            }
          }
          tb[i][j][k] = min(tb[i][j][k], v);
        }
      }
    }
  }

  int ans = tb[C[0]][C[1]][C[2]];
  printf("%d\n", ans);
  return 0;
}