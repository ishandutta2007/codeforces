#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1000;

int n;
vector<int> g[maxn];

void dfs(int v) {
	int cnt = 0;
	for(int to : g[v]) {
		cnt += g[to].empty();
		dfs(to);
	}
	if(!g[v].empty() && cnt < 3) {
		cout << "No";
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int p; cin >> p; p--;
		g[p].push_back(i + 1);
	}
	dfs(0);
	cout << "Yes";
}