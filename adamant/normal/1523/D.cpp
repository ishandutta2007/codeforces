#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 2e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a - b + mod) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

int fact[maxn];

int F(int n) {
	return fact[n] ? fact[n] : fact[n] = n ? mul(F(n - 1), n) : 1;
}
int nCr(int n, int r) {
	return r < 0 || n - r < 0 ? 0 : mul(F(n), mul(inv(F(r)), inv(F(n - r))));
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bitset<maxn> rev[66], tmp;

void solve() {
	tmp.flip();
	size_t n, m, p;
	cin >> n >> m >> p;
	string s[n];
	int msk[n];
	for(size_t i = 0; i < n; i++) {
		cin >> s[i];
		msk[i] = 0;
		for(size_t j = 0; j < m; j++) {
			if(s[i][j] == '1') {
				rev[j][i] = 1;
				msk[i] |= 1LL << j;
			}
		}
	}
	int ans = 0;
	unordered_set<int> checked;
	for(int z = 0; z < 10; z++) {
		int super = msk[rng() % n];
		for(int ms = super; ms; ms = super & (ms - 1)) {
			if(!checked.count(ms) && __builtin_popcountll(ms) > __builtin_popcountll(ans)) {
				checked.insert(ms);
				bitset<maxn> fr = tmp;
				for(size_t j = 0; j < m; j++) {
					if((ms >> j) & 1) {
						fr &= rev[j];
						if(2 * fr.count() < n) {
							break;
						}
					}
				}
				if(2 * fr.count() >= n) {
					ans = ms;
				}
			}
		}
	}
	string as(m, '0');
	for(size_t i = 0; i < m; i++) {
		if((ans >> i) & 1) {
			as[i] = '1';
		}
	}
	cout << as << "\n";
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}