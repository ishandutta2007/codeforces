/*input
3 2 1
2 1 0
2 2 2 1
1 0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <tuple>

// .......

using namespace std;

const uint64_t INF = 1ull << 63;

struct AhoCorasick
{
	int n;
	vector<array<int, 2>> go, child;
	vector<int> par, link, terminal;

	AhoCorasick(): n(1), child(n + 1, {0, 0}), par(n + 1, 0), terminal(n + 1, 0) {};

	void addString(vector<int> str)
	{
		int u = 1;
		for (int c : str) {
			if (!child[u][c]) {
				child[u][c] = ++n;
				child.push_back({0, 0});
				par.push_back(u);
				terminal.push_back(false);
			}
			u = child[u][c];
		}
		terminal[u] = true;
	}

	void build()
	{
		go.resize(n + 1);
		link.resize(n + 1);

		queue<int> qu;
		qu.push(1);
		link[1] = 1;
		while (!qu.empty()) {
			int u = qu.front();
			qu.pop();

			if (terminal[link[u]] || terminal[par[u]]) terminal[u] = true;

			go[u][0] = (child[u][0] ? child[u][0] : (u == 1 ? 1 : go[link[u]][0]));
			go[u][1] = (child[u][1] ? child[u][1] : (u == 1 ? 1 : go[link[u]][1]));

			for (int c = 0; c < 2; ++c) if (child[u][c]) {
				int v = child[u][c];
				link[v] = (u == 1 ? 1 : go[link[u]][c]);
				qu.push(v);
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int G, N, M;
	cin >> G >> N >> M;

	vector<tuple<int, int, int>> muts; // mutations ...
	vector<vector<int>> conOf(G);
	vector<uint64_t> ans(G, INF);

	for (int i = 0; i < N; ++i) {
		int a, cnt, x, y, z;
		cin >> a >> cnt >> x;

		if (cnt == 1) {
			conOf[x].push_back((int) muts.size());
			muts.emplace_back(x, -1, a);
			continue;
		}

		for (int j = 1; j < cnt; ++j) {
			cin >> y;

			if (j == cnt - 1) z = a;
			else {
				z = (int) conOf.size();
				conOf.emplace_back();
			}

			conOf[x].push_back((int) muts.size());
			conOf[y].push_back((int) muts.size());
			muts.emplace_back(x, y, z);
			x = z;
		}
	}

	AhoCorasick ac;
	for (int i = 0; i < M; ++i) {
		int cnt;
		cin >> cnt;
		vector<int> str(cnt);
		for (int &x : str) cin >> x;
		ac.addString(str);
	}

	ac.build();
	int S = ac.n, H = (int) conOf.size();
	vector<vector<vector<uint64_t>>> dp(H, vector<vector<uint64_t>>(S + 1, vector<uint64_t>(S + 1, INF)));

	using pq_type = tuple<uint64_t, int, int, int>;
	priority_queue<pq_type, vector<pq_type>, greater<pq_type>> pq;
	for (int u = 1; u <= S; ++u) if (!ac.terminal[u]) {
		for (int k = 0; k < 2; ++k) {
			int v = ac.go[u][k];
			if (!ac.terminal[v]) {
				dp[k][u][v] = 1;
				pq.emplace(1, k, u, v);
			}
		}
	}

	int ansLeft = G - 2;
	while (!pq.empty() && ansLeft > 0) {
		uint64_t dist;
		int u, x, y;
		tie(dist, u, x, y) = pq.top();
		pq.pop();
		if (dist > dp[u][x][y]) continue;
		if (1 < u && u < G && ans[u] > dist) --ansLeft, ans[u] = dist; 

		for (int i : conOf[u]) {
			int w = get<2>(muts[i]);
			int v = u ^ get<0>(muts[i]) ^ get<1>(muts[i]);
			if (v == -1) {
				if (dp[w][x][y] > dist) {
					pq.emplace(dp[w][x][y] = dist, w, x, y);
				}
				continue;
			}

			if (u == get<0>(muts[i])) {
				for (int z = 1; z <= S; ++z) {
					if (dp[u][x][y] + dp[v][y][z] < dp[w][x][z]) {
						pq.emplace(dp[w][x][z] = dp[u][x][y] + dp[v][y][z], w, x, z);
					}
				}
			}

			if (u == get<1>(muts[i])) {
				for (int z = 1; z <= S; ++z) {
					if (dp[v][z][x] + dp[u][x][y] < dp[w][z][y]) {
						pq.emplace(dp[w][z][y] = dp[v][z][x] + dp[u][x][y], w, z, y);
					}
				}
			}
		}
	}

	for (int i = 2; i < G; ++i) {
		if (ans[i] == INF) {
			cout << "YES\n";
		} else {
			cout << "NO " << ans[i] << '\n';
		}
	}
}