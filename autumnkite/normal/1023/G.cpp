#include <bits/stdc++.h>

class state {
	static int _now;

	static int sgn(const int &v) {
		return v > 0 ? 1 : (v < 0 ? -1 : 0);
	}

	struct node {
		int x, v;

		node(int _x, int _v) : x(_x), v(_v) {}
	};

	struct coll {
		node a, b;
		int t;
	
		coll(node _a, node _b) : a(_a), b(_b), t((b.x - a.x + 1) >> 1) {}

		bool operator<(const coll &rhs) const {
			return std::make_tuple(t, a.x, a.v) < std::make_tuple(rhs.t, rhs.a.x, rhs.a.v);
		}
	};

	struct cmp {
		bool operator()(const node &a, const node &b) const {
			return a.x - sgn(a.v) * _now < b.x - sgn(b.v) * _now;
		}
	};

	int now;

	std::set<node, cmp> S;
	std::set<coll> T;

	void insert_coll(const node &a, const node &b) {
		if (a.v < 0 && b.v > 0) {
			T.emplace(a, b);
		}
	}

	void erase_coll(const node &a, const node &b) {
		if (a.v < 0 && b.v > 0) {
			T.erase(coll(a, b));
		}
	}

	void erase(const node &a) {
		auto it = S.find(a);
		if (it == S.end()) {
			return;
		}
		auto nx = std::next(it);
		if (nx != S.end()) {
			erase_coll(*it, *nx);
		}
		if (it != S.begin()) {
			auto pr = std::prev(it);
			erase_coll(*pr, *it);
			if (nx != S.end()) {
				insert_coll(*pr, *nx);
			}
		}
		S.erase(it);
	}

public:
	state() : now(0) {}

	void insert(int x, int v) {
		_now = now;
		if (v == 0) {
			return;
		}
		auto it = S.find(node(x + now * sgn(v), v));
		if (it != S.end()) {
			v += it->v;
			erase(*it);
		}
		if (v == 0) {
			return;
		}
		node a(x + now * sgn(v), v);
		it = S.insert(a).first;
		auto nx = std::next(it);
		if (it != S.begin()) {
			auto pr = std::prev(it);
			if (nx != S.end()) {
				erase_coll(*pr, *nx);
			}
			insert_coll(*pr, *it);
		}
		if (nx != S.end()) {
			insert_coll(*it, *nx);
		}
	}

	int delta(int p) {
		_now = now;
		auto it = S.find(node(p + now, 1));
		return it == S.end() ? 0 : it->v;
	}

	void advance(int l) {
		_now = now;
		while (!T.empty() && T.begin()->t - now <= l) {
			coll c = *T.begin();
			int v = c.a.v + c.b.v;
			int x = v < 0 ? c.a.x - sgn(c.a.v) * now : c.b.x - sgn(c.b.v) * now;
			erase(c.a), erase(c.b);
			insert(x, v);
		}
		now += l;
	}

	void merge(state &r) {
		if (S.size() < r.S.size()) {
			std::swap(now, r.now);
			S.swap(r.S);
			T.swap(r.T);
		}
		std::vector<std::pair<int, int>> tmp;
		_now = r.now;
		for (auto p : r.S) {
			tmp.emplace_back(p.x - sgn(p.v) * r.now, p.v);
		}
		r.S.clear(), r.T.clear();
		_now = now;
		for (auto p : tmp) {
			insert(p.first, p.second);
		}
	}

	int maximum() {
		_now = now;
		int sum = 0, ans = 0;
		for (auto p : S) {
			sum += p.v;
			ans = std::max(ans, sum);
		}
		return ans;
	}
};

int state::_now = 0;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		--u, --v;
		w <<= 1;
		E[u].emplace_back(v, w);
		E[v].emplace_back(u, w);
	}
	int m;
	std::cin >> m;
	std::vector<std::vector<std::pair<int, int>>> info(n);
	for (int i = 0; i < m; ++i) {
		int d, f, p;
		std::cin >> d >> f >> p;
		d <<= 1;
		--p;
		info[p].emplace_back(d, f);
	}

	std::vector<state> f(n);
	std::function<void(int, int, int)> dfs = [&](int u, int fa, int fw) {
		for (auto p : E[u]) {
			int v = p.first, w = p.second;
			if (v != fa) {
				dfs(v, u, w);
				f[u].merge(f[v]);
			}
		}
		auto tmp = info[u];
		for (auto &p : tmp) {
			int a = f[u].delta(p.first - 1), b = f[u].delta(p.first), c = f[u].delta(p.first + 1);
			p.second = std::max(0, p.second + a + b - std::max({a, a + b, a + b + c}));
		}
		f[u].advance(1);
		for (auto p : tmp) {
			f[u].insert(p.first, p.second);
			f[u].insert(p.first + 1, -p.second);
		}
		f[u].advance(fw - 1);
	};

	dfs(0, -1, 1);
	std::cout << f[0].maximum() << "\n";
}