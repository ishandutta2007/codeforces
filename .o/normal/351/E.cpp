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

const int SZ = 2205;

int N, D[SZ], E[SZ];

int A[SZ], AN;
int R[SZ], RN;

int res;

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) {
		scanf("%d", D+i);
		A[i] = E[i] = abs(D[i]);
	}

	sort(A+1, A+N+1);
	AN = unique(A+1, A+N+1) - (A+1);

	for(i = 1; i <= AN; i++) {
		int sum = 0;
		for(j = 1, k = 0, RN = 0; j <= N; j++) {
			if(A[i] > E[j]){
				++k;
			}else if(A[i] == E[j]) {
				R[++RN] = k; sum += k;
				k = 0;
			}
		}

		R[++RN] = k;
		sum += k;

		int now = 0;
		for(j = 1; j < RN; j++) {
			now += R[j];
			res += min(now, sum-now);
		}
	}

	printf("%d\n", res);

	return 0;	
}