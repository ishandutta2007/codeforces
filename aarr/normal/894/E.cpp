#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000 * 1000 + 5, P = 20 * 1000 + 5;;
int t = 0;

vector <pair <int, int> > adj[N];
vector <int> adjr[N];
long long s[N];
long long a[P];
long long ps[P];
long long dp[N];
vector <int> vec;
vector <pair <int, int> > adjp[N];
int part[N];
bool mark[N];

void dfs(int v) {
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first;
		if (!mark[u]) {
			dfs(u);
		}
	}
	vec.push_back(v);
}

void dfsr(int v) {
	for (auto u : adjr[v]) {
		if (!part[u]) {
			part[u] = part[v];
			dfsr(u);
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	for (int i = 1; i < P; i++) {
		a[i] = a[i - 1] + i;
		ps[i] = ps[i - 1] + a[i];
	//	cout << i << " " << a[i] << " " << ps[i] << endl;
	}
	int n, m, st;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adjr[v].push_back(u);
	}
	cin >> st;
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			dfs(i);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		int v = vec[i];
		if (!part[v]) {
			t++;
			part[v] = t;
			dfsr(v);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << part[i] << " ";
//	}
	for (int i = 1; i <= n; i++) {
		for (auto p : adj[i]) {
			int u = p.first, w = p.second;
			if (part[i] == part[u]) {
				int x = upper_bound(a, a + P, w) - a;
				s[part[i]] += 1ll * w * x;
				s[part[i]] -= ps[x - 1];
			}
			else {
				adjp[part[i]].push_back({part[u], w});
			}
		}
	}
//	for (int i = 1; i <= t; i++) {
//		cout << s[i] << " ";
//	}
	for (int i = t; i; i--) {
		for (auto p : adjp[i]) {
			int u = p.first, w = p.second;
			dp[i] = max(dp[i], dp[u] + w);
		}
		dp[i] += s[i];
	}
	cout << dp[part[st]];
	return 0; 
}