#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool dfs(int v, vector<vector<pair<int, int>>>& g, vector<int>& was, int par) {
	was[v] = par;
	for (auto& e : g[v]) {
		if (e.second == 1) {
			if (was[e.first] == -1) {
				if (!dfs(e.first, g, was, !par)) {
					return false;
				}
			}
			else {
				if (was[e.first] == par) {
					return false;
				}
			}
		}
		else {
			if (was[e.first] == -1) {
				if (!dfs(e.first, g, was, par)) {
					return false;
				}
			}
			else {
				if (was[e.first] != par) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	//ifstream cin("in.txt");
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	int n = s.size();
	const int mod = 998244353;
	int ans = 0;
	for (int m = 1; m < n; m++) {
		vector<vector<pair<int, int>>> g(n + m + 2);
		for (int i = 0; i < n / 2; i++) {
			g[i].push_back({ n - 1 - i, 0 });
			g[n - 1 - i].push_back({ i, 0 });
		}
		for (int i = 0; i < m / 2; i++) {
			g[i + n].push_back({ m - 1 - i + n, 0 });
			g[m - 1 - i + n].push_back({ i + n, 0 });
		}
		for (int i = 0; i < m; i++) {
			if (s[i] == '1') {
				g[i].push_back({ i + n, 1 });
				g[i + n].push_back({ i, 1 });
			}
			else if (s[i] == '0') {
				g[i].push_back({ i + n, 0 });
				g[i + n].push_back({ i, 0 });
			}
		}
		for (int i = m; i < n; i++) {
			if (s[i] == '0') {
				g[i].push_back({ n + m, 0 });
				g[n + m].push_back({ i, 0 });
			}
			else if (s[i] == '1') {
				g[i].push_back({ n + m + 1, 0 });
				g[n + m + 1].push_back({ i, 0 });
			}
		}
		g[n + m].push_back({ n + m + 1, 1 });
		g[n + m + 1].push_back({ n + m, 1 });
		g[m - 1 + n].push_back({ n + m + 1, 0 });
		g[n + m + 1].push_back({ m - 1 + n, 0 });
		vector<int> was(n + m + 2, -1);
		int comp = 0;
		bool okok = true;
		for (int i = 0; i < n + m + 2 && okok; i++) {
			if (was[i] == -1) {
				comp++;
				okok &= dfs(i, g, was, 0);
			}
		}
		if (okok) {
			int add = 1;
			for (int i = 0; i < comp - 1; i++) {
				add = (add + add) % mod;
			}
			ans = (ans + add) % mod;
		}
	}
	cout << ans;
}