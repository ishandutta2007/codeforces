#include<bits/stdc++.h>
using namespace std;
struct apple
{
	int u,v,w;
	apple(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator<(const apple &other)const
	{
		return w>other.w;
	}
}e[500005];
int fa[500005],a[500005],b[500005];
int findfather(int x)
{
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int main()
{
	int n,m,t,tot=0;
	long long ans=0;
	cin>>m>>n;
	t=n+m;
	for(int i=1;i<=t;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		for(int j=1;j<=s;j++)
		{
			int x;
			scanf("%d",&x);
			e[++tot]=apple(n+i,x,a[i]+b[x]);
			ans+=a[i]+b[x];
		}
	}
	sort(e+1,e+tot+1);
	for(int i=1;i<=tot;i++)
	{
		int u=findfather(e[i].u),v=findfather(e[i].v),w=e[i].w;
		if(u==v)continue;
		ans-=w;
		fa[u]=v;
	}
	cout<<ans<<endl;
	return 0;
}