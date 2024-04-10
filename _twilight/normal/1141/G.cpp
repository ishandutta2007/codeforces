#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define pii pair<int, int>

const int N = 2e5 + 5;

int n, m;
int c[N];
vector<pii> D;
vector<pii> G[N];
boolean vis[N], invalid[N];

void dfs(int p, int fa, int fcol) {
	int e, id, cur = (fcol == 1) + 1;
	for (auto &par : G[p]) {
		e = par.first, id = par.second;
		if (!invalid[p] && !c[id]) {
			c[id] = cur++;
		}
		if (e == fa) {
			continue;
		}
		dfs(e, p, c[id]);
		cur += (cur == fcol);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	D.resize(n, pii(0, 0));
	for (int i = 0; i < n; i++) {
		D[i].second = i + 1;
	}
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		G[v].push_back(pii(u, i));
		G[u].push_back(pii(v, i));
		D[--u].first++, D[--v].first++;
	}
	sort(D.begin(), D.end(), [&] (const pii& a, const pii& b) {
		return (a.first ^ b.first) ? (a.first > b.first) : (a.second < b.second);
	});

	printf("%d\n", D[m].first);
	for (int i = 0; i < m; i++) {
		invalid[D[i].second] = true;
	}
	dfs(1, 0, 0);
	for (int i = 1; i < n; i++) {
		printf("%d ", (!c[i]) ? (1) : (c[i]));
	}
	return 0;
}