#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
	long long x;
	scanf("%lld", &x);

	int sol;
	long long a = x / 2 + 2;
	
	if (a % 2 == 0) sol = 1LL * a / 2 % MOD * (a / 2 % MOD) % MOD;
	else sol = (1LL * a / 2 % MOD * (a / 2 % MOD) % MOD + a / 2) % MOD;

	printf("%d\n", sol);
}

int main() {

	int t;
	scanf("%d", &t);
	while (t--) solve();

	return 0;
}