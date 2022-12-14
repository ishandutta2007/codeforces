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

int main() {
	int i, j, k;

	scanf("%d%d", &N, &K);

	if(K == 0) {
		for(i = 1; i <= N+N; i++) printf("%d ", i);
		return 0;
	}

	printf("%d %d ", 1, 1+K);
	for(i = N+N; i > 1; i--) {
		if(i == K+1) continue;
		printf("%d ", i);
	}

	return 0;
}