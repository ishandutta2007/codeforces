#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 200 * 1000 + 5, LG = 20;
int t = 0;
bool b = true;


int part[N];
int pt[N];
int jump[N];
bool mark[N];
int h[N];
int h2[N];
vector <pair <int, int> > adj1[N];
vector <int> cmp[N];
stack <int> st;
vector <int> adj2[N];
vector <pair <int, int> > adj3[N];
int dp[N][LG];
int r[N][3];


void dfs1(int v, int pr = -1) {
	mark[v] = true;
	jump[v] = h[v];
	st.push(v);
	for (auto p : adj1[v]) {
		int u = p.first;
		if (!mark[u]) {
			pt[u] = pt[v];
			h[u] = h[v] + 1;
			dfs1(u, p.second);
			jump[v] = min(jump[v], jump[u]);
		}
		if (p.second != pr) {
			jump[v] = min(jump[v], h[u]);
		}
	}
	if (jump[v] == h[v]) {
		t++;
		while (st.top() != v) {
			part[st.top()] = t;
			cmp[t].push_back(st.top());
			st.pop();
		}
		st.pop();
		part[v] = t;
		cmp[t].push_back(v);
	}
}
void dfs2(int v) {
	mark[v] = true;
	for (auto u : adj2[v]) {
		if (u != dp[v][0]) {
			dp[u][0] = v;
			h2[u] = h2[v] + 1;
			dfs2(u);
		}
	}
}
void dfs3(int v) {
	mark[v] = true;
//	cout << "39 " << v << endl;
	r[v][0] = r[v][1] = h2[v];
	for (auto u : adj2[v]) {
		if (u != dp[v][0]) {
			dfs3(u);
			r[v][0] = min(r[v][0], r[u][0]);
			r[v][1] = min(r[v][1], r[u][1]);
		}
	}
	for (auto p : adj3[v]) {
		r[v][p.second] = min(r[v][p.second], h2[p.first]);
	}
	if (r[v][0] < h2[v] && r[v][1] < h2[v]) {
		b = false;
	}
}
int lca(int u, int v) {
	if (h2[u] > h2[v]) {
		swap(u, v);
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (h2[v] >= h2[u] + (1 << i)) {
			v = dp[v][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[v][0];
}
int main() {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj1[u].push_back({v, i});
		adj1[v].push_back({u, i});
	}
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			pt[i] = i;
			dfs1(i);
		}
	}
/*	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			cout << "No";
			return 0;
		}
	}*/
	for (int i = 1; i <= n; i++) {
		for (auto p : adj1[i]) {
			int u = p.first;
			if (part[u] != part[i]) {
				adj2[part[i]].push_back(part[u]);
			}
		}
	}
//	for (int i = 1; i <= t; i++) {
//		cout << part[i] << " ";
//	}
//	cout << endl;
//	cout << "48 " << t << endl;
	fill(mark, mark + n + 1, false);
	for (int i = 1; i <= t; i++) {
		
		if (!mark[i]) {
			dp[i][0] = i;
			dfs2(i);
		}
	}
//	for (int i = 1; i <= t; i++) {
//		cout << h2[i] << " ";
//	}
	for (int j = 1; j < LG; j++) {
		for (int i = 1; i <= t; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= q; i++) {
		int s, t;
		cin >> s >> t;
		if (pt[s] != pt[t]) {
			cout << "No";
			return 0;
		}
		s = part[s], t = part[t];
		int v = lca(s, t);
		adj3[s].push_back({v, 0});
	//	cout << s << " " << v << " " << t << endl;
		adj3[t].push_back({v, 1});
	}
	fill(mark, mark + n + 1, false);
//	for (int i = 1; i <= t; i++) {
	//	cout << dp[i][0] << endl;
//	}
	for (int i = 1; i <= t; i++) {
		
		if (!mark[i]) {
			dfs3(i);
		}
	}
//	for (int i = 1; i <= t; i++) {
	//	cout << i << " " << r[i][0] << " " << r[i][1] << endl;
//	}
	if (b) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}