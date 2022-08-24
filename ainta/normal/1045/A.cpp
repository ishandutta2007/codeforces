#include<cstdio>
#include<algorithm>
#include<vector>
#define N_ 101000
#define M_ 2001000
#define INF 999999
#define pii pair<int,int>
using namespace std;
int chkk[N_];
vector<pii>V;
class MaxFlow {
public:
	struct Edge {
		int b, e, f;
	}E[M_ * 2];
	vector<int>G[N_];
	int Level[N_], Q[N_], PV[N_], source, sink, n, flow, EC;
	void init(int N, int S, int T) {
		n = N, flow = EC = 0;
		source = S, sink = T;
		for (int i = 0; i <= n; i++)G[i].clear();
	}
	void Add_Edge(int a, int b, int f) {
		G[a].push_back(EC);
		G[b].push_back(EC + 1);
		E[EC++] = { a,b,f };
		E[EC++] = { b,a,0 };
	}
	bool GetLevel() {
		int i;
		for (i = 1; i <= n; i++)Level[i] = -1;
		int head = 0, tail = 0;
		Q[++tail] = source, Level[source] = 0;
		while (head < tail) {
			int x = Q[++head];
			for (auto &y : G[x]) {
				if (E[y].f && Level[E[y].e] == -1) {
					Q[++tail] = E[y].e;
					Level[E[y].e] = Level[x] + 1;
				}
			}
		}
		return Level[sink] != -1;
	}
	int BlockFlow(int a, int f) {
		if (a == sink) {
			return f;
		}
		for (int &i = PV[a]; i >= 0; i--) {
			int x = G[a][i];
			if (E[x].f && Level[E[x].e] == Level[a] + 1) {
				int t = BlockFlow(E[x].e, min(f, E[x].f));
				if (t) {
					E[x].f -= t;
					E[x ^ 1].f += t;
					return t;
				}
			}
		}
		return 0;
	}
	void Dinic() {
		int t;
		while (GetLevel()) {
			for (int i = 1; i <= n; i++)PV[i] = G[i].size() - 1;
			while (t = BlockFlow(source, INF)) flow += t;
		}
	}
	int t1, t2;
	bool DFS(int a) {
		if (chkk[a] == 1)t1 = a;
		if (chkk[a] == 2)t2 = a;
		if (a == source) {
			V.push_back({ t1,t2 });
			return true;
		}
		for (auto &t : G[a]) {
			if (E[t].f) {
				E[t].f--;
				if (DFS(E[t].e))return true;
				E[t].f++;
			}
		}
		return false;
	}
	void GetPath() {
		while (DFS(sink));
	}
}G1;
int n, m, Num[5010], cnt, SZ = 8192, U[5010][3], Mat[5010], ord[5010];
int main() {
	int i, ck, c, a, b, e;
	scanf("%d%d", &n, &m);
	G1.init(50000, 49999, 50000);
	for (i = 1; i <= n; i++) {
		scanf("%d", &ck);
		if (!ck) {
			G1.Add_Edge(G1.source, i, 1);
			scanf("%d", &c);
			while (c--) {
				scanf("%d", &a);
				G1.Add_Edge(i, n + SZ + a, 1);
			}
		}
		if (ck == 1) {
			G1.Add_Edge(G1.source, i, 1);
			scanf("%d%d", &b, &e);
			b += SZ, e += SZ;
			while (b <= e) {
				if (b & 1)G1.Add_Edge(i, n + b, 1);
				if (!(e & 1))G1.Add_Edge(i, n + e, 1);
				b = (b + 1) >> 1, e = (e - 1) >> 1;
			}
		}
		if (ck == 2) {
			cnt++;
			scanf("%d%d%d", &a, &b, &c);
			U[cnt][0] = a, U[cnt][1] = b, U[cnt][2] = c;
			Num[a] = Num[b] = Num[c] = cnt;
			ord[cnt] = i;
		}
	}
	for (i = 1; i <= n; i++)chkk[i] = 1;
	for (i = 1; i <= m; i++)chkk[SZ + n + i] = 2;
	for (i = 1; i < SZ; i++) {
		G1.Add_Edge(n + i, n + i * 2, INF);
		G1.Add_Edge(n + i, n + i * 2 + 1, INF);
	}
	for (i = 1; i <= m; i++) {
		if (!Num[i])G1.Add_Edge(n + SZ + i, G1.sink, 1);
		else {
			G1.Add_Edge(n + SZ + i, n + SZ + SZ + Num[i], 1);
		}
	}
	for (i = 1; i <= cnt; i++) {
		G1.Add_Edge(n + SZ + SZ + i, G1.sink, 1);
	}
	G1.Dinic();
	printf("%d\n", G1.flow + cnt * 2);
	G1.GetPath();
	for (auto &t : V) {
		Mat[t.second - n - SZ] = t.first;
	}
	for (i = 1; i <= cnt; i++) {
		int c = 0;
		for (int j = 0; j < 3; j++) {
			if (!Mat[U[i][j]] && c < 2) {
				c++;
				Mat[U[i][j]] = ord[i];
			}
		}
	}
	int cc = 0;
	for (i = 1; i <= m; i++) {
		if (Mat[i]) {
			printf("%d %d\n", Mat[i], i);
		}
	}
}