#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=2005;

int n,a[N][N],low[N],dfn[N],tim,stack[N],top,tot;
bool ins[N];

void tarjan(int x)
{
	dfn[x]=low[x]=++tim;
	stack[++top]=x;ins[x]=1;
	for (int i=1;i<=n;i++)
		if (a[x][i])
		{
			if (!dfn[i]) tarjan(i),low[x]=std::min(low[x],low[i]);
			else if (ins[i]) low[x]=std::min(low[x],dfn[i]);
		}
	if (dfn[x]==low[x])
	{
		tot++;int y=0;
		while (y!=x)
		{
			y=stack[top--];
			ins[y]=0;
		}
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
	if (tot>1) puts("NO");
	else puts("YES");
	return 0;
}