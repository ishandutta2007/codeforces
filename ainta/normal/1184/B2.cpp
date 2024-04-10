#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int dis[110][110], nV, nE, n, m;
long long K, H;
#define N_ 10100
#define M_ 2210000
struct MaxFlow {
	vector<int>G[N_];
	struct Edge {
		int b, e, f;
	}E[M_];
	int EC, flow, PV[N_], Q[N_], Level[N_], n, source, sink, INF = 1e9;
	void init(int N, int S, int T) {
		source = S, sink = T, flow = EC = 0;
		n = N;
		for (int i = 0; i <= n; i++)G[i].clear();
	}
	void Add_Edge(int a, int b, int f) {
		G[a].push_back(EC);
		G[b].push_back(EC + 1);
		E[EC++] = { a,b,f };
		E[EC++] = { b,a,0 };
	}
	int BlockFlow(int a, int f) {
		if (a == sink)return f;
		for (int &i = PV[a]; i >= 0; i--) {
			int t = G[a][i];
			if (E[t].f && Level[E[t].e] == Level[a] + 1) {
				int ff = BlockFlow(E[t].e, min(E[t].f, f));
				if (ff) {
					E[t].f -= ff;
					E[t ^ 1].f += ff;
					return ff;
				}
			}
		}
		return 0;
	}
	bool GetLevel() {
		int head = 0, tail = 0, i;
		for (i = 1; i <= n; i++)Level[i] = -1;
		Q[++tail] = source; Level[source] = 0;
		while (head < tail) {
			int x = Q[++head];
			for (auto &t : G[x]) {
				if (E[t].f && Level[E[t].e] == -1) {
					Level[E[t].e] = Level[x] + 1;
					Q[++tail] = E[t].e;
				}
			}
		}
		return Level[sink] != -1;
	}
	void Dinic() {
		int i, t;
		flow = 0;
		while (GetLevel()) {
			for (i = 1; i <= n; i++)PV[i] = G[i].size() - 1;
			while (t = BlockFlow(source, INF)) {
				flow += t;
			}
		}
	}
}G1;
struct AA {
	int x, a, f;
}A[1100];
struct BB {
	int x, d;
}B[1100];
int main() {
	int i, j, k;
	scanf("%d%d", &nV, &nE);
	for (i = 1; i <= nV; i++)for (j = 1; j <= nV; j++)if (i != j)dis[i][j] = 1e9;
	for (i = 0; i < nE; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		dis[a][b] = dis[b][a] = 1;
	}
	for (k = 1; k <= nV; k++)for (i = 1; i <= nV; i++)for (j = 1; j <= nV; j++)dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	scanf("%d%d%lld%lld", &n, &m, &K, &H);
	G1.init(n + m + 2, n + m + 1, n + m + 2);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d", &A[i].x, &A[i].a, &A[i].f);
		G1.Add_Edge(G1.source, i, 1);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &B[i].x, &B[i].d);
		G1.Add_Edge(n + i, G1.sink, 1);
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (A[i].a >= B[j].d && dis[A[i].x][B[j].x] <= A[i].f) {
				G1.Add_Edge(i, n + j, 1);
			}
		}
	}
	G1.Dinic();
	long long res = 1e18;
	for (i = 0; i <= n; i++) {
		int f = min(n - i, G1.flow);
		res = min(res, f*K + i * H);
	}
	printf("%lld\n", res);
}