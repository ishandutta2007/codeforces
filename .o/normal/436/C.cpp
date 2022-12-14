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

int N, M, K, W;
char S[1002][12][12];
int D[1002][1002];

int dist[1002];
int Res[1002][2];
bool used[1002];
int bef[1002];
int cost;

int main() {
	scanf("%d%d%d%d", &N, &M, &K, &W);
	
	for(int k = 1; k <= K; k++) {
		for(int i = 0; i < N; i++) scanf("%s", S[k][i]);
		D[0][k] = D[k][0] = N*M;
	}

	for(int k = 1; k <= K; k++) for(int l = 1; l <= K; l++) {
		int &d = D[k][l];
		for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(S[k][i][j] != S[l][i][j]) d += W;
	}
	
	for(int i = 1; i <= K; i++) dist[i] = (int)1e9;
	for(int i = 0; i <= K; i++) {
		int v = -1;
		for(int j = 0; j <= K; j++) if(!used[j] && (v < 0 || dist[j] < dist[v])) v = j;
		used[v] = true;
		if(i > 0) {
			Res[i][0] = v;
			Res[i][1] = bef[v];
		}

		cost += dist[v];
		for(int j = 0; j <= K; j++) if(dist[j] > D[v][j]) dist[j] = D[v][j], bef[j] = v;
	}

	printf("%d\n", cost);
	for(int i = 1; i <= K; i++) printf("%d %d\n", Res[i][0], Res[i][1]);

	return 0;
}