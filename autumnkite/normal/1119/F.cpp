#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int n;
    std::cin >> n;
    std::vector<int> U(n - 1), V(n - 1), W(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> U[i] >> V[i] >> W[i];
        --U[i], --V[i];
    }
    std::vector<int> deg(n);
	for (int i = 0; i < n - 1; ++i) {
		++deg[U[i]], ++deg[V[i]];
	}
	std::vector<std::vector<int>> id(n), gid(n);
	for (int i = 0; i < n; ++i) {
		id[deg[i]].push_back(i);
		for (int j = 0; j < deg[i]; ++j) {
			gid[j].push_back(i);
		}
	}
	std::vector<std::vector<std::tuple<int, int, int>>> edge(n);
	std::vector<std::vector<std::pair<int, int>>> G(n);
	for (int i = 0; i < n - 1; ++i) {
		int d = std::min(deg[U[i]], deg[V[i]]);
		for (int j = 0; j < d; ++j) {
			edge[j].emplace_back(U[i], V[i], W[i]);
		}
		G[U[i]].emplace_back(V[i], W[i]);
		G[V[i]].emplace_back(U[i], W[i]);
	}
	std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> Q(n);
	std::vector<std::priority_queue<int>> R(n);
	std::vector<int> vis(n);
	std::vector<long long> sum(n);
	std::vector<long long> f0(n), f1(n);
	std::vector<long long> ans(n);
	for (int i = 0; i < n - 1; ++i) {
		ans[0] += W[i];
	}
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int k = 1; k < n; ++k) {
		for (int u : gid[k]) {
			if (!R[u].empty()) {
				Q[u].push(R[u].top());
				sum[u] -= R[u].top();
				R[u].pop();
			}
		}
		for (int u : id[k]) {
			for (auto [v, w] : G[u]) {
				if (deg[v] > k) {
					if ((int)Q[v].size() < k || w > Q[v].top()) {
						Q[v].push(w);
						if ((int)Q[v].size() > k) {
							R[v].push(Q[v].top());
							sum[v] += Q[v].top();
							Q[v].pop();
						}
					} else {
						R[v].push(w);
						sum[v] += w;
					}
				}
			}
		}
		for (auto [u, v, w] : edge[k]) {
			E[u].emplace_back(v, w);
			E[v].emplace_back(u, w);
		}
		std::function<void(int, int)> dfs = [&](int u, int fa) {
			vis[u] = k;
			long long res = sum[u];
			std::vector<long long> val;
			for (auto [v, w] : E[u]) {
				if (v != fa) {
					dfs(v, u);
					res += f1[v] + w;
					val.push_back(f0[v] - f1[v] - w);
				}
			}
			std::sort(val.begin(), val.end());
			std::vector<long long> tmp;
			f1[u] = res;
			f0[u] = 0x3f3f3f3f3f3f3f3fll;
			for (int i = 0; i <= (int)val.size() && i < k; ++i) {
				while ((int)Q[u].size() + i >= k) {
					res += Q[u].top();
					tmp.push_back(Q[u].top());
					Q[u].pop();
				}
				f0[u] = std::min(f0[u], res);
				if (i == (int)val.size()) {
					break;
				}
				res += val[i];
				f1[u] = std::min(f1[u], res);
			}
			for (int v : tmp) {
				Q[u].push(v);
			}
		};
		ans[k] = 0;
		for (int u : gid[k]) {
			if (vis[u] != k) {
				dfs(u, -1);
				ans[k] += f1[u];
			}
		}
		for (int u : gid[k]) {
			E[u].clear();
		}
	}
	for (int i = 0; i < n; ++i) {
	    std::cout << ans[i] << " ";
	}
	std::cout << "\n";
}