#include<bits/stdc++.h>
using namespace std;
vector<int>g[1000005];
int dfn[1000005],low[1000005],vist[1000005],st[1000005];
int t1=0,t2=0,an,a[1000005],ans[1000005];
void tarjan(int x,int la)
{
	dfn[x]=low[x]=++t1;
	vist[x]=1,st[++t2]=x;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		if(!dfn[cu])
		{
			tarjan(cu,x);
			low[x]=min(low[x],low[cu]);
		}else if(vist[cu])
		{
			low[x]=min(low[x],dfn[cu]);
		}
	}
	if(dfn[x]!=low[x])return;
	int wz=t2;
	while(st[wz]!=x)wz--;
	if(t2>wz)an=0;
	for(int i=wz;i<=t2;i++)
	{
		if(t2>wz)ans[++an]=st[i];
		vist[st[i]]=0;
	}
	t2=wz-1;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]=i-a[i];
		for(int i=1;i<=n;i++)g[i].clear(),dfn[i]=low[i]=vist[i]=0;
		int flag=0;
		for(int i=1;i<=n;i++)if(a[i]==i)
		{
			printf("1\n%d\n",i);
			flag=1;
			break;
		}
		if(flag)continue;
		for(int i=1;i<=n;i++)if(a[a[i]]==i)
		{
			printf("2\n%d %d\n",i,a[i]);
			flag=1;
			break;
		}
		if(flag)continue;
		for(int i=1;i<=n;i++)
		{
			g[a[i]].push_back(i);
			g[i].push_back(a[i]);
		}
		for(int i=1;i<=n;i++)if(!dfn[i])
			t1=t2=0,tarjan(i,0);
		printf("%d\n",an);
		for(int i=1;i<an;i++)printf("%d ",ans[i]);
		printf("%d\n",ans[an]);
	}
	return 0;
}