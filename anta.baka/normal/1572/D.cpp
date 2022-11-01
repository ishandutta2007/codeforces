#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

using cost_type = long long;
const cost_type COST_INF = (int)1e18;
const int FLOW_INF = (int)1e9;
struct MinCost {
	explicit MinCost(int n) {
		g.resize(n);
	}
	struct edge {
		int from, to;
		int cap;
		cost_type cost;
		int flow;
	};
	vector<edge> edges;
	vector<vector<int>> g;
	void add_edge(int from, int to, cost_type cost, int cap) {
		edge e = { from, to, cap, cost, 0 };
		g[from].push_back(edges.size());
		edges.push_back(e);
		edge e2 = { to, from, 0, -cost, 0 };
		g[to].push_back(edges.size());
		edges.push_back(e2);
	}
	pair<int, cost_type> min_cost(int n, int s, int t, bool need_max_flow, int max_flow_value = FLOW_INF) {
		cost_type cost = 0;
		int flow = 0;
		while (flow < max_flow_value) {
			queue<int> q;
			q.push(s);
			vector<int> in_q(n, 0);
			in_q[s] = 1;
			vector<int> p(n, -1);
			vector<cost_type> d(n);
			d[s] = 0;
			p[s] = s;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				in_q[v] = false;
				for (size_t i : g[v]) {
					edge& e = edges[i];
					if (e.cap == e.flow || p[e.from] == -1)
						continue;
					if (p[e.to] == -1 || d[e.to] > d[e.from] + e.cost) {
						d[e.to] = d[e.from] + e.cost;
						p[e.to] = i;
						if (!in_q[e.to]) {
							in_q[e.to] = 1;
							q.push(e.to);
						}
					}
				}
			}
			if (p[t] == -1)
				break;
			if (d[t] >= 0 && !need_max_flow) {
				break;
			}
			int cur = t;
			int maxAdd = max_flow_value - flow;
			while (cur != s) {
				edge& e = edges[p[cur]];
				cur = e.from;
				maxAdd = min(maxAdd, e.cap - e.flow);
			}
			flow += maxAdd;
			cost += d[t] * maxAdd;
			cur = t;
			while (cur != s) {
				int id = p[cur];
				edges[id].flow += maxAdd;
				edges[id ^ 1].flow -= maxAdd;
				cur = edges[id].from;
			}
		}
		return make_pair(flow, cost);
	}
};

const int N = 1 << 21;

int a[N];
int bpc[N];
vector<pair<int, int>> vals[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i < N; i++) {
		bpc[i] = 1 + bpc[i & (i - 1)];
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < (1 << n); i++) {
		cin >> a[i];
	}

	for (int m = 0; m < (1 << n); m++) {
		if (bpc[m] & 1) {
			for (int i = 0; i < n; i++) {
				int val = a[m] + a[m ^ (1 << i)];
				vals[val].emplace_back(m, m ^ (1 << i));
			}
		}
	}

	int need = 2 * k * n;
	vector<pair<int, int>> imp;
	for (int i = N - 1; i >= 0 && imp.size() < need; i--) {
		for (auto e : vals[i]) {
			if (imp.size() >= need) {
				break;
			}
			imp.emplace_back(e);
		}
	}

	vector<int> lhs, rhs;
	for (auto e : imp) {
		lhs.push_back(e.first);
		rhs.push_back(e.second);
	}
	sort(lhs.begin(), lhs.end());
	sort(rhs.begin(), rhs.end());
	lhs.erase(unique(lhs.begin(), lhs.end()), lhs.end());
	rhs.erase(unique(rhs.begin(), rhs.end()), rhs.end());

	int ver = lhs.size() + rhs.size() + 2;
	int src = ver - 2;
	int dst = ver - 1;
	MinCost mc(ver);
	for (auto e : imp) {
		int from = lower_bound(lhs.begin(), lhs.end(), e.first) - lhs.begin();
		int to = lower_bound(rhs.begin(), rhs.end(), e.second) - rhs.begin();
		mc.add_edge(from, lhs.size() + to, -(a[e.first] + a[e.second]), 1);
	}
	for (int i = 0; i < lhs.size(); i++) {
		mc.add_edge(src, i, 0, 1);
	}
	for (int i = 0; i < rhs.size(); i++) {
		mc.add_edge(lhs.size() + i, dst, 0, 1);
	}

	cout << -mc.min_cost(ver, src, dst, true, k).second << endl;
}