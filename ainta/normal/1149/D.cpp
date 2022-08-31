#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N_ 10100
#define pii pair<int,int>
priority_queue<pii>PQ;
int n, m, A, B, UF[80], G[80], C[80], cc, Dis[80];
vector<int>E1[80], E2[80];
struct Edge {
	int a, b, c;
}w[220];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
int D[1 << 17][80];
int Get(int a) {
	int t = G[Find(a)];
	if (t == 0)return 0;
	return 1 << (t - 1);
}
void Put(int a, int d) {
	if (Dis[a] <= d)return;
	Dis[a] = d;
	PQ.push({ -d,a });
}
int main() {
	int i, a, b, c, j;
	scanf("%d%d%d%d", &n, &m, &A, &B);
	for (i = 1; i <= n; i++) UF[i] = i;
	for(i=1;i<=m;i++){
		scanf("%d%d%d", &a, &b, &c);
		w[i] = { a,b,c };
		if (c == A) {
			E1[a].push_back(b);
			E1[b].push_back(a);
			a = Find(a), b = Find(b);
			if (a != b)UF[a] = b;
		}
	}
	for (i = 1; i <= m; i++) {
		if (w[i].c == B && Find(w[i].a) != Find(w[i].b)) {
			E2[w[i].a].push_back(w[i].b);
			E2[w[i].b].push_back(w[i].a);
		}
	}
	for (i = 1; i <= n; i++) {
		C[Find(i)]++;
	}
	for (i = 1; i <= n; i++) {
		if (C[i] >= 4) {
			G[i] = ++cc;
		}
	}
	for (i = 0; i < (1 << cc); i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = 2e9;
		}
	}
	D[Get(1)][1] = 0;
	for (i = 0; i < (1 << cc); i++) {
		for (j = 1; j <= n; j++)Dis[j] = 2e9;
		for (j = 1; j <= n; j++) {
			Put(j, D[i][j]);
		}
		while (!PQ.empty()) {
			pii t = PQ.top();
			PQ.pop();
			int x = t.second;
			if (-t.first != Dis[x])continue;
			for (auto &y : E1[x]) {
				Put(y, Dis[x] + A);
			}
			for (auto &y : E2[x]) {
				if (Get(y) == 0) {
					Put(y, Dis[x] + B);
				}
			}
		}
		for (j = 1; j <= n; j++) D[i][j] = Dis[j];
		for (j = 1; j <= n; j++) {
			for (auto &x : E2[j]) {
				if (Get(x)&i)continue;
				int t = Get(x) | i;
				D[t][x] = min(D[t][x], D[i][j] + B);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		int res = 2e9;
		for (j = 0; j < (1 << cc); j++) {
			res = min(res, D[j][i]);
		}
		printf("%d ", res);
	}
}