#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3, MAXM = 1e5;

int A, B, M, K;
vector<int> connL[MAXN], connR[MAXN];
int col[MAXM], u[MAXM], v[MAXM];

void KempeR(int, int, int);

void KempeL(int l, int c, int d)
{
	for(auto e: connL[l])
		if(col[e] == c)
		{
			KempeR(v[e], d, c);
			col[e] = d;
			return;
		}
}

void KempeR(int r, int c, int d)
{
	for(auto e: connR[r])
		if(col[e] == c)
		{
			KempeL(u[e], d, c);
			col[e] = d;
			return;
		}
}

void augment(int x)
{
	vector<bool> usedL(K+1), usedR(K+1);
	for(auto e: connL[u[x]]) usedL[col[e]] = 1;
	for(auto e: connR[v[x]]) usedR[col[e]] = 1;

	int c = 0, d = 0;
	for(int i=1; i<=K; ++i)
	{
		if(!usedL[i] && !usedR[i])
		{
			col[x] = i;
			return;
		}
		if(!usedL[i]) c = i;
		else if(!usedR[i]) d = i;
	}
	KempeR(v[x], c, d);
	col[x] = c;
}

int main()
{
	scanf("%d%d%d", &A, &B, &M);
	for(int i=0; i<M; ++i)
	{
		scanf("%d%d", u+i, v+i); --u[i]; --v[i];
		connL[u[i]].push_back(i);
		connR[v[i]].push_back(i);
	}
	for(int i=0; i<A; ++i) K = max(K, (int)connL[i].size());
	for(int i=0; i<B; ++i) K = max(K, (int)connR[i].size());
	for(int i=0; i<M; ++i) augment(i);
	printf("%d\n", K);
	for(int i=0; i<M; ++i) printf("%d ", col[i]);
	puts("");
}