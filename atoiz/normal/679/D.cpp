#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <iomanip>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)

const int MAXN = 402;
int N, M, dist[MAXN][MAXN];
vector<int> G[MAXN];
double prob_at[MAXN], max_prob_dist[MAXN];
bool flag[MAXN];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	FOR(i, 1, N) FOR(j, 1, N) dist[i][j] = N + 1;
	FOR(i, 1, N) dist[i][i] = 0;
	FOR(j, 1, M) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		dist[u][v] = dist[v][u] = 1;
	}
	FOR(k, 1, N) FOR(i, 1, N) FOR(j, 1, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	double opt_prob = 0;

	FOR(c0, 1, N) {
		double opt_prob_c0 = 0;
		FOR(d, 0, N) {
			int cnt_d = 0;
			FOR(v, 1, N) prob_at[v] = 0;

			FOR(u, 1, N) if (dist[c0][u] == d) {
				++cnt_d;
				double single_prob = 1.0 / G[u].size();
				for (int v : G[u]) prob_at[v] += single_prob;
			}
			if (cnt_d == 0) continue;

			vector<int> adj;
			FOR(v, 1, N) if (prob_at[v] > 0) adj.push_back(v);

			double opt_prob_c0_d = 1.0; // var = true_val * cnt_d
			FOR(c1, 1, N) {
				double opt_prob_c0_d_c1 = 0;
				for (int v : adj) max_prob_dist[dist[c1][v]] = 0, flag[dist[c1][v]] = 1;
				for (int v : adj) max_prob_dist[dist[c1][v]] = max(max_prob_dist[dist[c1][v]], prob_at[v]);
				for (int v : adj) if (flag[dist[c1][v]]) {
					opt_prob_c0_d_c1 += max_prob_dist[dist[c1][v]];
					flag[dist[c1][v]] = 0;
				}

				opt_prob_c0_d = max(opt_prob_c0_d, opt_prob_c0_d_c1);
			}

			opt_prob_c0 += opt_prob_c0_d;
		}
		opt_prob_c0 /= N;
		opt_prob = max(opt_prob, opt_prob_c0);
	}
	cout << fixed << setprecision(9) << opt_prob << endl;
}