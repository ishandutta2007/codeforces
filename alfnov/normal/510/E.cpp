#include<bits/stdc++.h>
using namespace std;
vector<int>g[205];
int vis[100005],fa[100005],vist[100005],ss[20005],q[100005],dd[20005],ans=0,tol=0,sv[100005];
int n,S,T,tot=1,cur[100005],nxt[100005],id[100005],mw[100005],a[100005],f[100005],c[100005],zhi[100005],l[100005];
void print()
{
	ss[1]=1;
	for(int i=2;i<=20000;i++)
	{
		if(!ss[i])dd[++tol]=i;
		for(int j=1;j<=tol&&i*dd[j]<=20000;j++)
		{
			ss[i*dd[j]]=1;
			if(i%dd[j]==0)break;
		}
	}
}
void addedge(int u,int v,int w)
{
	tot++;
	if(!id[u])id[u]=mw[u]=tot;
	else mw[u]=nxt[mw[u]]=tot;
	zhi[tot]=v,c[tot]=w;
}
int getc()
{
	for(int i=1;i<=n;i++)l[i]=0,cur[i]=id[i];
	int head=0,tail=-1;
	q[++tail]=S,l[S]=1;
	while(head<=tail)
	{
		int x=q[head++];
		for(int j=id[x];j;j=nxt[j])
		{
			if(l[zhi[j]]||c[j]==f[j])continue;
			l[zhi[j]]=l[x]+1;
			q[++tail]=zhi[j];
		}
	}
	return l[T]!=0;
}
int dinic(int x,int rl)
{
	if(x==T)
	{
		ans+=rl;
		return rl;
	}
	int tt=rl,ll=cur[x];
	for(int j=cur[x];j;j=nxt[j])
	{
		if(l[zhi[j]]!=l[x]+1||c[j]==f[j])continue;
		int ggg=dinic(zhi[j],min(c[j]-f[j],rl));
		rl-=ggg,f[j]+=ggg,f[j^1]-=ggg;
		ll=j;
	}
	cur[x]=ll;
	return tt-rl;
}
int findfather(int x)
{
	return x==fa[x]?fa[x]:fa[x]=findfather(fa[x]);
}
void dfs(int x)
{
	sv[x]=1;
	printf(" %d",x);
	for(int i=0;i<g[x].size();i++)
	{
		int cu=g[x][i];
		if(sv[cu])continue;
		dfs(cu);
	}
}
int main()
{
	print();
	int N;
	cin>>N;
	T=n=N+2,S=1;
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]&1)addedge(S,i+1,2),addedge(i+1,S,0);
		else addedge(i+1,T,2),addedge(T,i+1,0);
	}
	for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)if((a[i]&1)&&!ss[a[i]+a[j]])
	{
		int x=i+1,y=j+1;
		addedge(x,y,1),addedge(y,x,0);
	}
	while(getc())dinic(S,INT_MAX);
	if(ans!=N)puts("Impossible");
	else
	{
		for(int i=1;i<=N;i++)fa[i]=i;
		for(int i=1;i<=N;i++)if(a[i]&1)for(int j=id[i+1];j;j=nxt[j])if(c[j]&&c[j]==f[j])
		{
			int x=i,y=zhi[j]-1;
			g[x].push_back(y);
			g[y].push_back(x);
			int f1=findfather(x),f2=findfather(y);
			if(f1!=f2)fa[f1]=f2;
		}
		int gg=0;
		for(int i=1;i<=N;i++)
		{
			findfather(i);
			vist[fa[i]]++;
			if(vist[fa[i]]==1)gg++;
		}
		cout<<gg<<endl;
		for(int i=1;i<=N;i++)if(!vis[fa[i]])
		{
			printf("%d",vist[fa[i]]);
			vis[fa[i]]=1;
			dfs(i);
			puts("");
		}
	}
	return 0;
}