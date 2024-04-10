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

int A[4], N;

int gcd (int a, int b) {
	while(b > 0) {
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int res;

int main() {
	int i, j, k;

	for(i = 0; i < 4; i++) scanf("%d", A+i);
	scanf("%d", &N);

	for(i = 1; i < 16; i++) {
		int m = 1, c = 0;
		for(j = 0; j < 4; j++) if(i & (1<<j)) m = m / gcd(m, A[j]) * A[j], ++c;
		res += (c % 2 ?	1 : -1) * (N / m);
	}

	printf("%d\n", res);
	return 0;
}