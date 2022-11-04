#include <bits/stdc++.h>
using namespace std;
namespace {
const int N = 250005;
int n, deg[N], lim, vis[N];
long long dp[N][2];
vector<pair<int, int> > G[N];
vector<int> buckvis[N], buckdel[N];
struct Dat {
	multiset<long long> st;
	long long sum;
	Dat() { sum = 0; }
	void insert(long long x) { st.insert(x); sum += x; }
	void erase(long long x) { st.erase(st.find(x)); sum -= x; }
	long long erase_max() {
		long long x = *--st.end();
		st.erase(--st.end());
		sum -= x;
		return x;
	}
	int size() { return st.size(); }
} tr[N];
void dfs(int u) {
	vis[u] = lim;
	int cur = deg[u] - lim;
	while (tr[u].size() > cur) tr[u].erase_max();
	vector<long long> ch, vd;
	long long sum = 0;
	for (auto &e : G[u]) {
		int v = e.first;
		if (deg[v] <= lim) break;
		if (vis[v] == lim) continue;
		dfs(v);
		dp[v][0] = min(dp[v][0], dp[v][1] + e.second);
		long long val = dp[v][1] + e.second - dp[v][0];
		ch.push_back(val);
		tr[u].insert(val);
		sum += dp[v][0];
	}
	while (tr[u].size() > cur) vd.push_back(tr[u].erase_max());
	dp[u][0] = sum + tr[u].sum;
	while (tr[u].size() > cur - 1) vd.push_back(tr[u].erase_max());
	dp[u][1] = sum + tr[u].sum;
	for (auto &val : vd) tr[u].insert(val);
	for (auto &val : ch) tr[u].erase(val);
}
}
vector<long long> minimum_closure_costs(int _n, vector<int> U, vector<int> V, vector<int> W) {
	n = _n;
	long long SW = 0;
	for (int i = 0; i < n - 1; i++) {
		G[U[i]].emplace_back(V[i], W[i]);
		G[V[i]].emplace_back(U[i], W[i]);
		deg[U[i]]++, deg[V[i]]++;
		SW += W[i];
	}
	for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end(), [](pair<int, int> a, pair<int, int> b) {
			return deg[a.first] > deg[b.first];
		});
		buckdel[deg[i]].push_back(i);
		for (int j = 1; j < deg[i]; j++) buckvis[j].push_back(i);
	}
	vector<long long> ans;
	ans.push_back(SW);
	for (lim = 1; lim < n; lim++) {
		for (int u : buckdel[lim]) {
			for (auto &e : G[u]) {
				int v = e.first;
				if (deg[v] <= deg[u]) break;
				tr[v].insert(e.second);
			}
		}
		long long sum = 0;
		for (int u : buckvis[lim]) if (vis[u] != lim) {
			dfs(u);
			sum += dp[u][0];
		}
		ans.push_back(sum);
	}
	return ans;
}
int main() {
  int N;
  assert(1 == scanf("%d", &N));

  std::vector<int> U(N - 1), V(N - 1), W(N - 1);
  for (int i = 0; i < N - 1; ++i) {
    assert(3 == scanf("%d %d %d", &U[i], &V[i], &W[i]));
  }

  std::vector<long long> closure_costs = minimum_closure_costs(N, U, V, W);
  for (int i = 0; i < static_cast<int>(closure_costs.size()); ++i) {
    if (i > 0) {
      printf(" ");
    }
    printf("%lld",closure_costs[i]);
  }
  printf("\n");
  return 0;
}