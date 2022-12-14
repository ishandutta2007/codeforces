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

const int N_ = 100005;

int N, K;
int A[N_];
int S[N_];
bool Chk[N_];
int res;

int main() {

	int i, j, k;

	scanf("%d%d", &N, &K);
	if(K == 1) {
		printf("%d\n", N);
		return 0;
	}

	for(i = 1; i <= N; i++) scanf("%d", A+i);
	sort(A+1, A+N+1);

	for(i = 1, j = 1; i <= N; i++) {
		S[i] = -1;
		if(A[i]	% K == 0) {
			int t = A[i] / K;
			while(j < i && A[j] < t) ++j;
			if(A[j] == t) S[i] = j;
		}
	}

	for(i = N; i > 0; i--) {
		if(!Chk[i]) {
			int c = 1;
			for(j = i; j > 0 && S[j] != -1; j = S[j]) Chk[S[j]] = 1, ++c;
			res += (c+1) / 2;
		}
	}

	printf("%d\n", res);
	return 0;
}