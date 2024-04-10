#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> y[i];
	}
	std::vector<int> vx(x), vy(y);
	std::sort(vx.begin(), vx.end());
	vx.erase(std::unique(vx.begin(), vx.end()), vx.end());
	std::sort(vy.begin(), vy.end());
	vy.erase(std::unique(vy.begin(), vy.end()), vy.end());

	std::vector<std::vector<int>> px(vx.size()), py(vy.size());
	for (int i = 0; i < n; ++i) {
		int v = std::lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
		px[v].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int v = std::lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin();
		py[v].push_back(i);
	}
	for (auto &p : px) {
		std::sort(p.begin(), p.end(), [&](int i, int j) {
			return y[i] < y[j];
		});
	}
	for (auto &p : py) {
		std::sort(p.begin(), p.end(), [&](int i, int j) {
			return x[i] < x[j];
		});
	}

	auto check = [&](int T) {
		DSU D(n);
		for (int i = 0; i < (int)vx.size(); ++i) {
			for (int j = 1; j < (int)px[i].size(); ++j) {
				if (y[px[i][j]] - y[px[i][j - 1]] <= T) {
					D.merge(px[i][j - 1], px[i][j]);
				}
			}
		}
		for (int i = 0; i < (int)vy.size(); ++i) {
			for (int j = 1; j < (int)py[i].size(); ++j) {
				if (x[py[i][j]] - x[py[i][j - 1]] <= T) {
					D.merge(py[i][j - 1], py[i][j]);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += D.find(i) == i;
		}
		if (cnt == 1) {
			return true;
		} else if (cnt == 2) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (D.find(i) != D.find(j)) {
						if (abs(x[i] - x[j]) <= T && abs(y[i] - y[j]) <= T) {
							return true;
						} else if (x[i] == x[j] && (abs(y[i] - y[j]) + 1) / 2 <= T) {
							return true;
						} else if (y[i] == y[j] && (abs(x[i] - x[j]) + 1) / 2 <= T) {
							return true;
						}
					}
				}
			}
			return false;
		} else if (cnt == 3) {
			for (int i = 0; i < (int)vx.size(); ++i) {
				for (int j = 1; j < (int)px[i].size(); ++j) {
					int u = px[i][j], v = px[i][j - 1];
					if (D.find(u) != D.find(v)) {
						for (int k = 0; k < n; ++k) {
							if (D.find(u) != D.find(k) && D.find(v) != D.find(k)) {
								if (abs(y[u] - y[k]) <= T && abs(y[v] - y[k]) <= T && abs(x[u] - x[k]) <= T) {
									return true;
								}
							}
						}
					}
				}
			}
			for (int i = 0; i < (int)vy.size(); ++i) {
				for (int j = 1; j < (int)py[i].size(); ++j) {
					int u = py[i][j], v = py[i][j - 1];
					if (D.find(u) != D.find(v)) {
						for (int k = 0; k < n; ++k) {
							if (D.find(u) != D.find(k) && D.find(v) != D.find(k)) {
								if (abs(x[u] - x[k]) <= T && abs(x[v] - x[k]) <= T && abs(y[u] - y[k]) <= T) {
									return true;
								}
							}
						}
					}
				}
			}
			return false;
		} else if (cnt == 4) {
			for (int ix = 0; ix < (int)vx.size(); ++ix) {
				for (int jx = 1; jx < (int)px[ix].size(); ++jx) {
					for (int iy = 0; iy < (int)vy.size(); ++iy) {
						for (int jy = 1; jy < (int)py[iy].size(); ++jy) {
							int a = px[ix][jx], b = px[ix][jx - 1], c = py[iy][jy], d = py[iy][jy - 1];
							if (D.find(a) != D.find(b) && D.find(a) != D.find(c) && D.find(a) != D.find(d) && 
							    D.find(b) != D.find(c) && D.find(b) != D.find(d) && D.find(c) != D.find(d)) {
								if (abs(y[a] - y[c]) <= T && abs(y[b] - y[c]) <= T &&
								    abs(x[c] - x[a]) <= T && abs(x[d] - x[a]) <= T) {
									return true;
								}
							}
						}
					}
				}
			}
			return false;
		} else {
			return false;
		}
	};

	int l = 0, r = 2e9, ans = -1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << ans << "\n";
}