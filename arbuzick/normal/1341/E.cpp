#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> d(m);
	for (int i = 0; i < m; ++i)
		cin >> d[i];
	sort(d.begin(), d.end());
	int g, r;
	cin >> g >> r;
	vector<vector<int>> dist(m, vector<int>(g + 1)), used(m, vector<int>(g + 1));
	dist[0][0] = 0;
	used[0][0] = 1;
	deque<pair<int, int>> deq;
	deq.push_back({ 0, 0 });
	int ans = -1;
	while (!deq.empty()) {
		int v = deq.front().first, t = deq.front().second;
		deq.pop_front();
		if (t == 0) {
			if (d[m - 1] - d[v] <= g) {
				if (ans == -1 || ans > (r + g) * dist[v][t] + d[m - 1] - d[v])
					ans = (r + g) * dist[v][t] + d[m - 1] - d[v];
			}
		}
		if (t == g) {
			if (!used[v][0]) {
				dist[v][0] = dist[v][t]+1;
				used[v][0] = 1;
				deq.push_back({ v, 0 });
			}
		}
		if (v > 0) {
			int t2 = t + d[v] - d[v - 1];
			if (t2 <= g && used[v - 1][t2] == 0) {
				used[v - 1][t2] = 1;
				dist[v - 1][t2] = dist[v][t];
				deq.push_front({ v - 1, t2 });
			}
		}
		if (v < m - 1) {
			int t2 = t + d[v + 1] - d[v];
			if (t2 <= g && used[v + 1][t2] == 0) {
				used[v + 1][t2] = 1;
				dist[v + 1][t2] = dist[v][t];
				deq.push_front({ v + 1, t2 });
			}
		}
	}
	cout << ans << endl;
	return 0;
}