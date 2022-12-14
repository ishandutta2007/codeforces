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

using namespace std; 
typedef long long ll; 
typedef unsigned long long llu; 
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, M, K;
char D[2005][2005];
int dx[128], dy[128];

int Res[2005];

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0; i < N; i++) scanf("%s", D[i]);

	dx['U'] = -1;
	dx['D'] = 1;
	dy['L'] = -1;
	dy['R'] = 1;

	for(int x = 0; x < N; x++) for(int y = 0; y < M; y++) if(D[x][y] != '.') {
		if(D[x][y] == 'L') {
			if(y - x >= 0) Res[y-x] += 1;
		}
		if(D[x][y] == 'R') {
			if(y + x < M) Res[y+x] += 1;
		}
		if(D[x][y] == 'U') {
			if(x % 2 == 0) Res[y]++;
		}
		if(D[x][y] == 'D') {
		}
	}

	for(int i = 0; i < M; i++) printf("%d ", Res[i]);

	return 0;
}