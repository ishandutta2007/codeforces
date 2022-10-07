#include <bits/stdc++.h>

const int N = 200005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n;
int fa[N];
int a[N];
std::vector<int> E[N];
int dep[N];

long long f[N];
std::pair<long long, long long> fd[N], ad[N];

void upd(long long &a, long long b) {
	a = std::max(a, b);
}

void solve() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		E[i].clear();
	}
	for (int i = 2; i <= n; ++i) {
		std::cin >> fa[i];
		E[fa[i]].push_back(i);
	}
	for (int i = 2; i <= n; ++i) {
		std::cin >> a[i];
	}
	std::vector<int> Q;
	Q.push_back(1);
	dep[1] = 0;
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (int v : E[u]) {
			dep[v] = dep[u] + 1;
			Q.push_back(v);
		}
	}
	std::reverse(Q.begin(), Q.end());
	for (int i = 0; i < n; ++i) {
		fd[i].first = fd[i].second = -INF;
		ad[i].first = ad[i].second = -INF;
	}
	for (int u : Q) {
		if (!E[u].empty()) {
			f[u] = 0;
			for (int v : E[u]) {
				f[u] = std::max(f[u], f[v] + std::max(a[v] + ad[dep[v]].second, -a[v] + ad[dep[v]].first));
				f[u] = std::max(f[u], std::max(a[v] + fd[dep[v]].second, -a[v] + fd[dep[v]].first));
			}
		} else {
			f[u] = 0;
		}
		upd(ad[dep[u]].first, a[u]);
		upd(ad[dep[u]].second, -a[u]);
		upd(fd[dep[u]].first, f[u] + a[u]);
		upd(fd[dep[u]].second, f[u] - a[u]);
	}
	std::cout << f[1] << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T = 1;
	std::cin >> T;
	while (T--) {
		solve();
	}
}