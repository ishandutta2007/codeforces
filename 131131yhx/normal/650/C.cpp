#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> H[1000010], L[1000010], Htmp[1000010], Ltmp[1000010], Ans[1000010];

int n, m, s;

int X[1000010], tmp[1000010], A[1000010], B[1000010], ans[1000010], F[1000010];

int TMP[1000010], Sz = 0;

int getfa(int x)
{
	return F[x] == x ? x : F[x] = getfa(F[x]);
}

bool cmpH(int x, int y)
{
	return H[s][x] < H[s][y];
}

bool cmpL(int x, int y)
{
	return L[s][x] < L[s][y];
}

void Merge(int x, int y)
{
	if(getfa(x) != getfa(y)) F[getfa(x)] = getfa(y);
}

bool cmpp(int x, int y)
{
	return H[x / m][x % m] < H[y / m][y % m];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			int x;
			scanf("%d", &x);
			H[i].push_back(x), L[j].push_back(x), Htmp[i].push_back(j), Ltmp[j].push_back(i);
			F[i * m + j] = i * m + j;
		}
	for(int i = 0; i < n; i++) s = i, sort(Htmp[i].begin(), Htmp[i].end(), cmpH);
	for(int i = 0; i < m; i++) s = i, sort(Ltmp[i].begin(), Ltmp[i].end(), cmpL);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < Htmp[i].size() - 1; j++)
			if(H[i][Htmp[i][j]] == H[i][Htmp[i][j + 1]])
				Merge(i * m + Htmp[i][j], i * m + Htmp[i][j + 1]);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < Ltmp[i].size() - 1; j++)
			if(L[i][Ltmp[i][j]] == L[i][Ltmp[i][j + 1]])
				Merge(Ltmp[i][j] * m + i, Ltmp[i][j + 1] * m + i);
	for(int i = 0; i < n * m; i++)
	{
		if(getfa(i) == i) TMP[++Sz] = i;
		Ans[getfa(i)].push_back(i);
	}
	sort(TMP + 1, TMP + Sz + 1, cmpp);
	for(int i = 1; i <= Sz; i++)
		if(Ans[TMP[i]].size())
		{
			int Max = 0;
			for(int j = 0; j < Ans[TMP[i]].size(); j++)
				Max = max(Max, max(A[Ans[TMP[i]][j] / m], B[Ans[TMP[i]][j] % m]));
			Max++;
			for(int j = 0; j < Ans[TMP[i]].size(); j++)
				ans[Ans[TMP[i]][j]] = A[Ans[TMP[i]][j] / m] = B[Ans[TMP[i]][j] % m] = Max;
		}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++) printf("%d ", ans[i * m + j]);
		putchar('\n');
	}
	return 0;
}