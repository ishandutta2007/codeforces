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
#include <time.h>
#include <functional>
#include <numeric>
#include <unordered_set>
 #include <cfloat>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const int N_ = 1050;

int N, K, M;
int A[N_][N_];

int main() {
	scanf("%d%d", &N, &K);
	M = N*N;

	int ans = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = N; j >= K; j--) {
			A[i][j] = M--;
			if(j == K) ans += A[i][j];
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = K-1; j > 0; j--) A[i][j] = M--;
	}
	
	printf("%d\n", ans);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) printf("%d ", A[i][j]);
		puts("");
	}

	return 0;
}