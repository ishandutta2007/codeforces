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

int N, D;
ll B[2005];
ll res;

int main() {
	int i, j, k;

	scanf("%d%d", &N, &D);
	for(i = 1; i <= N; i++) {
		scanf("%lld", B+i);
		if(i >= 2) {
			ll t = B[i-1] - B[i];
			if(t >= 0) {
				ll v = t / D + 1;
				res += v;
				B[i] += v*D;
			}
		}
	}

	printf("%I64d\n", res);
	return 0;
}