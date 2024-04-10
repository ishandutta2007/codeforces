#include<bits/stdc++.h>
using namespace std;
int n,f[500005],u[200005],v[200005],q[200005],q2[200005];
int sz[200005],fa[200005],vist[200005];
vector<int>g[200005];
void dfs(int x,int la)
{
	vist[x]=1;
	sz[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(cu==la)continue;
		fa[cu]=x;
		dfs(cu,x);
		sz[x]+=sz[cu];
	}
}
bool check(int l,int r)
{
	if(r-l+2<=3)return 1;
	if(!f[r-l+2])return 0;
	for(int i=l;i<=r;i++)
		g[u[q[i]]].clear(),g[v[q[i]]].clear();
	for(int i=l;i<=r;i++)
	{
		g[u[q[i]]].push_back(v[q[i]]);
		g[v[q[i]]].push_back(u[q[i]]);
		fa[u[q[i]]]=fa[v[q[i]]]=0;
	}
	dfs(u[q[l]],0);
	for(int i=l;i<=r;i++)
	{
		vist[u[q[i]]]=vist[v[q[i]]]=0;
	}
	for(int i=l;i<=r;i++)
	{
		int x=u[q[i]],y=v[q[i]];
		if(fa[x]==y)swap(x,y);
		if(f[sz[y]]<f[r-l+2]-2)continue;
		dfs(y,fa[y]);
		int t1=l-1,t2=r+1;
		for(int j=l;j<=r;j++)
		{
			if(i==j)continue;
			if(vist[u[q[j]]])q2[--t2]=q[j];
			else q2[++t1]=q[j];
		}
		for(int j=l;j<=r;j++)q[j]=q2[j];
		if(!check(l,t1))return 0;
		if(!check(t2,r))return 0;
		return 1;
	}
	return 0;
}
int main()
{
	int a=0,b=1;
	for(int i=1;i<=27;i++)
	{
		int c=a+b;
		f[c]=i,a=b,b=c;
	}
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		q[i]=i;
	}
	if(check(1,n-1))printf("YES\n");
	else printf("NO\n");
	return 0;
}