#include <bits/stdc++.h>

struct Node {
	int t;
	long long k, b;
	
	Node() : t(0), k(0), b(0) {}
	Node(int _t, long long _k, long long _b) : t(_t), k(_k), b(_b) {}
	
	bool operator<(const Node &rhs) const {
		return t < rhs.t;
	}
};

long long div_floor(long long a, long long b) {
	if (a >= 0) {
		return a / b;
	} else {
		return (a - b + 1) / b;
	}
}

long long div_ceil(long long a, long long b) {
	if (a >= 0) {
		return (a + b - 1) / b;
	} else {
		return a / b;
	}
}

std::pair<bool, std::vector<int>> solve(std::vector<Node> a, int L) {
	std::sort(a.begin(), a.end());
	bool par[2] = {true, true};
	bool flag = true;
	long long l = -L, r = L;
	for (int i = 1; i < (int)a.size(); ++i) {
		long long dk = a[i].k - a[i - 1].k;
		long long db = a[i].b - a[i - 1].b;
		long long dt = a[i].t - a[i - 1].t;
		for (int p = 0; p < 2; ++p) {
			if (((dk * p + db) & 1) != (dt & 1)) {
				par[p] = false;
			}
		}
		if (dk == 0) {
			flag &= -dt <= db && db <= dt;
		} else if (dk > 0) {
			l = std::max(l, div_ceil(-dt - db, dk));
			r = std::min(r, div_floor(dt - db, dk));
		} else {
			l = std::max(l, div_ceil(db - dt, -dk));
			r = std::min(r, div_floor(dt + db, -dk));
		}
	}
	if (!flag || (!par[0] && !par[1])) {
		return std::make_pair(false, std::vector<int>(L));
	}
	while (l <= r && !par[l & 1]) {
		++l;
	}
	if (l > r) {
		return std::make_pair(false, std::vector<int>(L));
	}

	std::vector<int> ans(L);
	for (int i = 1; i < (int)a.size(); ++i) {
		long long dx = (a[i].k - a[i - 1].k) * l + (a[i].b - a[i - 1].b);
		long long dt = a[i].t - a[i - 1].t;
		assert((dx & 1) == (dt & 1) && -dt <= dx && dx <= dt);
		for (int j = 0; j < (dx + dt) / 2; ++j) {
			ans[a[i - 1].t + j] = 1;
		}
		for (int j = (dx + dt) / 2; j < dt; ++j) {
			ans[a[i - 1].t + j] = -1;
		}
	}
	return std::make_pair(true, ans);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, L;
	std::cin >> n >> L;
	std::vector<Node> a, b;
	a.emplace_back(0, 0, 0);
	a.emplace_back(L, 1, 0);
	b.emplace_back(0, 0, 0);
	b.emplace_back(L, 1, 0);
	for	(int i = 0; i < n; ++i) {
		long long t, x, y;
		std::cin >> t >> x >> y;
		a.emplace_back(t % L, -t / L, x + y);
		b.emplace_back(t % L, -t / L, x - y);
	}

	auto res_a = solve(a, L);
	auto res_b = solve(b, L);
	if (!res_a.first || !res_b.first) {
		std::cout << "NO\n";
	} else {
		const char ch[] = "LDUR";
		for (int i = 0; i < L; ++i) {
			std::cout << ch[(res_a.second[i] == 1) << 1 | (res_b.second[i] == 1)];
		}
		std::cout << "\n";
	}
}