#include <bits/stdc++.h>

using namespace std;

int N, K;
const long long MOD = 1e9+7;
long long fact[100005];

long long add(long long a, long long b) {
	return (a + b) % MOD;
}

long long mult(long long a, long long b) {
	return a * b % MOD;
}

long long qikpow(long long b, long long e) {
	if(!e) {
		return 1;
	}
	long long ret = qikpow(b, e/2);
	ret = mult(ret, ret);
	if(e&1) {
		ret = mult(ret, b);
	}
	return ret;
}

long long choose(long long n, long long r) {

}

int main() {
	cin >> N >> K;
	K = min(K, N);
	long long ans = 0;
	fact[0] = 1;
	for(int i = 1; i <= N; i++) {
		fact[i] = mult(fact[i-1], i);
	}
	for(int k = 0; k <= K; k++) {
		long long invk = qikpow(fact[k], MOD - 2);
		long long invnk = qikpow(fact[N-k], MOD - 2);
		ans = add(ans, mult(fact[N], mult(invk, invnk)));
	}
	cout << ans << "\n";
}