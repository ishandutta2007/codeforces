#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int INF = (int)1e9 + 100; // max edge
struct Edge {
	int from, to;
	int cap, flow;
};
struct Dinic {
    int n;
	int s, t;
    vector<Edge> edges;
    vector<vi> g;
    vi d;
    vi pointer;
	int A;

    Dinic(int n) : n(n) {
		s = n - 2;
		t = n - 1;
        g.resize(n);
    }
	void add_edge(int from, int to, int cap) {
		g[from].pb(sz(edges));
		edges.pb({ from, to, cap, 0 });
		g[to].pb(sz(edges));
		edges.pb({ to, from, 0, 0 });
	}
    bool bfs() {
        d.assign(n, -1);
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : g[v]) {
                const Edge& e = edges[id];
                if (e.cap - e.flow >= A && d[e.to] == -1) {
                    d[e.to] = d[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[t] != -1;
    }
    int dfs(int v, int cmin) {
        if (v == t) {
            return cmin;
        }
        for (int& i = pointer[v]; i < sz(g[v]); i++) {
            int id = g[v][i];
			Edge& e = edges[id];
			if (e.cap - e.flow >= A && d[e.to] == d[v] + 1) {
				int pushed = dfs(e.to, min(cmin, e.cap - e.flow));
				if (pushed) {
					e.flow += pushed;
					edges[id ^ 1].flow -= pushed;
					return pushed;
				}
			}
        }
        return 0;
    }
    int max_flow() {
        int flow = 0;
		for (A = INF; A; A >>= 1) {
			while (bfs()) {
				pointer.assign(n, 0);
				while (int pushed = dfs(s, INF)) {
					flow += pushed;
				}
			}
		}
        return flow;
    }
};


const int M = 50;

#define x1 bivez
#define y1 dushit

int n;
int m;
int x1[M], y1[M], x2[M], y2[M];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	set<int> xs, ys;
	for (int i = 0; i < m; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		xs.insert(x1[i]);
		xs.insert(x2[i] + 1);
		ys.insert(y1[i]);
		ys.insert(y2[i] + 1);
	}
	vi vx, vy;
	for (auto it : xs) {
		vx.pb(it);
	}
	for (auto it : ys) {
		vy.pb(it);
	}
    Dinic grape(sz(vx) + sz(vy) + 2);
	for (int p = 0; p < m; p++) {
		for (int i = 0; i < sz(vx) - 1; i++) if (x1[p] <= vx[i] && vx[i + 1] <= x2[p] + 1) {
			for (int j = 0; j < sz(vy) - 1; j++) if (y1[p] <= vy[j] && vy[j + 1] <= y2[p] + 1) {
				grape.add_edge(i, j + sz(vx), INF);
			}
		}
	}
	for (int i = 0; i < sz(vx) - 1; i++) {
		grape.add_edge(grape.s, i, vx[i + 1] - vx[i]);
	}
	for (int j = 0; j < sz(vy) - 1; j++) {
		grape.add_edge(j + sz(vx), grape.t, vy[j + 1] - vy[j]);
	}
	cout << grape.max_flow();
}