#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int len;
bitset <N> vis;
long long n, k;
vector <ll> pr;

void sieve (void) {
	for (int i = 2; i * i < N; ++i) if (!vis[i]) {
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
	for (int i = 2; i < N; ++i) {
		if (!vis[i]) pr.push_back((ll) i);
	}
	len = pr.size();
}

ll phi (ll x) {
	ll res = x;
	for (int i = 0; i < len; ++i) {
		if (pr[i] * pr[i] > x) break;
		if (x % pr[i] == 0) {
			while (x % pr[i] == 0) x /= pr[i];
			res /= pr[i];
			res *= (pr[i] - 1LL);
		}
	}
	if (x > 1) {
		res /= x;
		res *= (x - 1LL);
	}
	return res;
}

int main (int argc, char const *argv[]) {
	sieve();
	cin >> n >> k;
	k = 1LL + k >> 1;
	ll ret = n;
	while (k--) {
		if (ret == 1LL) break;
		ret = phi(ret);
	}
	printf("%lld\n", ret % MOD);
	return 0;
}