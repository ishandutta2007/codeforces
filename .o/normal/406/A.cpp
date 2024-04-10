#define _CRT_SECURE_NO_WARNINGS

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
typedef pair<ll, int> pli;

const int N_ = 1005;

int N, A[N_][N_], Q;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
		scanf("%d", &A[i][j]);
	}

	int r = 0;
	for(int i = 0; i < N; i++) {
		r ^= A[i][i];
	}

	scanf("%d", &Q);
	while(Q--) {
		int q; scanf("%d", &q);
		if(q == 3) putchar(r + '0');
		else r = !r, scanf("%*d");
	}
	return 0;
}