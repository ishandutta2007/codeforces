#include<stdio.h>
#include<algorithm>
#include<vector>
#define INF 999999999999999LL
#define SZ 131072
using namespace std;
vector<int>E[101000], L[101000];
int n, Ck[101000];
long long D[101000][2];
void DFS(int nd, int pp, long long d, int ck){
	D[nd][ck] = d;
	int i;
	for (i = 0; i < E[nd].size(); i++){
		if (E[nd][i] != pp)DFS(E[nd][i], nd, d + L[nd][i], ck);
	}
}
int get_far(int a, int ck){
	int i, x;
	long long MX = -1;
	DFS(a, 0, 0, ck);
	for (i = 1; i <= n; i++){
		if (MX < D[i][ck])MX = D[i][ck], x = i;
	}
	return x;
}
int par[101000], UF[101000], C[101000];
void DFS2(int a, int pp, int ck){
	par[a] = pp;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != pp && Ck[E[a][i]] == ck){
			DFS2(E[a][i], a, ck);
		}
	}
}
struct point{
	long long d;
	int num;
	bool operator<(const point &p)const{
		return d < p.d;
	}
}w[101000];
int Find(int a){
	if (a == UF[a])return a;
	return UF[a] = Find(UF[a]);
}
void Del(int a){
	a = Find(a);
	C[a]--;
}
int Res;
void Add(int a){
	int i, S = 1;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != par[a] && Ck[E[a][i]] == Ck[a]){
			S += C[E[a][i]];
			C[E[a][i]] = 0;
			UF[E[a][i]] = a;
		}
	}
	C[a] = S;
	Res = max(Res, C[a]);
}
int main(){
	int i, a, b, d, Q;
	int P1, P2;
	scanf("%d", &n);
	for (i = 1; i < n; i++){
		scanf("%d%d%d", &a, &b, &d);
		E[a].push_back(b);
		E[b].push_back(a);
		L[a].push_back(d);
		L[b].push_back(d);
	}
	P1 = get_far(1, 0);
	P2 = get_far(P1, 0);
	get_far(P2, 1);
	long long Mn1 = INF, Mn2 = INF, LL;
	int R1, R2, pv;
	for (i = 1; i <= n; i++){
		if (D[i][0] < D[i][1]){
			Ck[i] = 2;
			if (Mn2 > D[i][1])Mn2 = D[i][1], R2 = i;
		}
		else{
			Ck[i] = 1;
			if (Mn1 > D[i][0])Mn1 = D[i][0], R1 = i;
		}
	}
	DFS2(R1, 0, 1);
	DFS2(R2, 0, 2);
	for (i = 1; i <= n; i++){
		w[i].num = i;
		w[i].d = D[i][Ck[i] - 1];
	}
	sort(w + 1, w + n + 1);
	scanf("%d", &Q);
	while (Q--){
		scanf("%lld", &LL);
		pv = n;
		for (i = 1; i <= n; i++){
			UF[i] = i;
			C[i] = 1;
		}
		Res = 0;
		for (i = n; i >= 1; i--){
			while (w[pv].d - w[i].d > LL){
				Del(w[pv].num);
				pv--;
			}
			Add(w[i].num);
		}
		Res = max(Res, C[R1] + C[R2]);
		printf("%d\n", Res);
	}
}