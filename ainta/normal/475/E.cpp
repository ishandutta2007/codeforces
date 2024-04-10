#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
bool E[2010][2010], P[2010][2010], v[2010];
int n, m, cnt, num[2010], SCC[2010], C[2010], Res, C2[2010], Sum;
vector<int>Ed[2010];
int DFS(int a,int par){
	int i, pp, t;
	num[a] = ++cnt;
	pp = cnt;
	for (i = 1; i <= n; i++){
		if (E[a][i]){
			if (i == par)continue;
			if (!num[i]){
				t = DFS(i, a);
			}
			else t = num[i];
			if (pp > t)pp = t;
		}
	}
	if (pp == num[a]){
		if (par != -1){
			P[a][par] = P[par][a] = true;
		}
	}
	return pp;
}
void DFS2(int a){
	int i;
	SCC[a] = cnt;
	C[cnt]++;
	for (i = 1; i <= n; i++){
		if (E[a][i] && !SCC[i])DFS2(i);
	}
}
void DFS3(int a, int Dep){
	v[a] = true;
	C2[a] = C[a];
	Sum += C[a] * Dep;
	int i;
	for (i = 0; i < Ed[a].size(); i++){
		if (!v[Ed[a][i]]){
			DFS3(Ed[a][i], Dep + C[a]);
			C2[a] += C2[Ed[a][i]];
		}
	}
}
bool DP[2010];
void Do(int a){
	int i, j, x, M;
	for (i = 1; i <= cnt; i++)v[i] = false;
	Sum = 0;
	DFS3(a, 0);
	for (i = 1; i <= n; i++)DP[i] = false;
	DP[0] = true;
	for (i = 0; i < Ed[a].size(); i++){
		x = C2[Ed[a][i]];
		for (j = n - x; j >= 0; j--){
			if (DP[j])DP[j + x] = true;
		}
	}
	M = 0;
	for (i = 0; i <= n-C[a]; i++){
		if (DP[i] && i*(n - C[a] - i)>M)M = i*(n - C[a] - i);
	}
	if (Res < Sum + M)Res = Sum + M;
}
int main()
{
	int i, a, b, j;
	scanf("%d%d", &n,&m);
	while (m--){
		scanf("%d%d", &a, &b);
		E[a][b] = E[b][a] = true;
	}
	DFS(1, -1);
	for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (P[i][j])E[i][j] = false;
	cnt = 0;
	for (i = 1; i <= n; i++){
		if (!SCC[i]){
			cnt++;
			DFS2(i);
		}
	}
	for (i = 1; i <= n; i++)for (j = 1; j <= n; j++)if (P[i][j])Ed[SCC[i]].push_back(SCC[j]);
	for (i = 1; i <= cnt; i++)Do(i);
	for (i = 1; i <= cnt; i++){
		Res += C[i] * C[i];
	}
	printf("%d\n", Res);
	return 0;
}