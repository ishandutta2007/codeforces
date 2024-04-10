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

const int MOD = 1000000007;

int N, A[1005], tb[2][20005];

int& Table(int x, int y) { return tb[x&1][y+10000]; }

int res;

int main() {
	scanf("%d",&N);
	for(int i = 1; i <= N; i++) scanf("%d" ,A+i);

	Table(0, 0) = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = -10000; j <= 10000; j++) Table(i, j) = 0;
		for(int j = A[i]-10000; j <= 10000-A[i]; j++) {
			Table(i, j+A[i]) += Table(i-1, j); Table(i, j+A[i]) %= MOD;
			Table(i, j-A[i]) += Table(i-1, j); Table(i, j-A[i]) %= MOD;
		}
		res = (res + Table(i, 0)) % MOD;
		Table(i, 0) = (Table(i, 0) + 1) % MOD;
	}

	printf("%d\n", res);
	return 0;
}