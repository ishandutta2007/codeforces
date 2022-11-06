#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getPDivs(ll x) {
	vector<int> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i);
			for (x /= i; x % i == 0; x /= i)
				;
		}

	if (x != 1)
		v.emplace_back(x);
	return v;
}

const int MaxN = (int) 2e5 + 9;

vector<int> adj[MaxN + 9];
map<int, int> dp[MaxN + 9];
int a[MaxN + 9];

int f(const int u, const int parent, const int prime) {
	if (a[u] % prime != 0)
		return 0;
	auto it = dp[u].find(prime);
	if (it != dp[u].end())
		return it->second;

	int res = 1;
	for (const int &v : adj[u])
		if (v != parent)
			res = max(res, 1 + f(v, u, prime));

	return dp[u][prime] = res;
}

int ans = 0;

void g(const int u, const int parent) {
	const vector<int> divs = getPDivs(a[u]);
	for (const int&prime : divs) {
		int best1 = 0, best2 = 0;
		for (const int &v : adj[u]) {
			if (v == parent)
				continue;
			const int temp = f(v, u, prime);
			if (temp > best1) {
				best2 = best1;
				best1 = temp;
			} else if (temp > best2)
				best2 = temp;
		}
		ans = max(ans, 1 + best1 + best2);
	}

	for (const int &v : adj[u])
		if (v != parent)
			g(v, u);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	g(1, -1);
	cout << ans;
	return 0;
}