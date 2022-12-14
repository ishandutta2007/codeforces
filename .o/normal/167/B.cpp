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

int N, L, K;
lf Table[205][205][205];
lf P[205];
int A[205];
lf res;

int main() {
	int i, j, k;

	scanf("%d%d%d", &N, &L, &K);
	for(i = 1; i <= N; i++) scanf("%lf", P+i), P[i] /= 100.;
	for(i = 1; i <= N; i++) { scanf("%d", A+i); ++A[i]; }

	Table[0][0][0] = 1.;
	for(i = 0; i < N; i++) {
		for(j = 0; j <= i; j++) {
			for(k = 0; k <= N; k++) {
				Table[i+1][j+1][min(k+A[i+1], N)] += Table[i][j][k] * P[i+1]; // win
				Table[i+1][j][k] +=  Table[i][j][k] * (1 - P[i+1]); // lose
			}
		}
	}

	for(j = L; j <= N; j++) {
		for(k = 0; k <= N; k++) {
			if(K+k >= j) res += Table[N][j][k];
		}
	}

	printf("%.10lf\n", res);
	return 0;
}