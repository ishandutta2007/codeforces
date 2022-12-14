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

const int N_ = 200005;

int N, A[N_], L[N_], R[N_];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);

	for(int i = 1; i <= N; i++) L[i] = L[i-1] + A[i];
	for(int i = N; i >= 1; i--) R[i] = R[i+1] + !A[i];

	ll sum[2] = {0,0};
	for(int i = 1; i <= N; i++) sum[A[i]] += A[i] ? R[i] : L[i];
	
	printf("%I64d\n", min(sum[0], sum[1]));
	return 0;
}