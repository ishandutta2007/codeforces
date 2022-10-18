#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)

map<int, int> used;

bool dfs(int v, vector<int> *g, vector<int> &st) {
	used[v] = 1;
	bool res = true;
	for(auto u: g[v]) {
		if(!used[u]) {
			res &= dfs(u, g, st);
		} else {
			res &= used[u] == 2;
		}
	}
	st.push_back(v);
	used[v] = 2;
	return res;
}

void solve() {
	used.clear();
	int n;
	cin >> n;
	int next[n];
	vector<int> g[n + 1];
	vector<int> st;
	for(int i = 0; i < n; i++) {
		cin >> next[i];
		while(!st.empty() && next[st.back()] == i) {
			st.pop_back();
		}
		if(!st.empty()) {
			g[st.back()].push_back(i);
		}
		if(next[i] != -1) {
			next[i]--;
			g[next[i]].push_back(i);
			st.push_back(i);
		}
	}
	vector<int> srt;
	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(!used[i]) {
			ok &= dfs(i, g, srt);
		}
	}
	if(!ok) {
		cout << -1 << endl;
		return;
	}
	int ans[n];
	for(int i = 0; i < n; i++) {
		ans[srt[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] + 1 << ' ';
	}
	cout << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}