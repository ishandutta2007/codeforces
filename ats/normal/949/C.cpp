#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
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
void visit(const Graph &g, int v, vector< vector<int> >& scc,
	stack<int> &S, vector<bool> &inS,
	vector<int> &low, vector<int> &num, int& time) {
	low[v] = num[v] = ++time;
	S.push(v); inS[v] = true;
	FOR(e, g[v]) {
		int w = e->dst;
		if (num[w] == 0) {
			visit(g, w, scc, S, inS, low, num, time);
			low[v] = min(low[v], low[w]);
		}
		else if (inS[w])
			low[v] = min(low[v], num[w]);
	}
	if (low[v] == num[v]) {
		scc.push_back(vector<int>());
		while (1) {
			int w = S.top(); S.pop(); inS[w] = false;
			scc.back().push_back(w);
			if (v == w) break;
		}
	}
}
void stronglyConnectedComponents(const Graph& g,
	vector< vector<int> >& scc) {
	const int n = g.size();
	vector<int> num(n), low(n);
	stack<int> S;
	vector<bool> inS(n);
	int time = 0;
	REP(u, n) if (num[u] == 0)
		visit(g, u, scc, S, inS, low, num, time);
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M, H;
	cin >> N >> M >> H;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int a, b;
	
	Graph g(N); 
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		if ((A[a] + 1) % H == A[b]) {
			g[a].push_back(Edge(a, b, 1));
		}
		swap(a, b);
		if ((A[a] + 1) % H == A[b]) {
			g[a].push_back(Edge(a, b, 1));
		}
	}
	vector<vector<int> >scc;
	stronglyConnectedComponents(g, scc);
	vector<int> inv(N);
	for (int i = 0; i < scc.size(); i++) {
		for (int j = 0; j < scc[i].size(); j++) {
			inv[scc[i][j]] = i;
		}
	}
	bool f;
	int res = N + 1;
	int ii = 0;
	for (int i = 0; i < scc.size(); i++) {
		f = true;
		for (int j = 0; j < scc[i].size(); j++) {
			
			int v = scc[i][j];
			for (int k = 0; k < g[v].size(); k++) {
				if (inv[g[v][k].dst] != i) {
					f = false;
					break;
				}
			}
			if (!f)break;
		}
		if (f) {
			if (res > (int)scc[i].size()) {
				res = (int)scc[i].size();
				ii = i;
			}
		}
	}
	cout << res << endl;
	for (int i = 0; i < scc[ii].size(); i++) {
		if (i > 0)cout << " ";
		cout << scc[ii][i] + 1;
	}
	cout << endl;
}