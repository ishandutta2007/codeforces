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

const int N_ = 100005;
int N, M;
int R[N_];
int A[3], P[3];

int main() {
	int i, j, k;

	scanf("%d%d", &N, &M);
	for(i = 1; i <= M; i++) {
		for(j = 0; j < 3; j++) scanf("%d", A+j), P[j] = j;
		do {
			bool possible = true;
			for(j = 0; j < 3; j++) if(R[A[j]] && R[A[j]] != P[j]+1) possible = false;
			if(possible) {
				for(j = 0; j < 3; j++) R[A[j]] = P[j]+1;
				break;
			}
		}while(next_permutation(P, P+3));
	}

	for(i = 1; i <= N; i++) printf("%d ", R[i]);

	return 0;
}