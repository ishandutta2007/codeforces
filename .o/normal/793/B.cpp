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

int N, M;
char D[1050][1050];
int si, sj, ei, ej;

int T[1050][1050];
int U[1050][1050][4];

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++) {
    scanf("%s", D[i]+1);
    for(int j = 1; j <= M; j++) {
      if(D[i][j] == 'S') si = i, sj = j;
      if(D[i][j] == 'T') ei = i, ej = j;

    }
  }

  {
    T[si][sj] |= 1;
    for(int i = si+1; i <= N && D[i][sj] != '*'; i++)
      T[i][sj] |= 1;
    for(int i = si-1; i >= 1&& D[i][sj] != '*'; i--)
      T[i][sj] |= 1;
    for(int j = sj+1; j <= M && D[si][j] != '*'; j++)
      T[si][j] |= 1;
    for(int j = sj-1; j >= 1 && D[si][j] != '*'; j--)
      T[si][j] |= 1;
  }

  {
    T[ei][ej] |= 2;
    for(int i = ei+1; i <= N && D[i][ej] != '*'; i++)
      T[i][ej] |= 2;
    for(int i = ei-1; i >= 1&& D[i][ej] != '*'; i--)
      T[i][ej] |= 2;
    for(int j = ej+1; j <= M && D[ei][j] != '*'; j++)
      T[ei][j] |= 2;
    for(int j = ej-1; j >= 1 && D[ei][j] != '*'; j--)
      T[ei][j] |= 2;
  }

  for(int j = 1; j <= M; j++) {
    for(int i = 1; i <= N; i++) {
      U[i][j][0] = (D[i][j] == '*') ? 0 : (U[i-1][j][0] | T[i][j]);
    }
    for(int i = N; i >= 1; i--) {
      U[i][j][1] = (D[i][j] == '*') ? 0 : (U[i+1][j][1] | T[i][j]);
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      U[i][j][2] = (D[i][j] == '*') ? 0 : (U[i][j-1][2] | T[i][j]);
    }
    for(int j = M; j >= 1; j--) {
      U[i][j][3] = (D[i][j] == '*') ? 0 : (U[i][j+1][3] | T[i][j]);
    }
  }
  
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      int dx[] = {-1, 1, 0, 0};
      int dy[] = {0, 0, -1, 1};
      for(int d = 0; d < 4; d++) {
        int ck = T[i][j] | U[i][j][d];
        /*for(int x = i+dx[d], y = j+dy[d];
          1 <= x && x <= N && 1 <= y && y <= M && D[x][y] != '*';
          x += dx[d], y += dy[d]) {
            ck |= T[x][y];
          }*/
        if(ck == 3) return 0 & puts("YES");
      }
    }
  }


  puts("NO");


  return 0;
}