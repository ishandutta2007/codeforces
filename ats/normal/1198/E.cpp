#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
template<typename T> class FordFulkerson {
public:
	struct edge {
		int to;
		T cap;
		int rev;
	};
	int V;
	vector<vector<edge> > G;
	vector<bool> used;
	FordFulkerson(int node_size) : V(node_size), G(V), used(V, false) {};
	void add_edge(int from, int to, T cap) {
		G[from].push_back((edge) { to, cap, (int)G[to].size() });
		G[to].push_back((edge) { from, 0, (int)G[from].size() - 1 });
	}
	T dfs(int v, int t, T f) {
		if (v == t) return f;
		used[v] = true;
		for (auto& e : G[v]) {
			if (!used[e.to] && e.cap > 0) {
				T d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	T solve(int s, int t) {
		T flow = 0;
		for (;;) {
			fill(used.begin(), used.end(), false);
			T f = dfs(s, t, numeric_limits<T>::max());
			if (!f) return flow;
			flow += f;
		}
	}
};
template<typename T> class Dinic {
private:
	int V;
	vector<int> level, iter;
	void bfs(int s) {
		fill(level.begin(), level.end(), -1);
		queue<int> que;
		level[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (auto& e : G[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					que.push(e.to);
				}
			}
		}
	}
	T dfs(int v, int t, T f) {
		if (v == t) {
			return f;
		}
		for (int& i = iter[v]; i < (int)G[v].size(); i++) {
			edge& e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				T d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

public:
	struct edge {
		int to;
		T cap;
		int rev;
	};
	vector<vector<edge> > G;

	Dinic(int node_size) : V(node_size), level(V), iter(V), G(V) {}
	//
	void add_edge(int from, int to, T cap) {
		G[from].push_back((edge) { to, cap, (int)G[to].size() });
		G[to].push_back((edge) { from, (T)0, (int)G[from].size() - 1 });
	}
	//
	T solve(int s, int t) {
		T flow = 0;
		for (;;) {
			bfs(s);
			if (level[t] < 0) return flow;
			fill(iter.begin(), iter.end(), 0);
			T f;
			while ((f = dfs(s, t, numeric_limits<T>::max())) > 0) {
				flow += f;
			}
		}
	}
};
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int res = 0;
	vector<pair<pair<int, int>, pair<int, int> > > R(M);
	set<int> X;
	set<int> Y;
	for (int i = 0; i < M; i++) {
		cin >> R[i].first.first >> R[i].first.second >> R[i].second.first >> R[i].second.second;
		X.insert(R[i].first.first);
		X.insert(R[i].second.first + 1);
		Y.insert(R[i].first.second);
		Y.insert(R[i].second.second + 1);
	}
	if (M == 0) {
		cout << 0 << endl;
		return 0;
	}
	map<int, int> mpx;
	map<int, int> mpy;
	vector<int> xs;
	vector<int> ys;
	for (int i : X) {
		mpx[i] = (int)xs.size();
		xs.push_back(i);
	}
	for (int i : Y) {
		mpy[i] = (int)ys.size();
		ys.push_back(i);
	}
	int INF = 2 * N;
	int sz = (int)xs.size() + (int)ys.size() + M;
	Dinic<int> d(sz);
	int offset = (int)xs.size() + (int)ys.size() - 2;
	for (int i = 0; i < M; i++) {
		int X1 = mpx[R[i].first.first];
		int X2 = mpx[R[i].second.first + 1];
		int Y1 = mpy[R[i].first.second];
		int Y2 = mpy[R[i].second.second + 1];
		//cerr << X1 << " " << X2 << endl;
		for (int j = X1; j < X2; j++) {
			d.add_edge(j, offset + i, INF);
		}
		for (int j = Y1; j < Y2; j++) {
			d.add_edge(offset + i, (int)xs.size() - 1 + j, INF);
		}
	}
	int s = (int)xs.size() + (int)ys.size() + M - 2;
	int t = (int)xs.size() + (int)ys.size() + M - 1;
	for (int i = 0; i < (int)xs.size() - 1; i++) {
		d.add_edge(s, i, xs[i + 1] - xs[i]);
	}

	for (int i = 0; i < (int)ys.size() - 1; i++) {
		d.add_edge((int)xs.size() - 1 + i, t, ys[i + 1] - ys[i]);
	}
	cout << d.solve(s, t) << endl;
}