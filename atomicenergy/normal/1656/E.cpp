#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int > > g;
vector<bool> as;
void dfs(int v, int p, bool b) {
	as[v] = b;
	for (auto u : g[v]) {
		if (u == p) continue;
		dfs(u, v, !b);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		g = vector<vector<int > >(n);
		as = vector<bool>(n);
		for (int i = 0; i < n-1; i++) {
			int a;
			int b;
			cin >> a >> b;
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}
		dfs(0, -1, true);
		for (int i = 0; i < n; i++) {
	
			cout << (as[i] ? 1 : -1) * ((int) g[i].size()) << " ";
		}
		cout << endl;
		
	}
}