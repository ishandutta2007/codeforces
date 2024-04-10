#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <assert.h>
using namespace std;
//#define int long long
int MOD = 1000000007;
class SCC {
public:
	int V, cnt;
	vector<vector<int> > G, rG, graph;
	vector<int> vs, cmp;
	vector<bool> used;
	SCC(int node_size) : V(node_size), G(V), rG(V), cmp(V), used(V, false) {}
	void add_edge(int from, int to) {
		G[from].push_back(to);
		rG[to].push_back(from);
	}
	void dfs(int u) {
		used[u] = true;
		for (int v : G[u]) {
			if (!used[v]) {
				dfs(v);
			}
		}
		vs.push_back(u);
	}
	void dfs(int u, const int k) {
		used[u] = true;
		cmp[u] = k;
		for (int v : rG[u]) {
			if (!used[v]) {
				dfs(v, k);
			}
		}
	}
	int solve() { //
		for (int i = 0; i < V; i++) {
			if (!used[i]) {
				dfs(i);
			}
		}
		fill(used.begin(), used.end(), false);
		cnt = 0;
		for (int i = V - 1; i >= 0; i--) {
			if (!used[vs[i]]) {
				dfs(vs[i], cnt++);
			}
		}
		return cnt;
	}
	void make_graph() {
		graph.resize(cnt);
		for (int i = 0; i < V; i++) {
			for (int v : G[i]) {
				if (cmp[i] < cmp[v]) {
					graph[cmp[i]].push_back(cmp[v]);
				}
				else if (cmp[i] > cmp[v]) {
					assert(false);
				}
			}
		}
	}
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, D;
	cin >> N >> M >> D;
	static SCC scc(N * D);
	int a, b;
	vector<string> S(N);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--; b--;
		for (int j = 0; j < D - 1; j++) {
			scc.add_edge(a * D + j, b * D + j + 1);
		}
		{
			scc.add_edge(a * D + D - 1, b * D);
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	int K = scc.solve();
	scc.make_graph();


	vector<int> score(K, 0); 


	{
		vector<int> X(K, -1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < D; j++) {
				if (S[i][j] == '1') {
					int idx = i * D + j;
					if (X[scc.cmp[idx]] != i) {
						X[scc.cmp[idx]]= i;
						score[scc.cmp[idx]]++;
					}
				}
			}
		}
	}


	int start = scc.cmp[0];
	//cerr << K << endl;
	//cerr << score[start] << endl;

	vector<int> dp(K, -((int)1e9));
	dp[start] = score[start];
	int res = dp[start];
	for (int i = start; i < K; i++) {
		res = max(res, dp[i]);
		if (dp[i] >= 0) {
			for (int j : scc.graph[i]) {
				
				dp[j] = max(dp[j], dp[i] + score[j]);
			}
		}
	}

	cout << res << endl;
}