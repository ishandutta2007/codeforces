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

const int M_ = 100005, N_ = 100005;

int M, Q[M_], N, A[N_];
ll res;

int main() {
	int i, j, k;
	
	scanf("%d", &M);
	for(i = 1; i <= M; i++) scanf("%d", Q+i);
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);

	sort(Q+1, Q+M+1);
	sort(A+1, A+N+1);

	for(i = N; i > 0; ){
		for(j = 0; j < Q[1] && i - j > 0; j++) res += A[i - j];
		i -= Q[1] + 2;
	}

	printf("%I64d\n", res);

	return 0;
}