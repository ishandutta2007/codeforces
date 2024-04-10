#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, D = 53, ND = N * D;
int n, m, d, t;

vector <int> adj[N], adjr[N];
vector <int> vec;
int part[ND];
bool b[ND];
int dp[ND];
vector <int> cmp[ND];
bitset <N> e;

void dfs(int v) {
	part[v] = true;
	for (auto x : adj[v / d]) {
		int u = (v + 1) % d + x * d;
		if (!part[u]) {
			dfs(u);
		}
	}
	vec.push_back(v);
}

void dfsr(int v) {
	for (auto x : adjr[v / d]) {
		int u = (v - 1 + d) % d + x * d;
		if (!part[u]) {
			part[u] = part[v];
			dfsr(u);
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
	//	for (int j = 0; j < d; j++) {
	//		int x = u * d + j, y = v * d + ((j + 1) % d);
	//		adj[x].push_back(y);
	//		adjr[y].push_back(x);
	//	}
		adj[u].push_back(v);
		adjr[v].push_back(u);
	}
	for (int i = 0; i < n * d; i++) {
		char c;
		cin >> c;
		b[i] = c - '0';
	}
	for (int i = 0; i < n * d; i++) {
		if (!part[i]) {
			dfs(i);
		}
	}
//	if (vec.size() != n * d) {
//		int x = 0;
//		n /= x;
//	}
	fill(part, part + n * d, 0);
	for (int i = n * d - 1; i >= 0; i--) {
		int v = vec[i];
	//	cout << "72 " << v << endl;
		if (!part[v]) {
			t++;
			part[v] = t;
			dfsr(v);
		}	
	//	cmp[part[v]].push_back(v);
	//	mask[part[v]] |= b[v] * (1ll << (v / d));
	}
	vec.clear();
	for (int i = 0; i < n * d; i++) {
		cmp[part[i]].push_back(i);
	}
	for (int i = t; i; i--) {
		int cnt = 0;
		for (auto v : cmp[i]) {
			if (!e[v / d] && b[v]) {
				e[v / d] = true;
				cnt++;
			}
			for (auto x : adj[v / d]) {
				int u = (v + 1) % d + d * x;
				dp[i] = max(dp[i], dp[part[u]]);
			}
		}
		dp[i] += cnt;
		for (auto v : cmp[i]) {
			e[v / d] = false;
		}
	}
	cout << dp[part[0]];
	return 0;
}