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

int N, M, K;
ll res;

void cut (int h, int w) {
	if(h >= 0 && w >= 0 && h <= N-1 && w <= M-1) {
		res = max(res, (ll)(N / (h+1)) * (ll)(M / (w+1)));
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);

	if(K > N+M-2) return 0 & puts("-1");

	(K < M) ? cut(0, K) : cut(K-M+1, M-1);
	(K < N) ? cut(K, 0) : cut(N-1, K-N+1);

	ll t = (ll)K*N/(N+M);
	for(int x = -10000; x <= 10000; x++) cut(t+x, K-(t+x));
	
	printf("%lld\n", res);
	return 0;
}