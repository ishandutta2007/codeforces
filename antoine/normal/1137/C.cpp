#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <bitset>
#include <set>
#include <functional>
#include <cstring>
#include <assert.h>

using namespace std;
typedef long long ll;

const int MxN = (int) 1e5 + 9;
const int MxD = 50;

int n, D;
bitset<MxD> open[MxN + 9];
vector<int> adj[MxN * MxD + 9];
int comp[MxN * MxD + 9];
int dp[MxN * MxD + 9];
int low[MxN * MxD + 9];
int disc[MxN * MxD + 9];
static int t = 0;
static int numComps = 0;
static stack<int> st;

void dfsSCC(const int x) {

	low[x] = disc[x] = t++; // [!] 3 in 1
	st.push(x);

	for (int i = 0; i < (int) adj[x / D].size(); ++i) {
		const int v = adj[x / D][i];
		const int y = v * D + (x + 1) % D;
		if (disc[y] == -1) {
			dfsSCC(y);
			low[x] = min(low[x], low[y]);
		} else if (comp[y] == -1)
			low[x] = min(low[x], disc[y]);
	}

	if (low[x] == disc[x]) {
		comp[x] = numComps++;
		while (st.top() != x) {
			comp[st.top()] = comp[x];
			st.pop();
		}
		st.pop();
	}
}

void dfsSCC() {
	memset(low, -1, sizeof low);
	memset(disc, -1, sizeof disc);
	memset(comp, -1, sizeof comp);
	dfsSCC(0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int m;
	cin >> n >> m >> D;

	vector<pair<int, int>> edges(m);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		edges[i] = {u, v};
	}

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < D; ++j)
			if (s[j] == '1')
				open[i][j] = 1;
	}

	dfsSCC();

	static vector<int> compNodes[MxN * MxD + 9];

	for (int x = 0; x < n * D; ++x) {
		if (comp[x] == -1)
			continue;
		const int u = x / D;
		const int d = x % D;
		if (!open[u][d])
			continue;
		compNodes[comp[x]].push_back(u);
	}

	for (int i = 0; i < n * D; ++i) {
		vector<int> &v = compNodes[i];
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	fill(begin(adj), end(adj), vector<int>());

	for (const pair<int, int> &edge : edges) {
		const int u = edge.first;
		const int v = edge.second;
		for (int d = 0; d < D; ++d) {
			const int x = u * D + d;
			const int y = v * D + (d + 1) % D;
			if (comp[x] != comp[y])
				adj[comp[x]].push_back(comp[y]);
		}
	}

	for (int i = 0; i < n * D; ++i) {
		sort(adj[i].begin(), adj[i].end());
		adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
	}

	// memset(dp, -1, sizeof dp);

	for (int i = 0; i <= comp[0]; ++i) {
		int &res = dp[i] = 0;
		for (const int &x : adj[i]) {
			assert(x < i);
			res = max(res, dp[x]);
		}
		res += (int) compNodes[i].size();
	}

	cout << dp[comp[0]];

	return 0;
}