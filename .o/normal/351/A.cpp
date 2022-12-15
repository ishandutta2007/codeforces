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

const int SZ = 4105;

int N;
ll Cost[SZ];
ll sum ;
ll res = (ll)1e15;

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1, j = 0; i <= N+N; i++) {
		lf x; scanf("%lf", &x);
		Cost[i] = (ll)(1000.0 * x + .5) % 1000ll;
		if(Cost[i] == 0) ++j;
		sum += Cost[i];
	}

	for(i = max(N-j, 0); i <= N && i <= N+N-j; i++) {
		ll val = abs(sum - 1000ll * i);
		res = min(res, val);
	}

	printf("%.3lf\n", res * 0.001);

	return 0;	
}