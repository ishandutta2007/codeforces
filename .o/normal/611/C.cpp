#define _CRT_SECURE_NO_WARNINGS

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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int H,W,Q;
char S[550][550];
int X[550][550], Y[550][550];

int main() {
scanf("%d%d",&H,&W);
for(int i=1; i<=H; i++) {
 scanf("%s", S[i]+1);
 for(int j = 1; j <= W; j++) {
  X[i][j] = X[i-1][j] + X[i][j-1] - X[i-1][j-1] + (S[i][j] == '.' && S[i-1][j] == '.');
  Y[i][j] = Y[i-1][j] + Y[i][j-1] - Y[i-1][j-1] + (S[i][j] == '.' && S[i][j-1] == '.');
 }
}
for(scanf("%d", &Q); Q--; ){
 int r1, r2, c1, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
 int ans = (X[r2][c2] - X[r1][c2] - X[r2][c1-1] + X[r1][c1-1])
           + (Y[r2][c2] - Y[r2][c1] - Y[r1-1][c2] + Y[r1-1][c1]);
 printf("%d\n", ans);
}
return 0;
    return 0;
}