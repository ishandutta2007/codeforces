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

int N, M, A[1024*1024];
ll res;

int main() {
	int i, j, k;

	scanf("%d", &M);
	N = (int)sqrt(M);
	
	for(i = 0; i < M; i++) scanf("%d", A+i);
	sort(A, A+M, greater<int>());

	ll sum = 0;
	for(i = 0, k = 1; i < M; i++) {
		sum += A[i];
		if(i+1 == k) k <<= 2, res += sum;
	}

	printf("%lld\n", res);
	return 0;
}