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
#define int long long
int MOD = 1000000007;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

struct E {
	int a;
	int b;
	int c;
};
typedef int Weight;
struct Edge {
	int src, dst;
	Weight weight;
	Edge(int src, int dst, Weight weight) :
		src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
	return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
	e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;
bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
	color[v] = 1;
	FOR(e, g[v]) {
		if (color[e->dst] == 2) continue;
		if (color[e->dst] == 1) return false;
		if (!visit(g, e->dst, order, color)) return false;
	}
	order.push_back(v); color[v] = 2;
	return true;
}
bool topologicalSort(const Graph &g, vector<int> &order) {
	int n = g.size();
	vector<int> color(n);
	order.clear();
	REP(u, n) if (!color[u] && !visit(g, u, order, color))
		return false;
	reverse(ALL(order));
	return true;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<E> A(M);
	int res = 0;
	for (int i = 0; i < M; i++) {
		cin >> A[i].a >> A[i].b >> A[i].c;
		A[i].a--;
		A[i].b--;
	}
	int ok = 1e9 + 1;
	int ng = -1;
	vector<int> order;
	while (ok - ng > 1) {
		int m = (ok + ng) / 2;
		Graph g(N);
		for (int i = 0; i < M; i++) {
			if (A[i].c > m) {
				g[A[i].a].push_back(Edge(A[i].a, A[i].b, 0));
			}
		}
		if (topologicalSort(g, order)) {
			ok = m;
		}
		else {
			ng = m;
		}
	}
	vector <int> vp;
	{
		Graph g(N);
		for (int i = 0; i < M; i++) {
			if (A[i].c > ok) {
				g[A[i].a].push_back(Edge(A[i].a, A[i].b, 0));
			}
		}
		topologicalSort(g, order);
		vector<int> pos(N);
		for (int i = 0; i < N; i++) {
			pos[order[i]] = i;
		}
	
		for (int i = 0; i < M; i++) {
			if (A[i].c <= ok) {
				if (pos[A[i].a] > pos[A[i].b]) {
					vp.push_back(i + 1);
				}
			}
		}
	}
	cout << ok << " " << vp.size() << endl;
	for (int i = 0; i < vp.size(); i++) {
		if (i > 0)cout << " ";
		cout << vp[i];
	}
	cout << endl;
}