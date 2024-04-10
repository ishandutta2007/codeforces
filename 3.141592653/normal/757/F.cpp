#include<bits/stdc++.h>
typedef long long ll;
ll dis[1111111];
int n,m,S;
int fa[1111111][22],dep[1111111];
struct pii{int x;ll v;};
bool operator<(const pii x,const pii y){return x.v>y.v;}
int lca(int x,int y)
{
	register int i;
	if(dep[x]<dep[y])x^=y^=x^=y;
	for(i=20;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(i=20;~i;i--)if(fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
std::vector<pii>v[1111111];
std::vector<int>w[1111111],u[1111111];
void ins(int x,int y)
{
	fa[y][0]=x,dep[y]=dep[x]+1,u[x].push_back(y);
	for(register int i=0;fa[y][i];i++)fa[y][i+1]=fa[fa[y][i]][i];
}
int stk[1111111],tp;
void dij()
{
	memset(dis,0x3f,sizeof dis),dis[S]=0;
	std::priority_queue<pii>Q;
	for(Q.push((pii){S,0});Q.size();)
	{
		pii A=Q.top();Q.pop();
		if(dis[A.x]!=A.v)continue;stk[++tp]=A.x;
		for(pii t:v[A.x])if(dis[t.x]>A.v+t.v)dis[t.x]=A.v+t.v,Q.push(pii{t.x,dis[t.x]});
	}
}
int sz[1111111];
void dfs(int p=S)
{sz[p]=1;for(int t:u[p])dfs(t),sz[p]+=sz[t];}
int main()
{
	scanf("%d%d%d",&n,&m,&S);
	register int i;
	for(i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back((pii){y,z}),v[y].push_back((pii){x,z});
	}dij();
	for(i=1;i<=n;i++)
		for(pii t:v[i])
			if(t.v+dis[i]==dis[t.x])w[t.x].push_back(i);
	for(i=1;i<=n;i++)
	{
		int p=stk[i],f=0;
		for(int t:w[p]){if(!f)f=t;else f=lca(f,t);}
		ins(f,p);
	}dfs();
	int ans=0;
	for(i=1;i<=n;i++)
		if(i!=S)
			if(ans<sz[i])ans=sz[i];
	printf("%d\n",ans);
}
/*
Please don't let me down.
*/