#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int n, m, K;
int D[220][510], tD[220][510], w[220], Next[220][22], Sum2, Sum, Mod = 1000000007, Gap[220];
int Len[220], tp[220];
int LLen, RLen, cnt;
char p[220][220], TP[220];
char L[220], R[200];
bool v[220];
map<string, int>Map;
void Do(char *p, bool ck, int node, int g, bool fir)
{
	int i, j, k, t;
	g += w[node];
	if (*p == 0){
		if (ck && g <= K)D[node][g]++;
		return;
	}
	for (i = 0; i <= cnt; i++)
	{
		for (j = 0; j <= K; j++){
			if (!D[i][j])continue;
			for (k = 0; k < m; k++){
				t = Next[i][k];
				if (j + w[t] > K)continue;
				tD[Next[i][k]][j + w[t]] = (tD[Next[i][k]][j + w[t]] + D[i][j]) % Mod;
			}
		}
	}
	for (i = 0; i <= cnt; i++){
		for (j = 0; j <= K; j++){
			D[i][j] = tD[i][j];
			tD[i][j] = 0;
		}
	}
	for (i = 0; i < p[0] - 'a'; i++){
		if (fir && !i)continue;
		t = Next[node][i];
		if (g + w[t] > K)continue;
		D[t][g + w[t]] = (D[t][g + w[t]] + 1) % Mod;
	}
	if (!fir)
	{
		for (i = 1; i < m; i++){
			t = Next[0][i];
			if (w[t] > K)continue;
			D[t][w[t]] = (D[t][w[t]] + 1) % Mod;
		}
	}
	Do(p + 1, ck, Next[node][p[0] - 'a'], g, 0);
}
int main()
{
	int i, j, g, t, k, l;
	scanf("%d%d%d", &n, &m, &K);
	scanf("%d", &LLen);
	for (i = 0; i < LLen; i++){
		scanf("%d", &t);
		L[i] = t + 'a';
	}
	scanf("%d", &RLen);
	for (i = 0; i < RLen; i++){
		scanf("%d", &t);
		R[i] = t + 'a';
	}
	cnt = 0;
	for (i = 1; i <= n; i++){
		scanf("%d", &Len[i]);
		for (j = 0; j < Len[i]; j++){
			scanf("%d", &tp[j]);
		}
		scanf("%d", &Gap[i]);
		for (j = 0; j < Len[i];j++){
			p[i][j] = tp[j] + 'a';
			if (!Map[p[i]])Map[p[i]] = ++cnt;
		}
		p[i][j] = 0;
	}
	for (i = 0; i < m; i++){
		TP[0] = i + 'a';
		TP[1] = 0;
		if (Map[TP]) Next[0][i] = Map[TP];
		else Next[0][i] = 0;
	}
	for (i = 1; i <= n; i++){
		for (j = 0; j < Len[i]; j++){
			TP[j] = p[i][j];
			TP[j + 1] = 0;
			t = Map[TP];
			if (v[t])continue;
			v[t] = true;
			TP[j + 2] = 0;
			for (k = 0; k < m; k++){
				TP[j + 1] = k + 'a';
				for (l = 0; l <= j + 1; l++){
					if (Map[TP + l])break;
				}
				Next[t][k] = Map[TP + l];
			}
			TP[j + 1] = 0;
			for (k = 1; k <= n; k++){
				if (Len[k] > j + 1)continue;
				for (l = 1; l <= Len[k]; l++){
					if (p[i][j + 1 - l] != p[k][Len[k] - l])break;
				}
				if (l == Len[k] + 1){
					w[Map[TP]] += Gap[k];
				}
			}
		}
	}
	Do(L, 0, 0, 0, 1);
	for (i = 0; i <= cnt; i++){
		for (j = 0; j <= K; j++){
			Sum2 = (Sum2 + D[i][j]) % Mod;
			D[i][j] = 0;
		}
	}
	Do(R, 1, 0, 0, 1);
	for (i = 0; i <= cnt; i++){
		for (j = 0; j <= K; j++){
			Sum = (Sum + D[i][j]) % Mod;
			D[i][j] = 0;
		}
	}
	printf("%d\n", (Sum - Sum2 + Mod) % Mod);
}