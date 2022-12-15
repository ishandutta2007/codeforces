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

const int N_ = 3005;
int N, P[N_];
ll inv;

int main() {
	int i, j, k;
	
	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", P+i);

	for(i = 1; i <= N; i++) {
		for(j = 1; j < i; j++) if(P[j] > P[i]) ++inv;
	}

	ll res = inv;
	res /= 2;
	res *= 4;
	if(inv & 1) ++res;

	printf("%I64d", res);
	return 0;
}