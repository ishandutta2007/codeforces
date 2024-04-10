#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>

#define N_ 5100
#define M_ 1010000
#define INF 9999999
using namespace std;
int n;
struct point {
	int x, y, num;
	bool operator <(const point &p)const {
		return x != p.x ? x < p.x : y < p.y;
	}
}w[1100], ori[1100];
struct XSeg {
	int x, y1, y2, a, b;
}X[1100];
struct YSeg {
	int y, x1, x2, a, b;
}Y[1100];

vector<int>EX[1100], EY[1100];

int CX, CY;

class MaxFlow {
public:
	struct Edge {
		int b, e, f;
	}E[M_ * 2];
	vector<int>G[N_];
	int Level[N_], Q[N_], PV[N_], source, sink, n, flow, EC;
	void init(int N, int S, int T) {
		n = N, flow = EC = 0;
		for (int i = 0; i <= n; i++)G[i].clear();
		source = S, sink = T;
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
		if (a == sink)return f;
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
}G1;
void AddX(int a, int b) {
	EX[a].push_back(b);
	EX[b].push_back(a);
}
void AddY(int a, int b) {
	EY[a].push_back(b);
	EY[b].push_back(a);
}
struct Seg {
	int x1, y1, x2, y2;
};
vector<Seg>RX, RY;
int vis[1100];
int mx, my, Mx, My;
void GoX(int a) {
	vis[a] = 1;
	mx = min(mx, ori[a].x);
	my = min(my, ori[a].y);
	Mx = max(Mx, ori[a].x);
	My = max(My, ori[a].y);
	for (auto &x : EX[a]) {
		if (!vis[x])GoX(x);
	}
}
void GoY(int a) {
	mx = min(mx, ori[a].x);
	my = min(my, ori[a].y);
	Mx = max(Mx, ori[a].x);
	My = max(My, ori[a].y);
	vis[a] = 1;
	for (auto &x : EY[a]) {
		if (!vis[x])GoY(x);
	}
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d%d", &w[i].x, &w[i].y);
		w[i].num = i;
		ori[i] = w[i];
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i < n; i++) {
		if (w[i].x == w[i + 1].x) {
			X[++CX] = { w[i].x,w[i].y,w[i + 1].y,w[i].num,w[i+1].num};
		}
	}
	for (i = 1; i <= n; i++)swap(w[i].x, w[i].y);
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++)swap(w[i].x, w[i].y);
	for (i = 1; i < n; i++) {
		if (w[i].y == w[i + 1].y) {
			Y[++CY] = { w[i].y,w[i].x,w[i + 1].x,w[i].num,w[i + 1].num };
		}
	}
	G1.init(2 + CX + CY, 1 + CX + CY, 2 + CX + CY);
	for (i = 1; i <= CX; i++)G1.Add_Edge(G1.source, i, 1);
	for (i = 1; i <= CY; i++)G1.Add_Edge(CX+i, G1.sink, 1);
	for (i = 1; i <= CX; i++) {
		for (j = 1; j <= CY; j++) {
			if (1ll * (Y[j].x1 - X[i].x)*(Y[j].x2 - X[i].x) < 0 && 1ll * (X[i].y1 - Y[j].y)*(X[i].y2 - Y[j].y) < 0) {
				G1.Add_Edge(i, CX + j, 1);
			}
		}
	}
	G1.Dinic();
	G1.GetLevel();
	for (i = 1; i <= CX; i++) {
		if (G1.Level[i] != -1) {
			AddX(X[i].a, X[i].b);
		}
	}
	for (i = 1; i <= CY; i++) {
		if (G1.Level[CX + i] == -1) {
			AddY(Y[i].a, Y[i].b);
		}
	}
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			mx = my = 2e9, Mx = My = -2e9;
			GoX(i);
			RX.push_back({ mx,my,Mx,My });
		}
	}
	for (i = 1; i <= n; i++)vis[i] = 0;
	for (i = 1; i <= n; i++) {
		if (!vis[i]) {
			mx = my = 2e9, Mx = My = -2e9;
			GoY(i);
			RY.push_back({ mx,my,Mx,My });
		}
	}
	printf("%d\n", RY.size());
	for (auto &t : RY)printf("%d %d %d %d\n", t.x1, t.y1, t.x2, t.y2);
	printf("%d\n", RX.size());
	for (auto &t : RX)printf("%d %d %d %d\n", t.x1, t.y1, t.x2, t.y2);
}