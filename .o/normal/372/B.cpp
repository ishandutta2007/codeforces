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
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;

const int SZ = 45;

int N, M, Q;
int D[SZ][SZ];
char S[SZ];

int P[SZ][SZ];
ll Table[SZ][SZ][SZ][SZ]; 
ll Res[SZ][SZ][SZ][SZ];

bool good (int x1, int y1, int x2, int y2) {
	return (D[x2][y2] - D[x2][y1-1] - D[x1-1][y1] + D[x1-1][y1-1]) == 0;
}

int main() {
	int i, j, k, x, y;

	scanf("%d%d%d", &N, &M, &Q);
	for(i = 1; i <= N; i++) {
		scanf("%s", S+1);
		for(j = 1; j <= M; j++) D[i][j] = S[j] - '0';
	}

	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			int &p = P[i][j];
			for(p = j; p > 0 && D[i][p] == 0; p--);
		}
	}

	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			for(y = j; y > P[i][j]; y--) {
				for(x = i; x > 0 && P[x][j] < y; x--) {
					Table[x][y][i][j] += 1;
				}
			}
		}
	}

	for(i = 1; i <= N; i++) {
		for(j = 1; j <= M; j++) {
			for(x = i; x > 0; x--) {
				for(y = j; y > 0; y--) {
					Table[x][y][i][j] += Table[x+1][y][i][j] + Table[x][y+1][i][j] - Table[x+1][y+1][i][j];
				}
			}
		}
	}

	for(x = 1; x <= N; x++) {
		for(y = 1; y <= M; y++) {
			for(i = x; i <= N; i++) {
				for(j = y; j <= M; j++) {
					Res[x][y][i][j] = Table[x][y][i][j] + Res[x][y][i-1][j] + Res[x][y][i][j-1] - Res[x][y][i-1][j-1];
				}
			}
		}
	}

	while(Q--){ 
		int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%I64d\n", Res[a][b][c][d]);
	}
	return 0;
}