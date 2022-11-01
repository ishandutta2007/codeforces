#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5, N2 = N * 2 + 5;
int t = 0;

int ans[N2];
bool mark[N2];
vector <pair <int, int> > adj[N2];
vector <int> tr;

void tur(int v) {
	while (adj[v].size()) {
		int u = adj[v].back().first, id = adj[v].back().second;
		adj[v].pop_back();
		if (!mark[id]) {
			mark[id] = true;
			tur(u);
			tr.push_back(id);
			t++;
			if (t % 2) {
				ans[id] = 1;
			}
			else {
				ans[id] = 2;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int m = n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		y += N;
		adj[x].push_back({y, i});
		adj[y].push_back({x, i});
	}
	for (int i = 1; i < N; i++) {
		if (adj[i].size() % 2 == 1) {
			n++;
			adj[N * 2].push_back({i, n});
			adj[i].push_back({N * 2, n});
		}
	}
	for (int i = N + 1; i <= N * 2; i++) {
		if (adj[i].size() % 2 == 1) {
			n++;
			adj[N].push_back({i, n});
			adj[i].push_back({N, n});
		}
	}
	for (int i = 1; i <= N * 2; i++) {
		tur(i);
	}
	for (int i = 1; i <= m; i++) {
		if (ans[i] == 1) {
			cout << 'r';
		}
		else {
			cout << 'b';
		}
	}
	return 0;
}