#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define N_ 200010
#define INF 99999999999999999LL

vector<int>E[N_];

int n, Q;
int Dep[N_];
int par[18][N_];

void DFS(int node, int dep, int pp){
	int i, x;
	Dep[node] = dep;
	par[0][node] = pp;
	for (i = 0; i < E[node].size(); i++){
		x = E[node][i];
		if (x != pp)DFS(x, dep + 1, node);
	}
}

void make_List(){
	int i, j;
	for (i = 0; i < 17; i++){
		for (j = 1; j <= n; j++)par[i + 1][j] = par[i][par[i][j]];
	}
}

int LCA(int u, int v){
	if (Dep[u] < Dep[v])return LCA(v, u);
	int d = Dep[u] - Dep[v], i = 0;
	while (d){
		if (d & 1) u = par[i][u];
		d >>= 1; i++;
	}
	for (i = 17; i >= 0; i--){
		if (par[i][u] != par[i][v])u = par[i][u], v = par[i][v];
	}
	if (u != v)u = par[0][u];
	return u;
}

int Lower(int a, int b){ // a b  ?
	if (Dep[a] < Dep[b])return b;
	return a;
}

int dist(int u, int v){ //  u v 
	int L = LCA(u, v);
	return Dep[u] + Dep[v] - 2 * Dep[L];
}

int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}

long long First(long long M, long long D, long long g){//Dx = g(mod M)     x ?
	if (g == 0)return 0;
	long long T = First(D, M%D, g%D);
	T = (g - T*M) / D;
	if (T < 0){
		T += (-T) / M*M;
		T += M;
	}
	return T % M;
}

long long SameDir(int T1, int d1, int T2, int d2, int L){ //  ,  T1 * x = d2 - d1 (mod T2)   x?
	int g = gcd(T1, T2), M = d2 - d1;
	long long TT = T1;
	if (M < 0) M = T2 + M;
	if (M % g != 0)return INF;
	T1 /= g, M /= g, T2 /= g;
	return First(T2, T1, M) * TT + d1;
}

int Gap(int M, int D, int L, int R){// L <= Dx <= R(mod M)      x ?  O(log M) .
	D %= M;
	if (D * 2 > M){
		return Gap(M, M - D, M - R, M - L);
	}
	int t = L / D, rr = M%D, q = M / D, o;
	long long a, b;
	if (L == t * D)return t;
	if (t * D + D <= R)return t + 1;
	a = Gap(D, D - rr, L%D, R%D);
	a = (a * M - 1) / D + 1;
	b = a * D % M;
	a += (R - b) / D;
	return a;
}

long long Do(int M, int D, int L, int R){// L <= Dx <= R(mod M)      x ?  
	int Res = INF;
	if (L == 0){
		Res = M / gcd(M, D);
		L = 1;
	}
	if ((L - 1) / gcd(M, D) >= R / gcd(M, D)){
		return INF;
	}
	return min(Res, Gap(M, D, L, R));
}

long long DiffDir(int T1, int d1, int T2, int d2, int L){ //   ,  d2 - d1 - L <= T1 * x <= d2 - d1 + L ( mod T2)  x?
	int be = d2 - d1 - L, ed = d2 - d1 + L;
	long long P;
	if (be < 0) be += (-be) / T2 * T2;
	if (ed < 0)ed += (-ed) / T2*T2;
	be = (be + T2) % T2, ed = (ed + T2) % T2;
	if (be & 1)return INF;
	if (T2 == L * 2){
		return d1 + ed / 2;
	}
	if (be > ed || be == 0)return d1 + ed / 2;
	P = Do(T2, T1, be, ed);
	if (P == INF)return INF;
	return T1*P + d1 + L - (P * T1 % T2 - be) / 2;
}

long long Query(int u, int v, int x, int y){
	int P1 = LCA(u, v), P2 = LCA(x, y), P3 = LCA(u, x), P4 = LCA(u, y), P5 = LCA(v, x), P6 = LCA(v, y);
	int pp, a, b, d1, d2, d3, d4, d5, d6, d;
	pp = Lower(P1, P2);
	a = Lower(P3, P4);
	b = Lower(P5, P6);
	if (Dep[a] < Dep[pp] && Dep[b] < Dep[pp])return -1;
	if (Dep[a] < Dep[pp]) a = pp;
	else if (Dep[b] < Dep[pp]) b = pp;
	d1 = dist(u, v), d4 = dist(x, y);
	d2 = dist(u, a), d3 = dist(u, b);
	d5 = dist(x, a), d6 = dist(x, b);
	d = dist(a, b);
	if (d2 <= d3) d3 = d1 * 2 - d3;
	else d2 = d1 * 2 - d2;
	if (d5 <= d6) d6 = d4 * 2 - d6;
	else d5 = d4 * 2 - d5;
	long long Res = INF;
	//d1 : u-v , d2 : x-y 
	// : a-b
	//d2, d3, d5, d6 : (u,v) - (a,b) 
	Res = min(SameDir(d1 * 2, d2, d4 * 2, d5, d), Res);
	Res = min(SameDir(d1 * 2, d3, d4 * 2, d6, d), Res);
	Res = min(DiffDir(d1 * 2, d2, d4 * 2, d6, d), Res);
	Res = min(DiffDir(d1 * 2, d3, d4 * 2, d5, d), Res);
	if (Res == INF)return -1;
	return Res;
}

void Output(){
	int u, v, x, y, T;
	scanf("%d", &Q);
	while (Q--){
		scanf("%d%d%d%d", &u, &v, &x, &y);
		printf("%lld\n", Query(u, v, x, y));
	}
}

void input(){
	int i, a, b;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

int main()
{
	input();
	DFS(1, 0, 0);
	make_List();
	Output();
}