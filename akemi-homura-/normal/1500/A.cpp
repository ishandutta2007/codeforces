#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int V = 2500005;
int n, a[N];
vector<int> vec[V];
vector<pair<int, int> > mp[V * 2];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		vec[a[i]].push_back(i);
		if (vec[a[i]].size() >= 4) {
			puts("YES");
			for (int j = 0; j < 4; j++) printf("%d ", vec[a[i]][j]);
			return 0;
		}
	}
	vector<int> stk;
	for (int i = 1; i < V; i++) {
		if (vec[i].size() >= 2) stk.push_back(i);
		if (stk.size() >= 2) {
			puts("YES");
			printf("%d %d %d %d ", vec[stk[0]][0], vec[stk[1]][0], vec[stk[0]][1], vec[stk[1]][1]);
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int s = a[i] + a[j];
			for (auto &P : mp[s]) {
				if (P.first != i && P.second != i && P.first != j && P.second != j) {
					puts("YES");
					printf("%d %d %d %d\n", P.first, P.second, i, j);
					return 0;
				}
			}
			mp[s].emplace_back(i, j);
		}
	}
	puts("NO");
	return 0;
}