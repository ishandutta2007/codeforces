#include <bits/stdc++.h>

const int INF = 0x3f3f3f3f;

class State {
	int a[4];

public:
	State() {
		a[0] = a[1] = a[2] = a[3] = -INF;
	}

	int &operator[](int x) {
		return a[x];
	}

	const int &operator[](int x) const {
		return a[x];
	}
};

bool chmax(int &a, int b) {
	if (b > a) {
		a = b;
		return true;
	} else {
		return false;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> l(n), r(n);
	std::vector<std::tuple<int, int, int>> pos;
	for (int i = 0; i < n; ++i) {
		std::cin >> l[i] >> r[i];
		pos.emplace_back(l[i], i, 0);
		pos.emplace_back(r[i], i, 1);
	}
	std::sort(pos.begin(), pos.end());
	std::vector<std::vector<int>> E(n + 1);
	std::vector<int> fa(n + 1);
	int now = n;
	for (auto p : pos) {
		int id = std::get<1>(p), op = std::get<2>(p);
		if (op) {
			now = fa[now];
		} else {
			E[now].push_back(id);
			fa[id] = now;
			now = id;
		}
	}

	std::vector<std::vector<State>> f(n), g(n), h(n);

	std::function<void(int)> DP = [&](int u) {
		if (E[u].empty()) {
			f[u].resize(1);
			f[u][0][0] = r[u] - l[u];
			f[u][0][1] = r[u];
			f[u][0][2] = -l[u];
			f[u][0][3] = 0;
			return;
		}
		for (int v : E[u]) {
			DP(v);
			if (v == E[u][0]) {
				f[u] = f[v];
				g[v].resize(f[u].size());
				for (int i = 0; i < (int)f[u].size(); ++i) {
					for (int a = 0; a < 4; ++a) {
						g[v][i][a] = i << 4 | a;
					}
				}
				continue;
			}
			std::vector<State> tmp(f[u].size() + f[v].size());
			g[v].resize(f[u].size() + f[v].size());
			for (int i = 0; i < (int)f[u].size(); ++i) {
				for (int a = 0; a < 4; ++a) {
					for (int j = 0; j < (int)f[v].size(); ++j) {
						for (int b = 0; b < 4; ++b) {
							if ((a >> 1) == (b & 1)) {
								if (chmax(tmp[i + j + (b & 1)][(a & 1) | (b & 2)], f[u][i][a] + f[v][j][b])) {
									g[v][i + j + (b & 1)][(a & 1) | (b & 2)] = j << 4 | a << 2 | b;
								}
							}
						}
					}
				}
			}
			f[u].swap(tmp);
		}
		std::vector<State> tmp(f[u].size());
		h[u].resize(f[u].size());
		for (int i = 0; i < (int)f[u].size(); ++i) {
			for (int a = 0; a < 4; ++a) {
				if (i > 0 && chmax(tmp[i - 1][a], f[u][i][a])) {
					h[u][i - 1][a] = 1;
				}
				if (a & 1 && chmax(tmp[i][a ^ 1], f[u][i][a] - l[u])) {
					h[u][i][a ^ 1] = 2;
				}
				if (a & 2 && chmax(tmp[i][a ^ 2], f[u][i][a] + r[u])) {
					h[u][i][a ^ 2] = 3;
				}
				if (a & 1 && chmax(tmp[i][a], f[u][i][a])) {
					h[u][i][a] = 4;
				}
				if (a & 2 && chmax(tmp[i][a], f[u][i][a])) {
					h[u][i][a] = 5;
				}
			}
		}
		f[u].swap(tmp);
	};

	std::vector<std::pair<int, int>> sta;
	std::vector<int> ansl(n), ansr(n);

	std::function<std::pair<int, int>(int, int, int)> get_ans = [&](int u, int i, int a) {
		if (E[u].empty()) {
			ansl[u] = l[u], ansr[u] = r[u];
			return std::make_pair(l[u], r[u]);
		}
		int tp = h[u][i][a];
		if (tp == 1) {
			++i;
		} else if (tp == 2) {
			a ^= 1;
		} else if (tp == 3) {
			a ^= 2;
		}
		std::reverse(E[u].begin(), E[u].end());
		int rig = -1, lst = -1;
		for (int v : E[u]) {
			int j = g[v][i][a] >> 4, b = g[v][i][a] & 3;
			std::pair<int, int> tmp = get_ans(v, j, b);
			if (b & 2) {
				if (lst == -1) {
					rig = tmp.second;
				} else {
					sta.emplace_back(tmp.second, lst);
				}
			}
			lst = tmp.first;
			a = g[v][i][a] >> 2 & 3;
			i -= j + (b & 1);
		}
		if (tp == 1) {
			ansl[u] = sta.back().first, ansr[u] = sta.back().second;
			sta.pop_back();
		} else if (tp == 2 || tp == 4) {
			ansl[u] = l[u], ansr[u] = lst, lst = l[u];
		} else if (tp == 3 || tp == 5) {
			ansl[u] = rig, ansr[u] = r[u], rig = r[u];
		}
		return std::make_pair(lst, rig);
	};

	int ans = 0;
	for (int i : E[n]) {
		DP(i);
		ans += f[i][0][0];
		sta.clear();
		get_ans(i, 0, 0);
	}
	std::cout << ans << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << ansl[i] << " " << ansr[i] << "\n";
	}
}