#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 2e6 + 5;

int n;
char str[N];
vector<int> g[N];

inline void init() {
	scanf("%d", &n);
	for (int i = 1, u, v; i < n; i++) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		if (str[i] == 'W') {
			g[i].push_back(++n);
			g[n].push_back(i);
			g[n].push_back(n + 1);
			g[n + 1].push_back(n);
			g[n].push_back(n + 2);
			g[n + 2].push_back(n);
			n = n + 2;
		}
	}
}

int dfs(int p, int fa, int dest) {
	if (p == dest) {
		return 1;
	}
	for (auto e : g[p]) {
		if (e ^ fa) {
			int ret = dfs(e, p, dest);
			if (~ret) {
				return ret ^ 1;
			}
		}
	}
	return -1;
}

vector<int> d3;
inline void solve() {
	d3.clear();
	for (int i = 1; i <= n; i++) {
		if (g[i].size() >= 4) {
			puts("White");
			return;
		}
		if (g[i].size() == 3) {
			d3.push_back(i);
			int _cnt = 0;
			for (auto e : g[i]) {
				if (g[e].size() >= 2) {
					_cnt++;
				}
			}
			if (_cnt >= 2) {
				puts("White");
				return;
			}
		}
	}
	if (d3.size() >= 3) {
		puts("White");
		return;
	}
	if (d3.size() == 2) {
		puts((dfs(d3[0], 0, d3[1])) ? ("White") : ("Draw"));
	} else {
		puts("Draw");
	}
}

inline void clear() {
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
}

int T;
int main() {
	scanf("%d", &T);
	while (T--) {
		init();
		solve();
		clear();
	}
	return 0;
}