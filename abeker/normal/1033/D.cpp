#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e2 + 5;
const int MOD = 998244353;

int N;
ll a[MAXN];
unordered_map <ll, int> ex, cnt;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", a + i);
}

inline int mul(int x, int y) {
	return (ll)x * y % MOD;
}

ll calc(ll x, int k) {
	ll lo = 1, hi = 2e9;
	while (lo < hi) {
		ll mid = (lo + hi + 1) / 2;
		ll tmp = x;
		for (int i = 0; i < k; i++)
			tmp /= mid;
		if (tmp)
			lo = mid;
		else
			hi = mid - 1;
	}
	for (int i = 0; i < k; i++) {
		if (x % lo)
			return -1;
		x /= lo;
	}
	return x == 1 ? lo : -1;
}

bool prime(ll x) {
	if (x == 1)
		return false;
	for (ll i = 2; i * i <= x; i++)
		if (!(x % i))
			return false;
	return true;
}

int solve() {
	for (int i = 0; i < N; i++) {
		bool ok = false;
		for (int j = 2; j <= 4; j++) {
			ll tmp = calc(a[i], j);
			if (tmp != -1 && prime(tmp)) {
				ex[tmp] += j;
				ok = true;
				break;
			}
		}
		if (!ok)
			cnt[a[i]]++;
	}
	
	int sol = 1;
	for (auto it : cnt) {
		bool ok = false;
		for (auto p : ex)
			if (!(it.first % p.first)) {
				ex[p.first] += it.second;
				ex[it.first / p.first] += it.second;
				ok = true;
				break;
			}
			
		if (ok)
			continue;
			
		for (auto it1 : cnt)
			if (it1.first != it.first) {
				ll g = __gcd(it1.first, it.first);
				if (g > 1) {
					ex[g] += it.second;
					ex[it.first / g] += it.second;
					ok = true;
					break;
				}
			}
			
		if (ok)
			continue;
			
		sol = mul(sol, mul(it.second + 1, it.second + 1));
	}
	
	for (auto it : ex) 
		sol = mul(sol, it.second + 1);
	
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}