#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <tuple>

using namespace std;

int n, m;
vector<tuple<int, int, int>> es;
int q;
vector<int> qs;

void read() {
	cin >> n >> m;
	es.resize(m);
	for (auto &e : es) {
		int u, v, w;
		cin >> u >> v >> w;
		e = make_tuple(u - 1, v - 1, w);
	}
	cin >> q;
	qs.resize(q);
	for (auto &_ : qs) {
		cin >> _;
	}
}

void gen() {

}

template<typename capacity_type, capacity_type capacity_inf, typename cost_type, cost_type cost_inf>
struct Flow {
	struct edge {
		int from;
		int to;
		capacity_type c, f;
		cost_type w;

		edge(int from, int to, capacity_type c, capacity_type f, cost_type w) : from(from), to(to), c(c), f(f), w(w) {}
	};

	int n, s, t;
	vector<edge> es;
	vector<vector<int>> g;
	vector<cost_type> d;
	vector<int> p;

	Flow(int n) : n(n), s(0), t(n - 1), g(n), d(n), p(n) {}

	void add_edge(int u, int v, capacity_type c, cost_type w) {
		es.emplace_back(u, v, c, 0, w);
		es.emplace_back(v, u, 0, 0, -w);
		static int i = 0;
		g[u].push_back(i);
		g[v].push_back(i ^ 1);
		i += 2;
	}

	void autistic_ford_bellman() {
		fill(d.begin(), d.end(), cost_inf);
		d[s] = 0;
		for (int it = 0; it < n; it++) {
			for (int i = 0; i < es.size(); i++) {
				const auto &e = es[i];
				if (e.c - e.f > 0 && d[e.from] + e.w < d[e.to]) {
					d[e.to] = d[e.from] + e.w;
					p[e.to] = i;
				}
			}
		}
	}

	vector<cost_type> path_costs() {
		vector<cost_type> ret;
		while (true) {
			autistic_ford_bellman();
			if (d[t] == cost_inf) {
				break;
			}
			int v = t;
			cost_type w = 0;
			while (v != s) {
				int i = p[v];
				auto &e = es[i];
				e.f++;
				es[i ^ 1].f--;
				w += e.w;
				v = e.from;
			}
			ret.push_back(w);
		}
		return ret;
	}
};

auto solve() {
	Flow<int, 1, int, (int)1e9 + 228> grape(n);
	for (const auto &e : es) {
		grape.add_edge(get<0>(e), get<1>(e), 1, get<2>(e));
	}
	auto v = grape.path_costs();
	vector<int> kek(v.size());
	for (int i = 1; i < kek.size(); i++) {
		for (int j = 0; j < i; j++) {
			kek[i] += (v[i] - v[j]);
		}
	}
	vector<double> ret;
	for (auto x : qs) {
		int k = 0;
		while (k + 1 < kek.size() && kek[k + 1] <= x) {
			k++;
		}
		ret.push_back(v[k] + (x - kek[k]) / (k + 1.0));
	}
	return ret;
}

auto brute() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(10);
	cout << fixed;
	read();
	for (auto x : solve()) {
		cout << x << '\n';
	}
}