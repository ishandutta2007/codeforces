#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[101000], F[101000];
int n, m, ord[101000], cnt, Res;
int deg[101000], Q[101000];
bool v[101000];
void DFS(int a){
	v[a] = true;
	int i;
	for (i = 0; i < E[a].size(); i++){
		if (!v[E[a][i]])DFS(E[a][i]);
	}
	ord[++cnt] = a;
}
void Do(){
	int i, h = 0, t = 0, x;
	for (i = 1; i <= cnt; i++){
		if (!deg[ord[i]])Q[++t] = ord[i];
	}
	while (h < t){
		x = Q[++h];
		for (i = 0; i < F[x].size(); i++){
			deg[F[x][i]]--;
			if (!deg[F[x][i]])Q[++t] = F[x][i];
		}
	}
	if (t != cnt)Res += cnt;
	else Res += cnt - 1;
}
int main()
{
	int i, a, b;
	scanf("%d%d", &n, &m);
	while (m--){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		F[a].push_back(b);
		deg[b]++;
	}
	for (i = 1; i <= n; i++){
		if (!v[i]){
			cnt = 0;
			DFS(i);
			Do();
		}
	}
	printf("%d\n", Res);
}