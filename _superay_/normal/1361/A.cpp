#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, m, eu[N], ev[N], t[N], id[N], nt[N];
vector<int> G[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &eu[i], &ev[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]), id[i] = i;
	for (int i = 1; i <= m; i++) {
		if (t[eu[i]] == t[ev[i]]) {
			puts("-1");
			return 0;
		}
		G[eu[i]].push_back(ev[i]);
		G[ev[i]].push_back(eu[i]);
	}
	sort(id + 1, id + 1 + n, [](int i, int j) {
		return t[i] < t[j];
	});
	for (int _ = 1; _ <= n; _++) {
		int u = id[_];
		vector<int> vec;
		for (int v : G[u]) if (nt[v]) {
			vec.push_back(nt[v]);
		}
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
		int flag = -1;
		for (int i = 0; i < (int)vec.size(); i++) {
			if (vec[i] != i + 1) {
				flag = i + 1;
				break;
			}
		}
		if (flag == -1) {
			flag = vec.size() + 1;
		}
		nt[u] = flag;
		if (nt[u] != t[u]) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", id[i]);
	return 0;
}