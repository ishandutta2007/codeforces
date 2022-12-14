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

int K, C[1005], N;

ll comb[1005][1005];
const int MOD = 1000000007;

ll ans;

int main() {

	scanf("%d", &K);
	for (int i = 1; i <= K; i++) scanf("%d", C + i), N += C[i];

	comb[0][0] = 1;
	for (int i = 1; i <= 1000; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
	}

	ans = 1;
	for (int i = K; i > 0; i--) {
		ans = (ans * comb[N - 1][C[i] - 1]) % MOD;
		N -= C[i];
	}

	printf("%I64d\n", ans);
	return 0;
}