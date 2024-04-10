#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int dis[110][110], nV, nE, n, m;
#define N_ 220100
#define M_ 221000
#define pii pair<int,int>
struct MaxFlow {
	vector<int>G[N_];
	struct Edge {
		int b, e;
		long long f;
	}E[M_];
	int EC, PV[N_], Q[N_], Level[N_], n, source, sink;
	long long flow, INF = 1e16;
	void init(int N, int S, int T) {
		source = S, sink = T, flow = EC = 0;
		n = N;
		for (int i = 0; i <= n; i++)G[i].clear();
	}
	void Add_Edge(int a, int b, long long f) {
		G[a].push_back(EC);
		G[b].push_back(EC + 1);
		E[EC++] = { a,b,f };
		E[EC++] = { b,a,0 };
	}
	long long BlockFlow(int a, long long f) {
		if (a == sink)return f;
		for (int &i = PV[a]; i >= 0; i--) {
			int t = G[a][i];
			if (E[t].f && Level[E[t].e] == Level[a] + 1) {
				long long ff = BlockFlow(E[t].e, min(E[t].f, f));
				if (ff) {
					E[t].f -= ff;
					E[t ^ 1].f += ff;
					return ff;
				}
			}
		}
		return 0ll;
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
		int i;
		long long t;
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
	int x, a, f, cost;
}A[110000];
struct BB {
	int d, k;
	bool operator < (const BB &p)const {
		return d < p.d;
	}
};
vector<BB>U[110];
vector<int>MX[110];
pii Ed[1010];
int K, chk[101000];
long long WW[101000];
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
	scanf("%d%d%d", &n, &m, &K);
	for (i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &A[i].x, &A[i].a, &A[i].f, &A[i].cost);
	}
	for (i = 1; i <= m; i++) {
		int x, d, k;
		scanf("%d%d%d", &x, &d, &k);
		U[x].push_back({ d,k });
	}
	for (i = 1; i <= nV; i++) {
		int sz = U[i].size();
		if (!sz)continue;
		MX[i].resize(sz);
		sort(U[i].begin(), U[i].end());
		for (j = 0; j < sz; j++) {
			MX[i][j] = U[i][j].k;
			if (j)MX[i][j] = max(MX[i][j], MX[i][j - 1]);
		}
	}
	for (i = 1; i <= n; i++) {
		long long z = -1e16;
		for (j = 1; j <= nV; j++) {
			if (U[j].empty() || A[i].f < dis[A[i].x][j])continue;
			BB tp = { A[i].a + 1,0 };
			int pv = lower_bound(U[j].begin(), U[j].end(), tp) - U[j].begin();
			if (!pv)continue;
			z = max(z, 0ll + MX[j][pv - 1] - A[i].cost);
		}
		WW[i] = z;
	}
	for (i = 0; i < K; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Ed[i] = { a,b };
		chk[a] = chk[b] = 1;
	}
	long long sum = 0;
	G1.init(n + 2, n + 1, n + 2);
	long long BS = 1e10, tt = 0;
	for (i = 1; i <= n; i++) {
		if (!chk[i]) {
			sum += max(WW[i], 0ll);
		}
		else {
			tt += BS;
			G1.Add_Edge(G1.source, i, BS);
			G1.Add_Edge(i, G1.sink, BS - WW[i]);
		}
	}
	for (i = 0; i < K; i++) {
		G1.Add_Edge(Ed[i].first, Ed[i].second, G1.INF);
	}
	G1.Dinic();
	printf("%lld\n", sum + tt - G1.flow);
}