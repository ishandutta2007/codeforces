#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<string> t1;
vector<int> used;
void dfs(int v, int c) {
	used[v] = c;
	for (auto u : a[v])
		if (used[u] == -1)
			dfs(u, c);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	a.resize(n * m);
	t1.resize(n);
	used.resize(n * m);
	for (int i = 0; i < n; ++i)
		cin >> t1[i];
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			used[i * m + j] = -1;
			if (i != 0 && t1[i - 1][j] == t1[i][j]) {
				a[i * m + j].push_back((i - 1) * m + j);
				a[(i - 1) * m + j].push_back(i * m + j);
			}
			if (i != n-1 && t1[i + 1][j] == t1[i][j]) {
				a[i * m + j].push_back((i + 1) * m + j);
				a[(i + 1) * m + j].push_back(i * m + j);
			}
			if (j != 0 && t1[i][j-1] == t1[i][j]) {
				a[i * m + j].push_back(i * m + j - 1);
				a[i * m + j - 1].push_back(i * m + j);
			}
			if (j != m-1 && t1[i][j + 1] == t1[i][j]) {
				a[i * m + j].push_back(i * m + j + 1);
				a[i * m + j + 1].push_back(i * m + j);
			}
		}
	int c = 0;
	for(int v = 0; v < n*m; ++v)
		if (used[v] == -1) {
			dfs(v, c);
			c += 1;
		}
	vector<pair<int, int>> s(c);
	for (int v = 0; v < n * m; ++v) {
		s[used[v]].first += 1;
		s[used[v]].second = t1[v / m][v & m] - '0';
	}
	vector<pair<int, int>> dist(n * m);
	queue<int> q;
	for (int v = 0; v < n * m; ++v) {
		if (s[used[v]].first > 1) {
			dist[v] = { 0, used[v] };
			q.push(v);
		}
		else
			dist[v] = { -1, -1 };
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (v / m != 0) 
			if (dist[(v / m - 1) * m + v % m].first == -1) {
				dist[(v / m - 1) * m + v % m].first = dist[v].first + 1;
				dist[(v / m - 1) * m + v % m].second = dist[v].second;
				q.push((v / m - 1) * m + v % m);
			}
		if (v / m != n-1)
			if (dist[(v / m + 1) * m + v % m].first == -1) {
				dist[(v / m + 1) * m + v % m].first = dist[v].first + 1;
				dist[(v / m + 1) * m + v % m].second = dist[v].second;
				q.push((v / m + 1) * m + v % m);
			}
		if (v % m != 0)
			if (dist[v / m * m + v % m - 1].first == -1) {
				dist[v / m * m + v % m - 1].first = dist[v].first + 1;
				dist[v / m * m + v % m - 1].second = dist[v].second;
				q.push(v / m * m + v % m - 1);
			}
		if (v % m != m-1)
			if (dist[v / m * m + v % m + 1].first == -1) {
				dist[v / m * m + v % m + 1].first = dist[v].first + 1;
				dist[v / m * m + v % m + 1].second = dist[v].second;
				q.push(v / m * m + v % m + 1);
			}
	}
	for (int i = 0; i < t; ++i) {
		long long i1, j, p;
		cin >> i1 >> j >> p;
		int v = (i1 - 1) * m + j - 1;
		if (dist[v].first == -1||p < dist[v].first) {
			cout << t1[i1 - 1][j - 1] - '0' << "\n";
		}
		else {
			p -= dist[v].first;
			long long c1 = t1[i1 - 1][j - 1] - '0';
			c1 += p;
			c1 %= 2;
			cout << c1 << "\n";
		}
	}
	return 0;
}