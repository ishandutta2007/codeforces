#include <bits/stdc++.h>
#define PII pair <int, int>
#define x first
#define y second
#define M 300010

using namespace std;

int n, q, Deg[M], Dep[M], mxdep = 0;

PII Fa1[M], Ch1[M], Ch2[M];

int Bel[M], Lim[M], Fa2[M];

int Real[M][26], Self[M][26], qwq[M][26], Sum[M], Sumqwq[M], num_1 = 0;

int DFS(int x, int dep) {
	Dep[x] = dep, mxdep = max(mxdep, dep);
	if(Ch1[x].x) Ch2[x].x = DFS(Ch1[x].x, dep + 1);
	if(Ch1[x].y) Ch2[x].y = DFS(Ch1[x].y, dep + 1);
	if(Deg[x] == 0 || Deg[x] == 2) {
		if(Deg[x] == 2) Fa2[Ch2[x].x] = x, Fa2[Ch2[x].y] = x;
		return Bel[x] = x;
	} else return Bel[x] = Bel[Ch1[x].x];
}

int chg(int x) {return x == '?' ? -1 : x - 'a';}

void add(int x, int v) {
	int w = Fa1[x].y;
	x = Bel[x];
	Self[x][w] += v;
	Real[x][w] += v;
	for(int i = Fa2[x]; i; i = Fa2[i]) {
		if(Sumqwq[i] > mxdep - Dep[i]) num_1--;
		Sumqwq[i] -= qwq[i][w];
		qwq[i][w] = max(Real[Ch2[i].x][w], Real[Ch2[i].y][w]);
		Real[i][w] = qwq[i][w] + Self[i][w];
		if((Sumqwq[i] += qwq[i][w]) > mxdep - Dep[i]) num_1++;
	}
}

void getans() {
	if(num_1) {
		puts("Fou");
		return;
	}
	int ans = 0;
	for(int i = 0; i < 26; i++) ans += (i + 1) * Real[1][i];
	ans += (mxdep - Sumqwq[1]) * 13 * 27;
	printf("Shi %d\n", ans);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; i++) {
		int a;
		char ch[7];
		scanf("%d%s", &a, ch);
		Fa1[i] = PII(a, chg(ch[0]));
		if(!Ch1[a].x) Ch1[a].x = i; else Ch1[a].y = i;
		Deg[a]++;
	}
	DFS(1, 0);
	if(Deg[1] == 1) {Deg[1] = 2, Ch2[1].y = 0, Fa2[Ch2[1].x] = 1;}
	for(int i = 1; i <= n; i++) if(Deg[i] == 0 && Dep[i] != mxdep) {
		for(int i = 1; i <= q; i++) puts("Fou");
		return 0;
	}
	Fa2[1] = 0;
	for(int i = 2; i <= n; i++) if(Fa1[i].y != -1) add(i, 1);
	for(int i = 1; i <= q; i++) {
		int a;
		char ch[7];
		scanf("%d%s", &a, ch);
		if(Fa1[a].y != -1) add(a, -1);
		if((Fa1[a].y = chg(ch[0])) != -1) add(a, 1);
		getans();
	}
	return 0;
}