#include<bits/stdc++.h>
using namespace std;
int f1[300005],f2[300005],t1=0,t2=0,b1[300005],e1[300005],b2[300005],e2[300005];
int n,f[300005],v[300005],ans=0;
long long c[300005];
vector<int>g1[300005],g2[300005];
void dfs1(int x)
{
	b1[x]=e1[x]=++t1;
	for(int i=0;i<g1[x].size();i++)
	{
		int cu=g1[x][i];
		dfs1(cu);
		e1[x]=max(e1[x],e1[cu]);
	}
}
void dfs2(int x)
{
	b2[x]=e2[x]=++t2;
	for(int i=0;i<g2[x].size();i++)
	{
		int cu=g2[x][i];
		dfs2(cu);
		e2[x]=max(e2[x],e2[cu]);
	}
}
void add(int x,int s)
{
	while(x<=n)
	{
		c[x]+=s;
		x+=x&-x;
	}
}
int query(int x)
{
	int ans=0;
	while(x)
	{
		ans+=c[x];
		x-=x&-x;
	}
	return ans;
}
void dfs3(int x,int dd)
{
	int S1=query(b2[x]);
	if(S1)
	{
		add(b2[S1],-S1);
		add(e2[S1]+1,S1);
	}else dd++;
	ans=max(ans,dd);
	add(b2[x],x);
	add(e2[x]+1,-x);
	for(int i=0;i<g1[x].size();i++)
	{
		int cu=g1[x][i];
		dfs3(cu,dd);
	}
	add(b2[x],-x);
	add(e2[x]+1,x);
	if(S1)
	{
		add(b2[S1],S1);
		add(e2[S1]+1,-S1);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)g1[i].clear(),g2[i].clear(),c[i]=0;
		for(int i=2;i<=n;i++)
		{
			int u;
			scanf("%d",&u);
			f1[i]=u;
			g1[u].push_back(i);
		}
		for(int i=2;i<=n;i++)
		{
			int u;
			scanf("%d",&u);
			f2[i]=u;
			g2[u].push_back(i);
		}
		t1=0,t2=0;
		dfs1(1),dfs2(1);
		for(int i=1;i<=n;i++)f[i]=1;
		ans=0,dfs3(1,0);
		printf("%d\n",ans);
	}
	return 0;
}