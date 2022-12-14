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

const int N_ = 100005;
int N, A[N_];
int res;
int L[N_], R[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	A[N+1] = (int)1e9 + 1;

	for(int i = 1; i <= N; i++) L[i] = (A[i-1] < A[i]) ? L[i-1] + 1 : 1;
	for(int i = N; i > 0; i--) R[i] = (A[i] < A[i+1]) ? R[i+1] + 1 : 1;
	
	for(int i = 1; i <= N; i++) {
		if(A[i-1] + 1 < A[i+1]) res = max(res, L[i-1] + R[i+1] + 1);
		res = max(res, L[i-1] + 1);
		res = max(res, R[i+1] + 1);
	}

	printf("%d\n", res);
	return 0;
}