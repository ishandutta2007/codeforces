#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000];
vector<long long>L[101000];
int n, Count[101000], Num[101000], cnt, par[101000], pp[18][101000];
long long Mod = 1000000007, D[101000], D2[101000], T[101000], T2[101000], pL[101000], DL[101000];
int Dep[101000];
void DFS(int a, int pp){
	Num[a] = ++cnt;
	int i, x, y;
	x = Num[a];
	Count[x]++;
	par[x] = Num[pp];
	for (i = 0; i < E[a].size(); i++){
		if (pp != E[a][i]){
			DFS(E[a][i], a);
			y = Num[E[a][i]];
			pL[y] = L[a][i];
			Count[x] += Count[y];
			D[x] = (D[x] + D[y] + L[a][i] * Count[y]) % Mod;
			D2[x] = (D2[x] + D2[y] + L[a][i] * L[a][i] % Mod*Count[y] + 2 * L[a][i] * D[y]) % Mod;
		}
	}
}
void Pro(){
	int i, p;
	long long X, Y;
	T[1] = D[1];
	for (i = 2; i <= n; i++){
		p = par[i];
		DL[i] = DL[p] + pL[i];
		Dep[i] = Dep[p] + 1;
		X = Count[i];
		Y = n - Count[i];
		T[i] = (T[p] + (Y - X + Mod) % Mod*pL[i]) % Mod;
	}
}
void Pro2(){
	int i;
	long long Gap1, Gap2, X, Y, p;
	T2[1] = D2[1];
	for (i = 2; i <= n; i++){
		p = par[i];
		X = Count[i], Y = n - Count[i];
		Gap1 = ((T[i] - D[i] - pL[i]*Y%Mod + Mod * 2) % Mod * 2 * pL[i] + pL[i] * pL[i] % Mod*Y) % Mod;
		Gap2 = (D[i] * 2 * pL[i] % Mod + pL[i] * pL[i] % Mod*X) % Mod;
		T2[i] = (T2[p] + Gap1 - Gap2 + Mod) % Mod;
	}
}
void PrePro(){
	int i, j;
	for (i = 1; i <= n; i++)pp[0][i] = par[i];
	for (i = 0; i < 17; i++){
		for (j = 1; j <= n; j++){
			pp[i + 1][j] = pp[i][pp[i][j]];
		}
	}
}
int LCA(int a, int b){
	if (Dep[a] < Dep[b])return LCA(b, a);
	int d = Dep[a] - Dep[b], i = 0;
	while (d){
		if (d & 1)a = pp[i][a];
		d >>= 1;
		i++;
	}
	for (i = 17; i >= 0; i--){
		if (pp[i][a] != pp[i][b]){
			a = pp[i][a], b = pp[i][b];
		}
	}
	if (a != b)a = pp[0][a], b = pp[0][b];
	return a;
}
long long dist(int a, int b){
	int ppp = LCA(a, b);
	return (DL[a] + DL[b] - DL[ppp] * 2 + Mod * 2) % Mod;
}
long long Solve2(int a, int b){
	long long d = dist(a, b);
	long long r = (D2[b] + 2 * d*D[b] % Mod + d*d%Mod*Count[b]) % Mod;
	return (r * 2 - T2[a] + Mod) % Mod;
}
long long Solve1(int a, int b){
	long long d = dist(a, b);
	long long r = ((T2[b] - D2[b] + Mod) % Mod + (T[b] - D[b] + Mod) % Mod * 2 * d%Mod + d*d%Mod*(n - Count[b])) % Mod;
	return (T2[a] - r * 2 + Mod * 2) % Mod;
}
void Output(){
	int Q, a, b;
	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d", &a, &b);
		a = Num[a], b = Num[b];
		if (LCA(a, b) == b){
			printf("%lld\n", Solve1(a, b));
		}
		else{
			printf("%lld\n", Solve2(a, b));
		}
	}
}
int main()
{
	int i, a, b, c;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d%d", &a, &b, &c);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(c);
		L[b].push_back(c);
	}
	DFS(1, 0);
	Pro();
	Pro2();
	PrePro();
	Output();
	return 0;
}