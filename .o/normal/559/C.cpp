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

int H, W, N;
pii D[2500];

const int MOD = (int)1e9 + 7;
ll tb[2050];

ll fac[200500], invfac[200500];

ll MYpow(ll a, ll b) {
	ll ret = 1;
	while (b > 0) {
		if (b & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

ll comb(int x, int y) {
	return (((fac[x] * invfac[x - y]) % MOD) * invfac[y]) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("559C.in", "r", stdin);
	freopen("559C.out", "w", stdout);
#endif

	scanf("%d%d%d", &H, &W, &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &D[i].first, &D[i].second);
		if (D[i].first == 1 && D[i].second == 1) return 0 * puts("0");
		if (D[i].first == H && D[i].second == W) return 0 * puts("0");
	}
	//D[++N] = pii(1, 1);
	D[++N] = pii(H, W);
	sort(D + 1, D + N + 1);

	fac[0] = 1; invfac[0] = 1;
	for (int i = 1; i <= 200000; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
		invfac[i] = MYpow(fac[i], MOD - 2);
	}

	for (int i = 1; i <= N; i++) {
		ll val = 0;
		for (int j = 1; j < i; j++) {
			int dx = D[i].first - D[j].first;
			int dy = D[i].second - D[j].second;
			if(dx >= 0 && dy >= 0) val = (val + tb[j] * comb(dx + dy, dx)) % MOD;
		}

		tb[i] = (comb(D[i].first + D[i].second - 2, D[i].first - 1) - val + MOD) % MOD;
	}

	printf("%I64d\n", tb[N]);
	return 0;
}