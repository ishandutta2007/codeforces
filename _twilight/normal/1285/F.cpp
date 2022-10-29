#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

int gcd(int a, int b) {
	return (!b) ? (a) : gcd(b, a % b);
}

#define pii pair<int, int>

int n, V;
int a[N];
vector<pii> b;

class Sieve {
	public:
		int pri[N], mp[N], mu[N];

		Sieve(int n) {
			static bitset<N> vis;
			int *tp = pri;
			mu[1] = 1;
			for (int i = 2; i <= n; i++) {
				if (!vis.test(i))
					*(tp++) = mp[i] = i, mu[i] = -1;
				for (int* p = pri, x; p != tp && (x = *p * i) <= n; p++) {
					vis.set(x);
					mp[x] = *p;
					if (!(i % *p)) {
						mu[x] = 0;
						break;
					} else {
						mu[x] = -mu[i];
					}
				}
			}
		}

		vector<pii> factorize(int x) {
			vector<pii> rt;
			while (x > 1) {
				int p = mp[x], pd = 1;
				while (!(x % p))
					x /= p, pd *= p;
				rt.emplace_back(p, pd);
			}
			return rt;
		}
} sieve (100000);

int cnt[N];
vector<int> divisors[N];
void upd(int p, int v) {
	for (auto d : divisors[p])
		cnt[d] += v;
}
int qry(int p) {
	static int* mu = sieve.mu;
	int rt = 0;
	for (auto d : divisors[p])
		rt += mu[d] * cnt[d];
	return rt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		V = max(V, x);
		auto P = sieve.factorize(x);
		int m = (signed) P.size();
		for (int s = 0, pv, pd; s < (1 << m); s++) {
			pd = pv = 1;
			for (int i = 0; i < m; i++)
				if ((s >> i) & 1) {
					pv *= P[i].first;
					pd *= P[i].second;
				}
			a[pv] = max(a[pv], pd);
		}
	}
	for (int i = 1; i <= V; i++) {
		for (int j = i; j <= V; j += i) {
			divisors[j].push_back(i);
		}
	}
	for (int i = 1; i <= V; i++)
		if (a[i])
			b.emplace_back(a[i], i);
	sort(b.begin(), b.end(), greater<pii>());
	long long ans = 1;
	stack<int> stk;
	for (auto par : b) {
		int p = par.second;
		int t = qry(p);
		while (t) {
			int q = stk.top();
			upd(q, -1);
			if (__gcd(p, q) == 1) {
				ans = max(ans, 1ll * a[p] * a[q]);
				t--;
			}
			stk.pop();
		}
		upd(p, 1);
		stk.push(p);
	}
	printf("%lld\n", ans);
	return 0;
}