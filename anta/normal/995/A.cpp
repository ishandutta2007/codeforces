#include "bits/stdc++.h"
using namespace std;
int main() {
	int n; int K;
	while (~scanf("%d%d", &n, &K)) {
		vector<vector<int> > A(4, vector<int>(n));
		for (int i = 0; i < 4; ++ i) for (int j = 0; j < n; ++ j)
			scanf("%d", &A[i][j]);
		vector<pair<int, int>> cycle;
		for (int i = 0; i < n; ++ i)
			cycle.emplace_back(1, i);
		for (int i = 0; i < n; ++ i)
			cycle.emplace_back(2, n - 1 - i);
		vector<pair<int, pair<int, int>>> ans;
		int rem = K;
		while (rem > 0) {
			for (int k = 0; k < 2; ++ k) for (int i = 0; i < n; ++ i) if (A[k + 1][i] != 0 && A[k == 0 ? 0 : 3][i] == A[k + 1][i]) {
				ans.emplace_back(A[k + 1][i], make_pair(k == 0 ? 0 : 3, i));
				A[k + 1][i] = 0, -- rem;
			}
			auto it = find_if(cycle.begin(), cycle.end(), [&](auto p) { return A[p.first][p.second] == 0; });
			if (it == cycle.end()) break;
			rotate(cycle.begin(), it, cycle.end());
			for (int i = 0; i + 1 != cycle.size(); ++ i) {
				auto q = cycle[i], p = cycle[i + 1];
				int a = A[p.first][p.second];
				if (a != 0) {
					ans.emplace_back(a, q);
					A[p.first][p.second] = 0;
					A[q.first][q.second] = a;
				}
			}
		}
		if (rem != 0) {
			puts("-1");
		} else {
			printf("%d\n", (int)ans.size());
			for (int i = 0; i < (int)ans.size(); ++ i)
				printf("%d %d %d\n", ans[i].first, ans[i].second.first + 1, ans[i].second.second + 1);
		}
	}
}