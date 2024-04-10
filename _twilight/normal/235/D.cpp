#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e3 + 5;

template <typename T>
T _abs(T a) {
	return (a < 0) ? (-a) : (a);
}

int n, m;
vector<int> cir;
vector<int> G[N];

stack<int> S;
boolean vis[N], onc[N];
void dfs(int p, int fa) {
	if (vis[p]) {
		int cur;
		do {
			cur = S.top();
			S.pop();
			onc[cur] = true;
			cir.push_back(cur);
		} while (cur != p);
		throw 1;
	}
	vis[p] = true;
	S.push(p);
	for (auto& e : G[p]) {
		if (e ^ fa) {
			dfs(e, p);
		}
	}
}

int dep[N], id[N];
vector<int> T[N];
void dfs(int p, int fa, int d, int _id) {
	dep[p] = d, id[p] = _id;
	T[_id].push_back(p);
	for (auto& e : G[p]) {
		if ((e ^ fa) && !onc[e]) {
			dfs(e, p, d + 1, _id);
		}
	}
}

double ans = 0;
void dfs(int p, int fa, int dis) {
	ans += 1.0 / dis;
	for (auto& e : G[p]) {
		if (id[e] == id[p] && e != fa) {
			dfs(e, p, dis + 1);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1, u, v; i <= n; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	try {
		dfs(0, -1);
	} catch (int) {
		m = cir.size();
	}
	for (int i = 0; i < m; i++) {
		dfs(cir[i], -1, 0, i);
	}
	for (int i = 0; i < n; i++) {
		dfs(i, -1, 1);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j)
				continue;
			int d1 = _abs(i - j), d2 = m - d1;
			for (auto& p : T[i]) {
				for (auto& q : T[j]) {
					ans += 1.0 / (dep[p] + dep[q] + d1 + 1);
					ans += 1.0 / (dep[p] + dep[q] + d2 + 1);
					ans -= 1.0 / (dep[p] + dep[q] + m);
				}
			}
		}
	}
	printf("%.9lf\n", ans);
	return 0;
}