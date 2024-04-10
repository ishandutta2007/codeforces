#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
int n, m, par[2010], vis[2010], Q[2010], head, tail, UF[2010];
char p[2010][2010];
vector<int>E[2010];
bitset<2001>B[2001], BB[2001], U[2010], V[2010];
int Find(int a) {
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Del(int a) {
	int x = par[a];
	while (vis[x]) {
		x = par[x];
	}
	V[x] |= V[a];
	for (int i = 0; i < m; i++) {
		if (B[x][i]) {
			if (!(U[i] & (~V[x])).count()) {
				B[x][i] = 0;
			}
		}
	}
	int i;
	for (i = 1; i <= n; i++) {
		if (Find(i)!=x  && (B[x] & (~BB[i])).count() == 0) {
			vis[x] = 1;
			par[x] = i;
			UF[x] = Find(i);
			Q[++tail] = x;
			break;
		}
	}
}
void DFS(int pv, int a, int pp) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (x == pp || p[pv][x] != '1')continue;
		DFS(pv, x, a);
	}
}
int cc = 0;
void Solve() {
	cc++;
	int i, j;
	head = tail = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		E[i].clear();
		B[i].reset();
		BB[i].reset();
		V[i].reset();
		V[i][i] = 1;
	}
	for (i = 0; i < m; i++) {
		U[i].reset();
		scanf("%s", p[i]+1);
//		if(cc==741)fprintf(stderr,"%s\n", p[i]+1);
		int cc = 0;
		for (j = 1; j <= n; j++) {
			if (p[i][j] == '0')BB[j][i] = B[j][i] = 0, U[i][j]=0;
			else BB[j][i] = B[j][i] = 1, cc++, U[i][j]=1;
		}
		if (cc == 1) {
			for (j = 1; j <= n; j++)BB[j][i] = B[j][i] = 0, U[i][j] = 0;
		}
	}
	if (cc == 741) {
		int tt = -1;
	}
	for (i = 1; i <= n; i++) {
		vis[i] = 0; par[i] = UF[i] = i;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (Find(j) == i)continue;
			if (!(B[i] & ~B[j]).count()) {
				par[i] = j;
				UF[i] = j;
				vis[i] = 1;
				Q[++tail] = i;
				break;
			}
		}
	}
	while (head < tail) {
		int x = Q[++head];
		Del(x);
	}
	int cc = 0;
	for (i = 1; i <= n; i++) {
		if (par[i]!=i) {
			cc++;
			E[par[i]].push_back(i);
			E[i].push_back(par[i]);
		}
	}
	if (cc != n - 1) {
		puts("NO");
		return;
	}
	for (i = 0; i < m; i++) {
		for (j = 1; j <= n; j++)vis[j] = 0;
		for (j = 1; j <= n; j++) {
			if (p[i][j] == '1') {
				DFS(i, j, 0);
				break;
			}
		}
		for (j = 1; j <= n; j++)if (!vis[j] && p[i][j] == '1') {
			puts("NO");
			return;
		}
	}
	puts("YES");
	for (i = 1; i <= n; i++)if (par[i]!=i)printf("%d %d\n", par[i], i);
}

int main() {
	int TC, i, j, k;
	int DEBUG = 0;
	if(DEBUG){
		srand(1879);
		freopen("input.txt", "w", stdout);
		printf("%d\n", 1000);
		for (i = 0; i < 1000; i++) {
			printf("%d %d\n", 7, 10);
			for (j = 0; j < 10; j++) {
				for(k=0;k<7;k++)printf("%d", rand() % 2);
				puts("");
			}
		}
		return 0;
	}
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}
/*

#include<cstdio>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
int n, m, par[2010], vis[2010], Q[2010], head, tail;
char p[2010][2010];
vector<int>E[2010];
bitset<2000>B[2001], BB[2001];
void Del(int a) {
	int x = par[a];
	B[x] ^= B[x] & BB[a];
	if (vis[x])return;
	int i;
	for (i = 1; i <= n; i++) {
		if (!vis[i] && i != x && (B[x] & (~BB[i])).count() == 0) {
			vis[x] = 1;
			par[x] = i;
			Q[++tail] = x;
			break;
		}
	}
}
void DFS(int pv, int a, int pp) {
	vis[a] = 1;
	for (auto &x : E[a]) {
		if (x == pp || p[pv][x] != '1')continue;
		DFS(pv, x, a);
	}
}
void Solve() {
	int i, j;
	head = tail = 0;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		E[i].clear();
		B[i].reset();
	}
	for (i = 0; i < m; i++) {
		scanf("%s", p[i] + 1);
		int cc = 0;
		for (j = 1; j <= n; j++) {
			if (p[i][j] == '0')B[j][i] = 0;
			else B[j][i] = 1, cc++;
		}
		if (cc == 1) {
			for (j = 1; j <= n; j++)B[j][i] = 0;
		}
	}
	for (i = 1; i <= n; i++)BB[i] = B[i];
	for (i = 1; i <= n; i++)vis[i] = par[i] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j)continue;
			if (vis[j])continue;
			if (!(B[i] & ~B[j]).count()) {
				par[i] = j;
				vis[i] = 1;
				break;
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (vis[i])Del(i);
	}
	while (head < tail) {
		int x = Q[++head];
		Del(x);
	}
	int cc = 0;
	for (i = 1; i <= n; i++) {
		if (par[i]) {
			cc++;
			E[par[i]].push_back(i);
			E[i].push_back(par[i]);
		}
	}
	if (cc != n - 1) {
		puts("NO");
		return;
	}
	for (i = 0; i < m; i++) {
		for (j = 1; j <= n; j++)vis[j] = 0;
		for (j = 1; j <= n; j++) {
			if (p[i][j] == '1') {
				DFS(i, j, 0);
				break;
			}
		}
		for (j = 1; j <= n; j++)if (!vis[j] && p[i][j] == '1') {
			puts("NO");
			return;
		}
	}
	puts("YES");
	//for (i = 1; i <= n; i++)if (par[i])printf("%d %d\n", par[i], i);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
	int TC, cc = 0;
	scanf("%d", &TC);
	while (TC--) {
		cc++;
		if (cc == 741) {
			int tt = -1;
		}
		Solve();
	}
}*/