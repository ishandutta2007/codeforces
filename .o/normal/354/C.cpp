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

const int SZ = 1000015;

int N, K, C[SZ];
int res;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &K);

	int mn = K+1;
	for(i = 1; i <= N; i++) {
		int v; scanf("%d", &v);
		if(mn > v) mn = v;
		++C[v];
	}

	for(i = 1; i < SZ; i++) C[i] += C[i-1];

	if(mn <= K) res = mn;
	else {
		for(k = SZ-1; k > K && res == 0; k--) {
			int sum = 0;
			for(j = k; j < SZ; j += k) sum += C[min(SZ-1, j+K)] - C[j-1];
			if(sum >= N) res = k;
		}
	}

if(res == 0) assert(0);
	printf("%d\n", res);
	return 0;	
}