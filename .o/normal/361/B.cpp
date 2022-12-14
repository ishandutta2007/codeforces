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

int N, K;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &K);
	if(N == K) {
		puts("-1");
		return 0;
	}

	for(i = 1; i <= N-K; i++) printf("%d ", i>1?i-1:N-K);
	for(i = N-K+1; i <= N; i++) printf("%d ", i);

	return 0;
}