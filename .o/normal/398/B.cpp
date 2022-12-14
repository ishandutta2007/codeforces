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
 
using namespace std;
typedef long long ll;
typedef double lf;
typedef long double llf;
typedef unsigned long long llu;

int N, M;
lf Table[2005][2005];
int R, C;
bool chkR[2005], chkC[2005];

int main() {
	scanf("%d%d", &N, &M);
	
	R = C = N;
	for(int i = 1; i <= M; i++) {
		int r, c; scanf("%d%d", &r, &c);
		if(!chkR[r]) --R;
		if(!chkC[c]) --C;
		chkR[r] = chkC[c] = true;
	}

	for(int i = 1; i <= N; i++) Table[i][0] = Table[i-1][0] + (lf)N / i;
	for(int j = 1; j <= N; j++) Table[0][j] = Table[0][j-1] + (lf)N / j;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) {
		lf &v = Table[i][j];
		v = (i * j * Table[i-1][j-1])
			 + ((N - i) * j * Table[i][j-1])
			 + (i * (N - j) * Table[i-1][j]);
		v /= N*N;
		v = v+1;
		v /= (1. - (lf)(N-i) * (N-j) / (N*N));
	}

	printf("%.10Lf\n", Table[R][C]);
	return 0;
}