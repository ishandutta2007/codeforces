#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// http://codeforces.com/contest/1074/problem/B

set<int> getSet() {
	int k;
	cin >> k;
	set<int> s;
	while (k--) {
		int x;
		cin >> x;
		s.insert(x);
	}
	return s;
}

int ask(const char c, const int u) {
	cout << c << ' ' << u << endl;
	if (c == 'C')
		return 0;
	int res;
	cin >> res;
	assert(res != -1);
	return res;
}

int n;
vector<int> adj[1009];

int dfs(const int u, const int parent, const set<int> &s1) {
	if (s1.count(u))
		return u;

	for (const int &v : adj[u])
		if (v != parent) {
			const int res = dfs(v, u, s1);
			if (res != -1)
				return res;
		}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		for (auto &&x : adj)
			x.clear();

		cin >> n;
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		const set<int> s1 = getSet();
		const set<int> s2 = getSet();

		const int u2 = *s2.begin();
		const int u1 = ask('B', u2);

		const int v1 = dfs(u1, -1, s1);
		const int v2 = ask('A', v1);

		ask('C', s2.count(v2) ? v1 : -1);
	}
	return 0;
}