#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n;
	cin >> n;
	set<pair<int, int>> leafs;
	set<int> g[n];
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].insert(y);
		g[y].insert(x);
	}
	for(int i = 0; i < n; i++) {
		leafs.insert({g[i].size(), i});
	}
	while(leafs.size() > 1) {
		auto A = begin(leafs)->second;
		leafs.erase(begin(leafs));
		auto B = begin(leafs)->second;
		leafs.erase(begin(leafs));
		cout << "? " << A + 1 << ' ' << B + 1 << endl;
		int C;
		cin >> C;
		if(C == A + 1 || C == B + 1) {
			cout << "! " << C << endl;
			return;
		} else {
			int a = *begin(g[A]);
			int b = *begin(g[B]);
			leafs.erase({g[a].size(), a});
			leafs.erase({g[b].size(), b});
			g[*begin(g[A])].erase(A);
			g[*begin(g[B])].erase(B);
			leafs.insert({g[a].size(), a});
			leafs.insert({g[b].size(), b});
		}
	}
	cout << "! " << begin(leafs)->second + 1 << endl;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}