#include <bits/stdc++.h>

using namespace std;

int Head[300010], Next[600010], Go[600010], Size[300010], Ans[300010], F[300010], n, m, Cnt = 0;

void Search(int x)
{
	Size[x] = 1;
	for(int T = Head[x]; T; T = Next[T]) Search(Go[T]), Size[x] += Size[Go[T]];
}

void DFS(int x)
{
	if(Size[x] == 1)
	{
		Ans[x] = x;
		return;
	}
	for(int T = Head[x]; T; T = Next[T]) DFS(Go[T]);
	int v = Go[Head[x]];
	for(int T = Head[x]; T; T = Next[T]) if(Size[Go[T]] > Size[v]) v = Go[T];
	if(Size[v] * 2 <= Size[x])
	{
		Ans[x] = x;
		return;
	}
	int tmp = Ans[v];
	while((Size[x] - Size[tmp]) * 2 > Size[x]) tmp = F[tmp];
	Ans[x] = tmp;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		Go[++Cnt] = i, Next[Cnt] = Head[x], Head[x] = Cnt;
		F[i] = x;
	}
	Search(1);
	DFS(1);
	for(int i = 1; i <= m; i++)
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", Ans[x]);
	}
	return 0;
}