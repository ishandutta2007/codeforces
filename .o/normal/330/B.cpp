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

int N, M;
bool A[1005];

int main() {
	int i, j, k;

	scanf("%d", &N);
	scanf("%d", &M);
	for(i = 1; i <= M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		A[u] = A[v] = 1;
	}

	for(i = 1; i <= N; i++) if(!A[i]) {
		printf("%d\n", N-1);
		for(j = 1; j <= N; j++) if(i != j) printf("%d %d\n", i, j);
		return 0;
	}
	return 0;
}