
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

const int MOD = (int)1e9 + 7;
const int MAXN = 4050;

ll tb[MAXN][MAXN];
ll comb[MAXN][MAXN];

ll ans;
int N;

int main() {
#ifndef ONLINE_JUDGE
	freopen("568B.in", "r", stdin);
	freopen("568B.out", "w", stdout);
#endif

	scanf("%d", &N);

	comb[0][0] = 1;
	for (int i = 1; i <= N+3; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= i; j++) comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
	}

	tb[0][0] = tb[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			tb[i][j] += (tb[i - 1][j - 1] + (j * tb[i - 1][j]) % MOD) % MOD;
			tb[i][j] %= MOD;
		}
	}

	for (int i = 1; i <= N; i++) {
		ll val = 0;
		for (int j = 0; j <= N - i; j++) (val += tb[N - i][j]) %= MOD;
		ans += val * comb[N][i];
		ans %= MOD;
	}

	printf("%lld\n", ans);


	return 0;
}