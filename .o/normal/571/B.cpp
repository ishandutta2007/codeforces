
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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 500500;
const int K_ = 10050;

int N, K;
int A[N_];
ll tb[2][K_];

ll diff(int x, int y) {
	return abs((ll)A[x] - A[y]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("571B.in", "r", stdin);
	freopen("571B.out", "w", stdout);
#endif
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++) scanf("%d", A + i);
	sort(A, A + N);
	int b = N / K, c = N % K;

	for (int j = 1; j < K; j++) tb[1][j] = (ll)1e18;
	for (int i = 0; i < K; i++) {
		int pos = i * b;
		int t = i & 1;
		for (int j = 0; j <= c; j++) {
			tb[t][j] = (tb[!t][j] + diff(pos + j, pos + j + b - 1));
			if (j > 0) tb[t][j] = min(tb[t][j], tb[!t][j - 1] + diff(pos + j - 1, pos + j - 1 + b));
		}
	}

	printf("%I64d\n", tb[~K & 1][N % K]);
	return 0;
}