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

const int SZ = 1050;

int N, M;
ll A[SZ][SZ];
ll T1[SZ][SZ], T2[SZ][SZ], T3[SZ][SZ], T4[SZ][SZ];
ll res;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) scanf("%I64d", &A[i][j]);
	
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) T1[i][j] = max(T1[i-1][j], T1[i][j-1]) + A[i][j];
	for(int i = 1; i <= N; i++) for(int j = M; j >= 1; j--) T2[i][j] = max(T2[i-1][j], T2[i][j+1]) + A[i][j];
	for(int i = N; i >= 1; i--) for(int j = 1; j <= M; j++) T3[i][j] = max(T3[i+1][j], T3[i][j-1]) + A[i][j];
	for(int i = N; i >= 1; i--) for(int j = M; j >= 1; j--) T4[i][j] = max(T4[i+1][j], T4[i][j+1]) + A[i][j];

	for(int i = 2; i < N; i++) for(int j = 2; j < M; j++) {
		res = max(res, T1[i-1][j] + T2[i][j+1] + T3[i][j-1] + T4[i+1][j]);
		res = max(res, T1[i][j-1] + T2[i-1][j] + T3[i+1][j] + T4[i][j+1]);
	}

	printf("%I64d\n", res);

	return 0;
}