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

const int N_ = 25;

int N;
char D[N_][N_];
int Table[40][1<<20];
bool Chk[40][1<<20];
int wh[26][N_+N_];
int cst[2][2] = {{1, -1},{-1, 1}};

int solve (int x, int state) {
	if(x == N+N-1) return 0;
	if(Chk[x][state]) return Table[x][state];

	int &ret = Table[x][state];
	ret = (int)-1e9;

	int state_s = state | (state << 1);
	if(!state) state_s = 1;

	for(int c = 0; c < 26; c++) {
		int nxt = state_s & wh[c][x];
		if(nxt != 0) {
			int nxtret = ((c > 1) ? 0 : cst[x&1][c]) - solve(x+1, nxt);
			ret = max(ret, nxtret);
		}
	}


	Chk[x][state] = 1;
	return ret;
}

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 0; i < N; i++) scanf("%s", D[i]);

	for(int c = 0; c < 26; c++) for(i = 0; i < 2*N-1; i++) {
		for(j = max(i-N+1, 0); j < N && j <= i; j++) if(D[i-j][j] == c+'a') wh[c][i] |= 1<<j;
	}

	int ret = solve(0, 0);

	puts((ret == 0) ? "DRAW" : ((ret > 0) ? "FIRST" : "SECOND"));
	return 0;	
}