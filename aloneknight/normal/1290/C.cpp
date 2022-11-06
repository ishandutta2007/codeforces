#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n,m,cc,hd[N],vis[N],col[N];char s[N];
vector<int>g[N];
struct E{int v,nxt,w;}e[N*2];
inline void add(int u,int v,int w){e[++cc]=(E){v,hd[u],w};hd[u]=cc;e[++cc]=(E){u,hd[v],w};hd[v]=cc;}
struct st{int c0,c1,v,p;}T[N]; 
int fnd(int x){return !T[x].p?x:T[x].p=fnd(T[x].p);}
inline int calc(int v)
{
	if(T[v].v==-1)return min(T[v].c0,T[v].c1);
	return T[v].v?T[v].c1:T[v].c0;
}
void dfs(int x)
{
	vis[x]=1;
	for(int i=hd[x];i;i=e[i].nxt)
	{
		int y=e[i].v;if(vis[y])continue;
		col[y]=col[x]^e[i].w,dfs(y);
	}
}
int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1,k;i<=m;i++)
	{
		scanf("%d",&k);
		for(int j=1,x;j<=k;j++){scanf("%d",&x);g[x].push_back(i);}
	}
	for(int i=1;i<=n;i++)if(g[i].size()==2)add(g[i][0],g[i][1],(s[i]-'0')^1);
	for(int i=1;i<=m;i++)if(!vis[i])col[i]=0,dfs(i);
	for(int i=1;i<=m;i++)T[i]=(st){col[i]==0,col[i]==1,-1,0};
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!g[i].size()){printf("%d\n",ans);continue;}
		int c=s[i]-'0',u=g[i][0],v=g[i].size()==2?g[i][1]:0;
		if(g[i].size()==1)
		{
			int w=col[u]^c;u=fnd(u);
			if(T[u].v==-1)
			{
				ans-=min(T[u].c0,T[u].c1);
				T[u].v=w;ans+=w?T[u].c1:T[u].c0;
			}
		}
		else
		{
			u=fnd(u);v=fnd(v);
			if(u!=v)
			{
				ans-=calc(u)+calc(v);
				T[u].p=v;T[v].c0+=T[u].c0;T[v].c1+=T[u].c1;
				if(T[v].v==-1)T[v].v=T[u].v;
				ans+=calc(v);
			} 
		}
		printf("%d\n",ans);
	}
	return 0;
}