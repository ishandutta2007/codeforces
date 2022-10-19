#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
	bool operator<(const edge &other)const
	{
		return w<other.w;
	}
}e[500005];
int fa[500005],l[500005],r[500005];
set<int>s;
int findfather(int x)
{
	return x==fa[x]?x:fa[x]=findfather(fa[x]);
}
int main()
{
	int m,n,tot=0,p3=0;
	cin>>m>>n;
	for(int i=0;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int s;
		scanf("%d",&s);
		if(s==1)
		{
			int l;
			scanf("%d",&l);
			e[++tot]=edge(0,l,i);
		}else
		{
			scanf("%d%d",&l[i],&r[i]);
			e[++tot]=edge(l[i],r[i],i);
		}
	}
	sort(e+1,e+tot+1);
	int gs=0;
	for(int i=1;i<=tot;i++)
	{
		int fu=findfather(e[i].u),fv=findfather(e[i].v),w=e[i].w;
		if(fu==fv)continue;
		fa[fu]=fv;
		gs++;
		s.insert(w);
	}
	int ans=1;
	for(int i=1;i<=gs;i++)ans=2*ans%1000000007;
	cout<<ans<<" ";
	gs=s.size();
	cout<<gs<<endl;
	for(int i=1;i<=gs;i++)
	{
		printf("%d ",*(s.begin()));
		s.erase(*(s.begin()));
	}
	return 0;
}