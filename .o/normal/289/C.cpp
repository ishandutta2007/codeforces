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

	if(N < K || (N>1 && K==1)) return 0 & puts("-1"); 
if(N==1 && K==1) return 0& putchar('a');
	for(i = 0; i < N-(K-2); i++) putchar(i%2+'a');
	for(i = 2; i < K; i++) putchar(i+'a');
	return 0;
}