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

int N, M;
char tmp[1050], op[1050], tmp2[1050];
map<string, int> X;
bitset<1050> B[2][5050];

int main() {
  scanf("%d%d", &N, &M);
  B[1][0].set();
  for(int i = 1; i <= N; i++) {
    scanf("%s", tmp); X[tmp] = i;
    scanf("%*s");
    scanf("%s", tmp);
    if(tmp[0] == '0' || tmp[0] == '1') {
      for(int b = 0; b < M; b++) if(tmp[b] == '1') {
        B[0][i].set(b);
        B[1][i].set(b);
      }
    }else {
      scanf("%s%s", op, tmp2);
      int u = (tmp[0] == '?') ? 0 : X[tmp];
      int v = (tmp2[0] == '?') ? 0 : X[tmp2];
      for(int k = 0; k < 2; k++) {
        if(!strcmp(op, "AND")) {
          B[k][i] = B[k][u] & B[k][v];
        }else if(!strcmp(op, "OR")) {
          B[k][i] = B[k][u] | B[k][v];
        }else if(!strcmp(op, "XOR")) {
          B[k][i] = B[k][u] ^ B[k][v];
        }
      }
    }
  }

  string ans_min(M, '0');
  string ans_max(M, '0');
  for(int b = 0; b < M; b++) {
    int c[2] = {0, 0};
    for(int k = 0; k < 2; k++) {
      for(int i = 1; i <= N; i++) {
        c[k] += B[k][i][b];
      }
    }
    if(c[0] > c[1]) ans_min[b] = '1';
    else if(c[0] < c[1]) ans_max[b] = '1';
  }

  printf("%s\n%s\n", ans_min.c_str(), ans_max.c_str());
  return 0;
}