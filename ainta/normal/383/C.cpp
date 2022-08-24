#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 201000
#define SZ 262144
int n, Dep[N_], P[N_], IT[2][SZ*2+1], renum[N_], ed[N_], C;
bool v[N_];
vector<int>E[N_];
void DFS(int a, int depth){
	renum[a] = ++C;
	Dep[a] = depth;
	v[a] = true;
	int i, x;
	for (i = 0; i < E[a].size(); i++){
		x = E[a][i];
		if (!v[x]){
			DFS(x,depth+1);
		}
	}
	ed[renum[a]] = C;
}
int Sum(int x, int a){
	int r = 0;
	while (a){
		r += IT[x][a];
		a >>= 1;
	}
	return r;
}
void Add(int x, int b, int e, int k){
	while (b <= e){
		if (b & 1)IT[x][b] += k;
		if (!(e & 1))IT[x][e] += k;
		b = (b + 1) >> 1, e = (e - 1) >> 1;
	}
}
int main()
{
	int i, a, b, Q, ck;
	scanf("%d%d", &n,&Q);
	for (i = 1; i <= n; i++){
		scanf("%d", &P[i]);
	}
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(1, 0);
	for (i = 1; i <= n; i++){
		IT[Dep[i]%2][SZ + renum[i]] = P[i];
	}
	while (Q--){
		scanf("%d%d", &ck, &a);
		if (ck == 2){
			printf("%d\n", Sum(Dep[a]%2, SZ+renum[a]));
		}
		else{
			scanf("%d", &b);
			Add(Dep[a] % 2, SZ + renum[a], SZ + ed[renum[a]], b);
			Add(1 - (Dep[a] % 2), SZ + renum[a], SZ + ed[renum[a]], -b);
		}
	}
}