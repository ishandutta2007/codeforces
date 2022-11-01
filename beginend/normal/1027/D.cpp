#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n,c[N],a[N],ans,top,stack[N];
bool ins[N],vis[N];

void dfs(int x)
{
	vis[x]=1;ins[x]=1;
	stack[++top]=x;
	if (!vis[a[x]]) dfs(a[x]);
	else if (ins[a[x]])
	{
		int mn=c[x],p=top;
		while (stack[p]!=a[x]) p--,mn=std::min(mn,c[stack[p]]);
		ans+=mn;
	}
	top--;ins[x]=0;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) if (!vis[i]) dfs(i);
	printf("%d\n",ans);
	return 0;
}