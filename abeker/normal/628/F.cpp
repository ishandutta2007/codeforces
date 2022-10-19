#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int MAXN = 1e4 + 5;

namespace Dinic {
	#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
	#define REP(i, n) FOR(i, 0, n)
	
	typedef long long llint;
	
	const int MAXV = 1e4 + 100;
	const int MAXE = 1e5 + 100;
	const llint oo = 1e18;

	int V, E;
	int last[MAXV], dist[MAXV], curr[MAXV];
	int next[MAXE], adj[MAXE]; llint cap[MAXE];

	void init(int n) {
		V = n;
		E = 0;
		REP(i, V) last[i] = -1;
	}

	void edge(int x, int y, llint c1, llint c2) {
		adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
		adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
	}

	llint push(int x, int sink, llint flow) {
		if (x == sink) return flow;

		for (int &e = curr[x]; e != -1; e = next[e]) {
			int y = adj[e];

			if (cap[e] && dist[x] + 1 == dist[y])
				if (llint f = push(y, sink, min(flow, cap[e])))
					return cap[e] -= f, cap[e^1] += f, f;
		}
		return 0;
	}

	llint run(int src, int sink) {
		llint ret = 0;
		for (;;) {
			REP(i, V) curr[i] = last[i];
			REP(i, V) dist[i] = -1;

			queue<int> Q;
			Q.push(src), dist[src] = 0;
			
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();

				for (int e = last[x]; e != -1; e = next[e]) {
					int y = adj[e];
					if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
				}
			}
			if (dist[sink] == -1) break;

			while (llint f = push(src, sink, oo)) ret += f;
		}
		return ret;
	}
}

int N, B, Q;
pii hint[MAXN];
int tot;

void load() {
	scanf("%d%d%d", &N, &B, &Q);
	for (int i = 1; i <= Q; i++)
		scanf("%d%d", &hint[i].first, &hint[i].second);
}

bool add(pii p, pii q, int id) {
	int diff = q.second - p.second;
	int len = q.first - p.first;
	if (diff < 0 || diff > len)
		return false;
	
	Dinic::edge(0, id, diff % 5, 0);
	int bound = (diff + 4) / 5 <= len / 5 ? 5 : len % 5;
	for (int i = 0; i < bound; i++)
		Dinic::edge(id, Q + 1 + (p.first + 1 + i) % 5, 1, 0);
	tot += diff % 5;
	
	return true;
}

bool solve() {
	hint[0] = {0, 0};
	hint[++Q] = {B, N};
	sort(hint, hint + Q + 1);
	
	Dinic::init(Q + 10);
	for (int i = 1; i <= Q; i++)
		if (!add(hint[i - 1], hint[i], i))
			return false;
	
	for (int i = 1; i <= 5; i++)
		Dinic::edge(Q + i, Q + 6, tot / 5, 0);
	
	return Dinic::run(0, Q + 6) == tot;
}

int main() {
	load();
	puts(solve() ? "fair" : "unfair");
	return 0;
}