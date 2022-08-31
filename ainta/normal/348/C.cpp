#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define N_ 100010
vector<int>E[N_];
int n, m, Q, D[210][N_], C, heavy[210], cnt[N_], ord[N_];
long long S[210], w[N_], res, S2[210];
bool v[N_];
int main()
{
	int i, j, t, k, a, b;
	char p[2];
	scanf("%d%d%d", &n, &m, &Q);
	for (i = 1; i <= n; i++){
		scanf("%d", &j);
		w[i] = j;
	}
	for (i = 1; i <= m; i++){
		scanf("%d", &t);
		cnt[i] = t;
		if (t >= 500){
			heavy[++C] = i;
			ord[i] = C;
		}
		while (t--){
			scanf("%d", &j);
			E[i].push_back(j);
		}
	}
	for (i = 1; i <= C; i++){
		t = heavy[i];
		for (j = 0; j < cnt[t]; j++)v[E[t][j]] = true;
		for (j = 1; j <= m; j++)for (k = 0; k < cnt[j]; k++)if (v[E[j][k]])D[i][j]++;
		for (j = 0; j < cnt[t]; j++){
			v[E[t][j]] = false;
			S2[i] += w[E[t][j]];
		}
	}
	while (Q--){
		scanf("%s", p);
		if (p[0] == '?'){
			scanf("%d", &a);
			res = 0;
			for (i = 1; i <= C; i++)res += S[i] * D[i][a];
			if (cnt[a] < 500)for (i = 0; i < cnt[a]; i++)res += w[E[a][i]];
			else res += S2[ord[a]];
			printf("%lld\n", res);
			continue;
		}
		scanf("%d%d", &a, &b);
		if (cnt[a] < 500){
			for (i = 0; i < cnt[a]; i++)w[E[a][i]] += b;
			for (i = 1; i <= C; i++)S2[i] += (long long)b * D[i][a];
		}
		else S[ord[a]] += b; 
	}
}