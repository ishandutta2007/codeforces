#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e5 + 5;

#define pii pair<int, int>

int n, m;
int ans[N];
vector<int> V;
int L[N], R[N];
boolean vis[N];
vector<pii> G[N];

vector<int> E;
void dfs(int p) {
	while (!G[p].empty()) {
		pii par = G[p].back();
		G[p].pop_back();
		if (!vis[par.second >> 1]) {
			vis[par.second >> 1] = true;
			dfs(par.first);
			E.push_back(par.second);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", L + i, R + i);
		++R[i];
		V.push_back(L[i]);
		V.push_back(R[i]);
	}
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	for (int i = 1; i <= n; i++) {
		L[i] = lower_bound(V.begin(), V.end(), L[i]) - V.begin() + 1;
		R[i] = lower_bound(V.begin(), V.end(), R[i]) - V.begin() + 1;
		G[L[i]].emplace_back(R[i], i << 1);
		G[R[i]].emplace_back(L[i], i << 1 | 1);
	}
	m = V.size();
	int ls = 0, c = n;
	for (int i = 1; i <= m; i++) {
		if (G[i].size() & 1) {
			if (ls) {
				++c;
				G[ls].emplace_back(i, c << 1);
				G[i].emplace_back(ls, c << 1 | 1);
				ls = 0;
			} else{
				ls = i;
			}
		}
	}
	for (int i = 1; i <= (signed) V.size(); i++) {
		dfs(i);
	}
	for (auto id : E) {
		if ((id >> 1) <= n) {
			ans[id >> 1] = id & 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}