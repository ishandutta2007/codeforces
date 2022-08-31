#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, K, P, w[100010], p[100010], S[100010], M, S2[100010];
long long SS;
vector<int>E[100010];
void DFS(int dep, int a, int par){
	int i;
	S[dep]++;
	if (M < dep)M = dep;
	for (i = 0; i < E[a].size(); i++){
		if (par != E[a][i]){
			p[E[a][i]] = a;
			DFS(dep + 1, E[a][i], a);
		}
	}
}
long long mmin(long long a, long long b){
	return a < b ? a : b;
}
int main()
{
	int i, a, b, pv = 1, h, Res = 0, rr;
	long long tp;
	scanf("%d%d%d", &n, &K, &P);
	for (i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	DFS(0, 1, -1);
	S[0] = 0;
	for (i = 1; i <= M; i++)S2[i] = S2[i - 1] + S[i];
	for (i = 1; i <= M; i++){
		while (S2[i] - S2[pv - 1] > K || SS > P){
			tp = S[pv];
			tp = tp * (i - pv);
			SS -= tp;
			pv++;
		}
		rr = S2[i] - S2[pv - 1];
		h = pv - 1;
		if (i != h)tp = mmin((P - SS) / (i - h), K - rr);
		else tp = K - rr;
		if (tp > S[h]) tp = S[h];
		rr += tp;
		if (Res < rr)Res = rr;
		if (i != M){
			SS += S2[i] - S2[pv - 1];
		}
	}
	printf("%d\n", Res);
}