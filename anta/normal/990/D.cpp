#include "bits/stdc++.h"
using namespace std;

int main() {
	int n; int a; int b;
	while (~scanf("%d%d%d", &n, &a, &b)) {
		bool swapped = false;
		if (a < b) {
			swap(a, b);
			swapped = true;
		}
		bool ok;
		vector<pair<int, int>> edges;
		if (a > n) {
			ok = false;
		} else if (b == 1) {
			if ((n == 2 || n == 3) && a == 1) {
				ok = false;
			} else {
				ok = true;
				for (int i = 0; i < n - a; ++ i)
					edges.emplace_back(i, i + 1);
			}
		} else {
			ok = false;
		}
		puts(ok ? "YES" : "NO");
		if (ok) {
			vector<string> ans(n, string(n, '0'));
			for (auto e : edges)
				ans[e.first][e.second] = ans[e.second][e.first] = '1';
			if (swapped) {
				for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) if (i != j)
					ans[i][j] = ans[i][j] ^ 1;
			}
			for (int i = 0; i < n; ++ i)
				puts(ans[i].c_str());
		}
	}
}