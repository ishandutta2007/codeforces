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

const int M_ = 250005;
int N, M, W[M_];

int main() {
	int i, j, k;

	scanf("%d%d", &N, &M);
	for(i = 0; i < M; i++) scanf("%*d%d", W+i);
	sort(W, W+M, greater<int>());

	long long t;
	for(t = 2; ; t++) {
		ll a = (t % 2 == 0) ? (t*(t-1)/2 + t/2 - 1) : (t*(t-1)/2);
		if(a >= N) { --t; break; }
	}

	ll res = 0;
	for(i = 0; i < M && i < t; i++) res += W[i];
	printf("%I64d\n", res);
	
	return 0;
}