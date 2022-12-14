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

const int N_ = 55;
const int SZ = 2505;

int N, A[N_], P;
lf Table[N_][N_]; // Table[i,j]: length i, j persons
lf val[N_];
lf res;

int main() {
	int i, j, k;

	scanf("%d", &N);
	for(i = 1; i <= N; i++) scanf("%d", A+i);
	scanf("%d", &P);

	for(i = 1; i <= N; i++) {
		val[i] = 1.;
		for(k = 1; k <= N-i; k++) val[i] *= k;
		for(k = i+1; k <= N; k++) val[i] /= k;
	}

	Table[0][0] = 1;
	for(i = 1; i <= N; i++) {
		for(j = P; j >= A[i]; j--) {
			for(k = 1; k <= N; k++) Table[j][k] += Table[j-A[i]][k-1];
		}
	}

	for(i = 1; i <= P; i++) {
		for(j = 1; j <= N; j++) res += Table[i][j] * val[j];
	}

	printf("%.10lf\n", res);

	return 0;
}