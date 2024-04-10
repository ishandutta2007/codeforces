#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#define N_ 101000
using namespace std;
struct MCMF {
	struct Edge {
		int b, e, f, c;
	}E[N_*10];
	vector<int>G[N_];
	int n, EC, INF = 1e9, source, sink;
	int D[N_], inQ[N_], Q[N_ * 10], Path[N_];
	int s1 = 0;
	long long s2 = 0;
	void init(int N, int S, int T) {
		source = S, sink = T; EC = 0;
		s1 = s2 = 0;
		for (int i = 0; i <= N; i++)G[i].clear();
		n = N;
	}
	void Add_Edge(int b, int e, int f, int c) {
		G[b].push_back(EC);
		G[e].push_back(EC + 1);
		E[EC++] = { b,e,f,c };
		E[EC++] = { e,b,0,-c };
	}
	bool SPFA() {
		int i, head = 0, tail = 0;
		for (i = 1; i <= n; i++) {
			D[i] = INF;
			inQ[i] = 0;
		}
		D[source] = 0; Q[++tail] = source;
		while (head < tail) {
			int x = Q[++head];
			inQ[x] = 0;
			for (auto &tp : G[x]) {
				Edge t = E[tp];
				if (t.f && D[t.e] > D[x] + t.c) {
					D[t.e] = D[x] + t.c;
					if (!inQ[t.e]) {
						inQ[t.e] = 1;
						Q[++tail] = t.e;
					}
					Path[t.e] = tp;
				}
			}
		}
		if (D[sink] > 5e8)return false;
		int f = 1e9, x = sink;
		while (x != source) {
			f = min(f, E[Path[x]].f);
			x = E[Path[x]].b;
		}
		s1 += f, s2 += f * D[sink];
		x = sink;
		while (x != source) {
			E[Path[x]].f -= f;
			E[Path[x] ^ 1].f += f;
			x = E[Path[x]].b;
		}
		return true;
	}
	void Solve() {
		while (SPFA());
	}
}MCF;
int n, m, OutD[100], Res[110][110];
int main() {
	int i, j, a, b, SS = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		Res[a][b] = 1;
		SS += OutD[a];
		OutD[a]++;
	}
	int cnt = 0;
	MCF.init(n + n * (n-1)/2 + 2, n + n * (n-1)/2 + 1, n + n * (n-1)/2 + 2);
	for (i = 1; i <= n; i++) {
		for (j = i + 1; j <= n; j++) {
			if (Res[i][j] || Res[j][i])continue;
			cnt++;
			MCF.Add_Edge(MCF.source, n + cnt, 1, 0);
			MCF.Add_Edge(n + cnt, i, 1, 0);
			MCF.Add_Edge(n + cnt, j, 1, 0);
		}
	}
	for (i = 1; i <= n; i++) {
		while(OutD[i]<n) {
			MCF.Add_Edge(i, MCF.sink, 1, OutD[i]);
			OutD[i]++;
		}
	}
	MCF.Solve();
	//printf("%d\n", n*(n - 1)*(n - 2) / 6 - MCF.s2 - SS);
	for (i = n + 1; i <= n + cnt; i++) {
		int uu = 0, vv = 0;
		for (auto &t : MCF.G[i]) {
			int ed = MCF.E[t].e;
			if (1 <= ed && ed <= n) {
				if (MCF.E[t].f) vv = ed;
				else uu = ed;
			}
		}
		Res[uu][vv] = 1;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)printf("%d", Res[i][j]);
		puts("");
	}
}