#include<bits/stdc++.h>
using namespace std;
int m=0,a[200005],fa[25][200005],c[200005];
long long d[200005];
vector<pair<int,int> >g[200005];
int tiao(int x,int p)
{
	for(int i=20;i>=0;i--)if(p>=(1<<i))
		p-=1<<i,x=fa[i][x];
	return x;
}
void dfs1(int x)
{
	long long z=d[m]-a[x];
	int wz=lower_bound(d+1,d+m+1,z)-d;
	c[fa[0][tiao(x,m-wz)]]--,c[fa[0][x]]++;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i].first,c2=g[x][i].second;
		m++,d[m]=d[m-1]+c2;
		dfs1(cu),m--;
	}
}
void dfs2(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		dfs2(g[x][i].first);
		c[x]+=c[g[x][i].first];
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int p,w;
		scanf("%d%d",&p,&w);
		g[fa[0][i]=p].push_back(make_pair(i,w));
	}
	for(int i=1;i<=20;i++)for(int j=1;j<=n;j++)
		fa[i][j]=fa[i-1][fa[i-1][j]];
	d[++m]=0,dfs1(1),dfs2(1);
	for(int i=1;i<=n;i++)printf("%d ",c[i]);
	return 0;
}