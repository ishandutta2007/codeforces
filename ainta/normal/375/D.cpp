#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 100100
struct A{
	int a, b, c;
	bool operator <(const A &p)const{
		return a < p.a;
	}
}tp;
vector<int>E[N_];
vector<A>P[400];
int n, m, C[N_], ren[N_], ed[N_], cnt, res[N_], TP[N_], TP2[N_];
void DFS(int a, int p){
	int i;
	ren[a] = ++cnt;
	for (i = 0; i < E[a].size(); i++){
		if (p != E[a][i]){
			DFS(E[a][i], a);
		}
	}
	ed[ren[a]] = cnt;
}
int Do(int b, int e, int x){
	int i, r;
	for (i = b; i <= e; i++)++TP[++TP2[C[i]]];
	r = TP[x];
	for (i = b; i <= e; i++)TP[TP2[C[i]]--]--;
	return r;
}
int main()
{
	int i, a, b, j, pv1, pv2;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)scanf("%d", &C[i]);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, -1);
	for (i = 1; i <= n; i++)TP[ren[i]] = C[i];
	for (i = 1; i <= n; i++)C[i] = TP[i], TP[i] = 0;
	for (i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		if (ed[ren[a]] - ren[a] <= 300)res[i] = Do(ren[a], ed[ren[a]], b);
		else{
			tp.a = ren[a], tp.b = b, tp.c = i;
			P[ren[a] / 300].push_back(tp);
		}
	}
	for (i = 0; i <= n / 300; i++){
		if (P[i].empty())continue;
		sort(P[i].begin(), P[i].end());
		pv1 = pv2 = (i + 1) * 300;
		pv1--;
		for (j = P[i].size() - 1; j >= 0;j--){
			tp = P[i][j];
			while (pv1 >= tp.a)++TP[++TP2[C[pv1--]]];
			while (pv2 <= ed[tp.a])++TP[++TP2[C[pv2++]]];
			res[tp.c] = TP[tp.b];
		}
		a = P[i][0].a, b = ed[a];
		for (j = a; j <= b; j++){
			TP[TP2[C[j]]--]--;
		}
	}
	for (i = 0; i < m; i++)printf("%d\n", res[i]);
}