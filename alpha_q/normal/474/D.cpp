#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1e5 + 7;
const long long MOD = 1e9 + 7;

long long DP[MAX], t, k, a, b, Ret;

int main() {	
	//freopen("input.txt", "r", stdin);

	scanf("%I64d %I64d", &t, &k);

	for (int i = 0; i < k; i++) DP[i] = 1;
	for (int i = k; i < MAX; i++) DP[i] = (DP[i - 1] + DP[i - k]) % MOD;
	for (int i = 1; i < MAX; i++) DP[i] += DP[i - 1], DP[i] %= MOD;
	
	while (t--) {
		scanf("%I64d %I64d", &a, &b);
		Ret = (DP[b] - DP[a - 1]) % MOD;
		Ret = (Ret + MOD) % MOD;
		printf("%I64d\n", Ret);
	}
    return 0;
}