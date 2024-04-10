#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <cassert>

using std::cin;
using std::cout;
using std::vector;
using std::endl;
using std::min;
using std::max;

const int INF = 1e9;


template <class S, class T>
class MinCost {
public: 
	MinCost() : n(0) {};

	MinCost(size_t m) {
		n = m;
		g.resize(n);
		used.resize(n);
		q.resize(n);
		dist.resize(n);
	}

	T minCost (size_t s, size_t t, int k) {
		T cost = 0;
		vector<size_t> p(n);

		while (fordBelman(s, t, p) && k > 0) 
			cost += addFlow(s, t, k, p);
		return cost;
	}

	void addEdge(size_t u, size_t v, S cap, T cost) {
		edges.push_back(Edges{u, v, cap, 0, cost});
		g[u].push_back((int)edges.size() - 1);
		edges.push_back(Edges{v, u, 0, 0, - cost});
		g[v].push_back((int)edges.size() - 1);
	}


	void printEdges() {
		for (int i = 0; i < edges.size(); ++i)
			if (edges[i].cap == 1)
				cout << edges[i].flow << " ";
		cout << endl;
	}

private:

	size_t addFlow(size_t s, size_t t, S &maxFlow, vector<size_t> &p) {
		size_t cur = t;
		T cost = 0;
		S flow = maxFlow;
		while (cur != s) {
			size_t e = p[cur];
			flow = min(flow, edges[e].cap - edges[e].flow);
			cur = edges[e ^ 1].to;
		}
		cur = t;
		while (cur != s) {
			size_t e = p[cur];
			edges[e].flow += flow;
			edges[e ^ 1].flow -= flow;
			cost += edges[e].cost * flow;
			cur = edges[e ^ 1].to;
		}
		maxFlow -= flow;
		return cost;
	}

	
	bool fordBelman(size_t s, size_t t, vector<size_t> &p) {
		int l = 0, r = 0;
		q[r++] = s;
		used[s] = 1;
		dist.assign(n, INF);
		dist[s] = 0;
		while (l != r) {
			size_t v = q[l];
			for (auto e : g[v])
				if (edges[e].cap > edges[e].flow && dist[edges[e].to] > dist[v] + edges[e].cost) {
					dist[edges[e].to] = dist[v] + edges[e].cost;
					p[edges[e].to] = e;
					if (used[edges[e].to] == 0) {
						q[r++] = edges[e].to;
						if (r == n)
							r = 0;
						used[edges[e].to] = 1;
					}
				}
			used[v] = 0;
			++l;
			if (l == n)
				l = 0;
		}
		return (dist[t] != INF);
	}


	struct Edges {
		size_t from;
		size_t to;
		S cap;
		S flow;
		T cost;
	};

	size_t n;
	vector<Edges> edges;
	vector< vector<size_t> > g;

	vector<bool> used;
	vector<size_t> q;
	vector<T> dist;
};


struct Task {
	size_t l, r;
	size_t cost;
};

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	size_t n, k;
	cin >> n >> k;

	vector<Task> tasks(n);

	vector<size_t> tm;

	for (size_t i = 0; i < n; ++i) {
		size_t l, r, cost;
		cin >> l >> r >> cost;
		tasks[i] = {l, l + r, cost};
		tm.push_back(l);
	}
	sort(tm.begin(), tm.end());
	tm.resize(unique(tm.begin(), tm.end()) - tm.begin());

	size_t m = tm.size();
	MinCost<int, int> minCost(m + 1);


	size_t source = 0;
	size_t target = m;
	for (size_t i = 0; i < m; ++i)
		minCost.addEdge(i, i + 1, INF, 0);

	for (size_t i = 0; i < n; ++i) {
		size_t l = lower_bound(tm.begin(), tm.end(), tasks[i].l) - tm.begin();
		size_t r = lower_bound(tm.begin(), tm.end(), tasks[i].r) - tm.begin();
		minCost.addEdge(l, r, 1, -tasks[i].cost);
	}

	int ans = minCost.minCost(source, target, k);

	minCost.printEdges();
}