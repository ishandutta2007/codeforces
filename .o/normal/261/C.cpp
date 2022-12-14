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

const int SZ = 42;
ll N, T;
int K, Q;
ll Len[SZ+10];
ll Table[SZ+5][SZ+5];
ll res;

int main() {
	int i, j, k;

	scanf("%I64d%I64d", &N, &T);

	for(K = 0; (1ll << K) < T; K++);
	if((1ll << K) != T) {
		puts("0");
		return 0;
	}

	Len[1] = 2;
	for(i = 2; i <= SZ; i++) Len[i] = Len[i-1] * 3 - Len[i-2] * 2;
	
	Table[0][0] = Table[1][0] = Table[1][1] = 1;
	for(i = 2; i <= SZ; i++) {
		for(j = 0; j <= SZ; j++) Table[i][j] += Table[i-1][j];
		for(j = 1; j <= SZ; j++) Table[i][j] += Table[i-1][j-1];
	}

	for(i = SZ, k = 0; i > 0 && N > 0; i--) {
		if(Len[i] <= N) {
			for(k = 1; k <= i; k++) res += Table[k][K];
			Q = i;
			N -= Len[i];
			break;
		}
	}

	for(i = Q, k = 0; i >= 0; i--) {
		if(N & (1ll << i)) {
			res += Table[i][K-k];
			++k;
		}
	}

	printf("%I64d\n", res);

	return 0;
}