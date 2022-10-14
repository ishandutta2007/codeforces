#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 100000;

int input[N];
vector <int> adj[N];
int ans = 0, m;

void dfs (int v = 0, int pa = -1, int now = 0) {
	if (input[v]) now++;
	else now = 0;
	if (now > m) return;
	bool is = false;
	for (int u : adj[v]) if (u != pa) {
		is = true;
		dfs(u, v, now);
	}
	if (!is) ans++;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> input[i];
    for (int i = 0; i < n - 1; ++i) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
	}
	dfs();
	cout << ans << endl;
}