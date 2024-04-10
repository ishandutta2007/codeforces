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

int D, S;
int A[35], B[35], AS, BS;

int main() {
	int i, j, k;

	scanf("%d%d", &D, &S);
	for(i = 0; i < D; i++) {
		scanf("%d%d", A+i, B+i);
		AS += A[i];
		BS += B[i];
	}

	if(AS <= S && S <= BS) {
		puts("YES");
		S -= AS;
		for(i = 0; i < D; i++) {
			int x = B[i] - A[i];
			if(S >= x) S -= x; else x = S, S = 0;
			printf("%d ", A[i]+x);
		}
	}else {
		puts("NO");
	}
	
	return 0;
}