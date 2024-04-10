#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[301000];
char inp2[301000];
int ord[601000][19], par[301000][19], n, Dep[301000];
void DFS(int a, int pp){
	par[a][0] = pp;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp){
			Dep[E[a][i]] = Dep[a] + 1;
			DFS(E[a][i], a);
		}
	}
}
struct Order2{
	int num, a, b;
	bool operator<(Order2 &p)const{
		return a != p.a ? a < p.a : b < p.b;
	}
}TP[601000];
void Make_List(){
	int i, j, cnt;
	for (i = 0; i < 18; i++){
		for (j = 1; j <= n; j++){
			par[j][i + 1] = par[par[j][i]][i];
			TP[j].num = j, TP[j].a = ord[j][i];
			TP[j + n].num = j + n, TP[j + n].b = ord[j + n][i];
			if (par[j][i] == 0) TP[j].b = TP[j + n].a = 0;
			else TP[j].b = ord[par[j][i]][i], TP[j + n].a = ord[par[j][i] + n][i];
		}
		sort(TP + 1, TP + 2 * n + 1);
		cnt = 0;
		for (j = 1; j <= 2 * n; j++){
			if (j == 1 || TP[j].a != TP[j - 1].a || TP[j].b != TP[j - 1].b)cnt++;
			ord[TP[j].num][i + 1] = cnt;
		}
	}
}
int Up(int a, int d){
	int i = 0;
	while (d){
		if (d & 1)a = par[a][i];
		d >>= 1; i++;
	}
	return a;
}
int LCA(int a, int b){
	if (Dep[a] < Dep[b])swap(a, b);
	int i;
	a = Up(a, Dep[a] - Dep[b]);
	for (i = 18; i >= 0; i--){
		if (par[a][i] != par[b][i])a = par[a][i], b = par[b][i];
	}
	if (a != b)a = par[a][0];
	return a;
}
int LCP(int a, int b, int d){
	if (d == 0)return 0;
	int i, r = 0, t1, t2;
	for (i = 18; i >= 0; i--){
		if (r + (1 << i) > d)continue;
		if (a > n) t1 = Up(a - n, d - r - (1 << i)) + n;
		else t1 = a;
		if (b > n) t2 = Up(b - n, d - r - (1 << i)) + n;
		else t2 = b;
		if (ord[t1][i] == ord[t2][i]){
			if (a <= n) a = par[a][i];
			if (b <= n) b = par[b][i];
			r += (1 << i);
		}
	}
	return r;
}
int Pro(int a, int b, int c, int d){
	int L1 = LCA(a, b), L2 = LCA(c, d);
	if (Dep[a] - Dep[L1] < Dep[c] - Dep[L2]){
		return Pro(c, d, a, b);
	}
	int d1, d2, v1, v2, r, S = 0;
	r = LCP(a, c, Dep[c] - Dep[L2]);
	if (r != Dep[c] - Dep[L2])return r;
	S += r;
	v1 = Up(a, Dep[c] - Dep[L2]);
	d1 = Dep[v1] - Dep[L1] + 1;
	d2 = Dep[d] - Dep[L2] + 1;
	if (d1 >= d2){
		return S + LCP(v1, d + n, d2);
	}
	v2 = Up(d, d2 - d1);
	r = LCP(v1, v2 + n, d1);
	if (r != d1)return S + r;
	S += r;
	d1 = Dep[b] - Dep[L1];
	d2 = Dep[d] - Dep[v2];
	if (d1 >= d2){
		v1 = Up(b, d1 - d2);
		return S + LCP(v1 + n, d + n, d2);
	}
	v2 = Up(d, d2 - d1);
	return S + LCP(b + n, v2 + n, d1);
}
int main()
{
	int i, a, b, Q, c, d;
	scanf("%d", &n);
	scanf("%s", inp2 + 1);
	for (i = 1; i <= n; i++)ord[i][0] = ord[i + n][0] = inp2[i] - 'a' + 1;
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	Make_List();
	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n",Pro(a, b, c, d));
	}
	return 0;
}