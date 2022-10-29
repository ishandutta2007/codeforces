#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<bool> used;
vector<int> order;
vector<vector<int>> g, gr;

int cnt = 0;
void dfs1(int v) {
	used[v] = true;
	for (auto to : g[v])
		if (!used[to])
			dfs1(to);
	order.push_back(v);
}

vector<int> comp;

void dfs(int v) {
	used[v] = true;
	comp[v] = cnt;
	for (auto to : gr[v])
		if (!used[to])
			dfs(to);
}
int main() {
	int n, m, h;
	cin >> n >> m >> h;
	g.resize(n); gr.resize(n);
	used.assign(n, false);
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i) {
		int v, u;
		cin >> v >> u;
		v--; u--;
		if (a[v] + 1 == a[u] || a[v] + 1 == a[u] + h)
			g[v].push_back(u), gr[u].push_back(v);
		if (a[u] + 1 == a[v] || a[u] + 1 == a[v] + h)
			g[u].push_back(v), gr[v].push_back(u);
	}
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i);
	reverse(order.begin(), order.end());
	vector<int> minc;
	comp.resize(n);
	used.assign(n, false);
	for (int i = 0; i < n; ++i) {
		int v = order[i];
		if (!used[v]) {
			dfs(v);
			cnt++;
		}
	}
	vector<int> sum(cnt);
	vector<bool> t(cnt, true);
	for (int i = 0; i < n; ++i) {
		sum[comp[i]]++;
		for (auto to : g[i])
			if (comp[i] != comp[to]) {
				t[comp[i]] = false;
				break;
			}
	}
	int min = -1;
	for (int i = 0; i < cnt; ++i)
		if (t[i] && (min == -1 || sum[i] < sum[min]))
			min = i;
	cout << sum[min] << '\n';
	for (int i = 0; i < n; ++i)
		if (comp[i] == min)
			cout << i + 1 << ' ';
	n = n;
	return 0;
}