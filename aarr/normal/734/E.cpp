#include <iostream>
#include <vector>
#include <deque>
using namespace std;


const int N = 200 * 1000 + 5;
int n;

int c[N], d[N];
bool mark[N];
vector <pair <int, int> > adj[N];

pair <int, int> bfs(int v) {
	int cnt = 0;
	fill(d, d + n + 1, N);
	fill(mark, mark + n + 1, false);
	d[v] = 0;
	deque <int> q;
	q.push_front(v);
	while (q.size()) {
		int v = q.front();
		q.pop_front();
		if (!mark[v]) {
			mark[v] = true;
			cnt++;
		//	cout << "73 " << v << " " << d[v] << endl;
			if (cnt == n) {
				return {v, d[v]};
			}
			for (auto p : adj[v]) {
				int u = p.first, w = p.second;
				if (d[v] + w < d[u]) {
					d[u] = d[v] + w;
					if (w) {
						q.push_back(u);
					}
					else {
						q.push_front(u);
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		if (c[u] ^ c[v]) {
			adj[u].push_back({v, 1});
			adj[v].push_back({u, 1});
		}
		else {
			adj[v].push_back({u, 0});
			adj[u].push_back({v, 0});
		}
	}
	int v = bfs(1).first;
//	cout << v << endl;
	int ans = bfs(v).second;
	cout << (ans + 1) / 2;
	return 0;
}