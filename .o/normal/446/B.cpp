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

const int SZ = 1005;
const int SZK = 1000105;
int N,M,D,P;
int A[SZ][SZ];
ll SX[SZ], SY[SZ], DPX[SZK], DPY[SZK];
priority_queue<ll> PQ;

int main() {
	scanf("%d%d%d%d", &N, &M, &D, &P);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) {
		scanf("%d", &A[i][j]);
		SX[i] += A[i][j]; SY[j] += A[i][j];
	}
	
	for(int i = 0; i < N; i++) PQ.push(SX[i]);
	for(int i = 0; i < D; i++) {
		ll t = PQ.top(); PQ.pop();
		DPX[i+1] = DPX[i] + t;
		PQ.push(t - (ll)P * M);
	}
	
	while(!PQ.empty()) PQ.pop();
	for(int i = 0; i < M; i++) PQ.push(SY[i]);
	for(int i = 0; i < D; i++) {
		ll t = PQ.top(); PQ.pop();
		DPY[i+1] = DPY[i] + t;
		PQ.push(t - (ll)P * N);
	}

	ll res = -(ll)5e18;
	for(int i = 0; i <= D; i++) {
		res = max(res, DPX[i] + DPY[D-i] - (ll)i * (D-i) * P);
	}

	printf("%I64d\n", res);
	return 0;
}