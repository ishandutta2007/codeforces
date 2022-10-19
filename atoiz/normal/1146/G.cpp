/*input
4 10 2
2 3 8 76
3 4 7 39


*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

struct Edge
{
	int v, f, c;
	Edge() {}
	Edge(int _v, int _f, int _c): v(_v), f(_f), c(_c) {};
};

namespace Dinic
{
	const int MAXN = 3000, MAXM = 3000, INF = 1e9;
	int N, S, T;
	vector<int> G[MAXN];
	int dist[MAXN], ptr[MAXN];
	int qu[MAXN], fr, rr;
	vector<Edge> edges;

	void addEdge(int u, int v, int c)
	{
		G[u].emplace_back(SZ(edges));
		edges.emplace_back(v, 0, c);
		G[v].emplace_back(SZ(edges));
		edges.emplace_back(u, 0, 0);
	}

	bool levelGraph()
	{
		fill_n(dist, N, MAXN);
		fill_n(ptr, N, 0);

		fr = rr = 0; dist[qu[++rr] = S] = 0;
		while (fr < rr) {
			int u = qu[++fr];
			for (int id : G[u]) {
				Edge &e = edges[id];
				if (e.f < e.c && dist[u] + 1 < dist[e.v]) {
					dist[qu[++rr] = e.v] = dist[u] + 1;
					if (e.v == T) return true;
				}
			}
		}

		return false;
	}

	int pushFlow(int u, int flow)
	{
		if (u == T) return flow;
		for (int &i = ptr[u]; i < SZ(G[u]); ++i) {
			int id = G[u][i];
			Edge &e = edges[id];
			if (e.f < e.c && dist[u] + 1 == dist[e.v]) {
				int pushed = pushFlow(e.v, min(e.c - e.f, flow));
				if (pushed) {
					edges[id].f += pushed;
					edges[id ^ 1].f -= pushed;
					return pushed;
				}
			}
		}
		return 0;
	}

	int run()
	{
		while (levelGraph()) while (pushFlow(S, INF));
		int ans = 0;
		for (int id : G[S]) ans += edges[id].f;
		return ans;
	}
}

// start of code

int n, h, m;

const int INF = 300000;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> h >> m;
	Dinic::N = n * (h + 1) + m + 2;
	int S = Dinic::S = n * (h + 1) + m;
	int T = Dinic::T = n * (h + 1) + m + 1;
	int total = h * h * n;

	FOR(i, 0, n-1) {
		Dinic::addEdge(S, i * (h + 1), h * h);
		FOR(j, 1, h) Dinic::addEdge(i * (h + 1) + j - 1, i * (h + 1) + j, h * h - j * j);
	}

	FOR(j, 0, m-1) {
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		--l, --r;

		FOR(i, l, r) Dinic::addEdge(i * (h + 1) + x, n * (h + 1) + j, INF);
		Dinic::addEdge(n * (h + 1) + j, T, c);
	}

	cout << total - Dinic::run() << endl;

	return 0;
}