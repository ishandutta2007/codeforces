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

ll K, B, N, T;
ll res;


int main() {

	int i, j, k;

	scanf("%I64d%I64d%I64d%I64d", &K, &B, &N, &T);

	if(K == 1) {
		ll Z = 1 + B * N;
		ll low = 0, high = N;
		res = N;
		while(low <= high) {
			ll mid = (low + high) >> 1;
			ll R = T + B * mid;
			if(Z <= R) {
				res = mid;
				high = mid - 1;
			}else {
				low = mid + 1;
			}
		}
	}
	else {
		llf A = log(K) * N;
		llf Q = 1 - ((llf)T - 1.) / ((llf)B / (llf)(K - 1) + (llf)T);
		llf L = A + log(Q);
	
		ll low = 0, high = N;
		res = N;
		while(low <= high) {
			ll mid = (low + high) >> 1;
			llf R = log(K) * mid;
			if(L <= R || fabs(L - R) < 1e-7) {
				res = mid;
				high = mid - 1;
			}else {
				low = mid + 1;
			}
		}
	}

	printf("%lld\n", res);
	return 0;
}