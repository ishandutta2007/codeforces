#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 999999999
#define N_ 100100
int n, D[N_], par[N_], Len, pv, C[N_], res, res_n;
bool chk[N_];
vector<int>E[N_], L[N_];
void DFS(int a, int p){
	int i;
	par[a] = p;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != p){
			D[E[a][i]] = D[a] + L[a][i];
			DFS(E[a][i], a);
		}
	}
}
int DFS2(int a, int p){
	int i, r = 0, t;
	if (chk[a]){
		if (D[a] > Len) Len = D[a], pv = a;
		r = D[a];
	}
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != p){
			D[E[a][i]] = D[a] + L[a][i];
			t = DFS2(E[a][i], a);
			if (t == r && t == Len) pv = a;
			if (t > r) r = t;
		}
	}
	return r;
}
void DFS3(int a, int p, int root, int pv){
	if (chk[a])C[pv]++, C[root]--;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != p)DFS3(E[a][i], a, root, pv);
	}
}
int DFS4(int a, int p){
	int i, k = C[a];
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != p){
			k += DFS4(E[a][i], a);
		}
	}
	if (!chk[a]){
		if (res < k)res = k, res_n = 1;
		else if (res == k)res_n++;
	}
	return k;
}
int main(){
	int m, a, i, b, c, t;
	scanf("%d%d", &n, &m);
	while (m--){
		scanf("%d", &a);
		C[a]++;
		chk[a] = true;
	}
	for (i = 1; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b); L[a].push_back(c);
		E[b].push_back(a); L[b].push_back(c);
	}
	DFS(a, -1);
	b = 0;
	for (i = 1; i <= n; i++)if (chk[i] && b < D[i])b = D[i], a = i;
	D[a] = 0;
	DFS(a, -1);
	b = 0;
	for (i = 1; i <= n; i++)if (chk[i] && b < D[i])b = D[i], c = i;
	b = INF;
	a = c;
	while (a != -1){
		if (abs(D[c] - D[a] * 2) < b)b = abs(D[c] - D[a] * 2), t = a;
		a = par[a];
	}
	a = t;
	int LL = 0, LL2 = 0, pp2 = -1, p[2], pp[2];
	c = 0;
	for (i = 0; i < E[a].size(); i++){
		D[E[a][i]] = L[a][i];
		Len = 0;
		DFS2(E[a][i], a);
		if (LL < Len){
			LL2 = LL;
			if (c != 1)pp2 = -1;
			else pp2 = pp[0];
			LL = Len, c = 0;
			p[c] = E[a][i];
			pp[c++] = pv;
		}
		else if (LL == Len){
			if (c == 1)p[c] = E[a][i], pp[c] = pv;
			c++;
		}
		else if (LL2 < Len)LL2 = Len, pp2 = pv;
		else if (LL2 == Len)pp2 = -1;
	}
	if (c == 2){
		DFS3(p[0], a, a, pp[1]);
		DFS3(p[1], a, a, pp[0]);
	}
	if (c == 1){
		for (i = 0; i < E[a].size(); i++){
			if (p[0] != E[a][i]){
				DFS3(E[a][i], a, a, pp[0]);
			}
		}
		if (chk[a])C[pp[0]]++;
		if (LL2 && pp2 != -1)DFS3(p[0], a, a, pp2);
	}
	res = -1;
	DFS4(a, -1);
	printf("%d %d\n", res, res_n);
}