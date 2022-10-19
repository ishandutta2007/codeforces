#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define SQRT 450
#define MOD 998244353
#define MAXN 200010
vector<pair<int, int> > primefactors[MAXN];
ll ans;
ll mult;
int usedPrimeFactors[MAXN];
int deltaPrimeFactors[MAXN];
int seen[MAXN];
vector<pair<int, pair<int, int> > > adj[MAXN];
ll fastmult(ll n, ll k) {
	if (!k) return 1;
	ll ans = fastmult(n, k/2);
	ans *= ans;
	ans %= MOD;
	if (k % 2) {
		ans *= n;
		ans %= MOD;
	}
	return ans;
}
void dfs(int a) {
	seen[a] = true;
	for (auto ed : adj[a]) {
		int b = ed.first;
		if (seen[b]) continue;
		int x = ed.second.first, y = ed.second.second;
		// multiply ans by any unused prime factors
		for (auto p : primefactors[x]) {
			int diff = p.second-(usedPrimeFactors[p.first]+deltaPrimeFactors[p.first]);
			if (diff > 0) {
				while (diff) {
					D("factor = %d\n", p.first);
					diff--;
					ans *= (ll)p.first;
					ans %= MOD;
					usedPrimeFactors[p.first]++;
					mult *= (ll)p.first;
					mult %= MOD;
				}
			}
		}

		mult *= fastmult(x, MOD-2);
		mult %= MOD;
		for (auto p : primefactors[x]) {
			deltaPrimeFactors[p.first] -= p.second;
		}

		mult *= y;
		mult %= MOD;
		for (auto p : primefactors[y]) {
			deltaPrimeFactors[p.first] += p.second;
		}

		ans += mult;
		ans %= MOD;
		D("adding %lld times %d\n", mult, y);
		
		dfs(b);

		mult *= x;
		mult %= MOD;
		for (auto p : primefactors[x]) {
			deltaPrimeFactors[p.first] += p.second;
		}

		mult *= fastmult(y, MOD-2);
		mult %= MOD;
		for (auto p : primefactors[y]) {
			deltaPrimeFactors[p.first] -= p.second;
		}
	}
}
void solve() {
	int n;
	scanf("%d", &n);
	fill_n(seen, n+1, 0);
	fill_n(usedPrimeFactors, n+1, 0);
	ans = 1;
	mult = 1;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		int g = gcd(x, y);
		x /= g;
		y /= g;
		adj[a].push_back({b, {x, y}});
		adj[b].push_back({a, {y, x}});
		D("edge %d %d, %d %d\n", a, b, x, y);
	}
	dfs(1);
	printf("%lld\n", ans);
}	
int main() {
	for (int i = 2; i < MAXN; i++) {
		if (primefactors[i].empty()) {
			for (int j = i; j < MAXN; j += i) {
				int num = 0;
				int a = j;
				while (a % i == 0) {
					a /= i;
					num++;
					if (a == 0) exit(0);
				}

				primefactors[j].push_back({i, num});
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		solve();
	}
}