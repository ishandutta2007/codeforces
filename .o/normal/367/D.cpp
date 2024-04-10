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

const int M_ = 20;
const int N_ = 100005;

int N, M, K;
int X[N_];
bool T[1<<M_];
int A[M_];
int res;

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &M, &K);
	if(K == 1) {
		printf("%d\n", M);
		return 0;
	}
	
	for(i = 0; i < M; i++) {
		int sz; scanf("%d", &sz);
		for(j = 0; j < sz; j++) {
			int x; scanf("%d", &x);
			X[x-1] = i;
		}
	}

	for(i = 0; i < N; i++) {
		++A[X[i]];
		if(i >= K) --A[X[i-K]];
		if(i >= K-1) {
			int state = 0;
			for(j = 0; j < M; j++) if(!A[j]) state |= 1<<j;
			T[state] = 1;
		}
	}

	res = M;

	for(i = (1<<M)-1; i > 0; i--) {
		if(T[i]) {
			for(j = 0; j < M; j++) if(i & (1<<j)) T[i ^ (1<<j)] = 1;
		}else {
			int cnt = 0;
			for(j = 0; j < M; j++) if(i & (1<<j)) ++cnt;
			if(res > cnt) res = cnt;
		}
	}
	
	printf("%d\n", res);
	return 0;
}