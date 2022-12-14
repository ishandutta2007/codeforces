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

int N;
bool A[10];

int main() {
	int i, j, k;

	scanf("%d", &N);

	int x; scanf("%d", &x);
	for(i = 0; i < N; i++) {
		int a, b; scanf("%d%d", &a, &b);
		memset(A, 0, sizeof A);
		A[a] = A[b] = A[x] = A[7-a] = A[7-b] = A[7-x] = 1;
		for(j = 1; j <= 6; j++) if(!A[j]) break;
		if(j <= 6) return 0 & puts("NO");
	}
	puts("YES");
	return 0;
}