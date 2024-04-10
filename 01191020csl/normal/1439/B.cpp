#include<bits/stdc++.h>
using namespace std;
vector<int> edge[100001];
vector<int> clique[100001], work[100001];
int deg[100001], vis[100001], ans[100001], cnt;
int e[100001];
void check(int x) {
	++cnt;
	for (int i : edge[x])
		if (!vis[i]) clique[cnt].push_back(i);
	clique[cnt].push_back(x);
	for (int i : clique[cnt]) work[i].push_back(cnt);
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v), edge[v].push_back(u);
			++deg[u], ++deg[v];
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
			if (deg[i] < k-1) q.push(i);
		set<int> s0;
		for (int i = 1; i <= n; i++) s0.insert(i);
		bool tmp = 0;
		while (!tmp && s0.size()) {
			while (q.size()) {
				int u = q.front();
				s0.erase(u);
				q.pop(), vis[u] = 1;
				for (int i : edge[u])
					if (!vis[i]) {
						--deg[i];
						if (deg[i] == k-2) q.push(i);
					}
			}
			tmp = 1;
			for (int i : s0)
				if (deg[i] == k-1) {
					tmp = 0, check(i), q.push(i);
					break;
				}
		}
		bool flag = 0;
		if (s0.size()) {
			flag = 1;
			cout << 1 << ' ' << s0.size() << endl;
			for (int i : s0) cout << i << ' ';
			cout << endl;
		}
		else {
			for (int i = 1; i <= n; i++) {
				for (int j : edge[i]) e[j] = 1;
				for (int j : work[i])
					for (int x : clique[j])
						if (e[x]) ++ans[j];
				for (int j : edge[i]) e[j] = 0;
			}
			for (int i = 1; i <= cnt; i++)
				if (ans[i] == 1ll*k*(k-1)) {
					cout << 2 << endl;
					for (int j : clique[i]) cout << j << ' ';
					cout << endl, flag = 1;
					break;
				}
			if (!flag) puts("-1");
		}
		for (int i = 1; i <= n; i++) edge[i].clear(), deg[i] = vis[i] = 0, work[i].clear();
		for (int i = 1; i <= cnt; i++) clique[i].clear(), ans[i] = 0;
		cnt = 0;
	}
}