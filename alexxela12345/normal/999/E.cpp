#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n, m, s;
vector<int> g[N];
bool used[N];
bool ok[N];

int cnt;

void dfs1(int v) {
	ok[v] = true;
	for (auto to : g[v])
		if (!ok[to])
			dfs1(to);
}

void dfs2(int v) {
	used[v] = true;
	++cnt;
	for (auto to : g[v])
		if (!used[to] && !ok[to])
			dfs2(to);
}

int main() {
	cin >> n >> m >> s;
	--s;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
	}
	dfs1(s);
	vector<pair<int, int>> val;
	for (int i = 0; i < n; ++i) {
		if (!ok[i]) {
			cnt = 0;
			memset(used, false, sizeof(used));
			dfs2(i);
			val.push_back(make_pair(cnt, i));
		}
	}
	sort(val.begin(), val.end());
	reverse(val.begin(), val.end());
	int ans = 0;
	for (auto it : val) {
		if (!ok[it.second]) {
			++ans;
			dfs1(it.second);
		}
	}
	cout << ans << endl;
	return 0;
}