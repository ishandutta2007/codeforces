#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n,m,k;
#include<vector>
#include<cstdlib>
std::vector<int>v[1111111];
void Fail()
{puts("No"),exit(0);}
int h[1111111],tot=1;
struct edg
{int p,t;}e[2222222];
void build(int x,int y)
{e[++tot]=(edg){h[x],y},h[x]=tot;}
void dmin(int&x,int y)
{if(x>y)x=y;} 
int dfn[1111111],low[1111111],dep,stk[1111111],top;
int ecc,col[1111111];
void tarjan(int p,int f=-1)
{
	dfn[p]=low[p]=++dep,stk[++top]=p;
	for(register int i=h[p];i;i=e[i].p)
		if(i^f)
		{
			if(!dfn[e[i].t])tarjan(e[i].t,i^1),dmin(low[p],low[e[i].t]);
			else dmin(low[p],dfn[e[i].t]);
		}
	if(low[p]==dfn[p])
	{
		ecc++;
		for(;stk[top+1]^p;top--)
			col[stk[top]]=ecc;
	}
}
int x[1111111],y[1111111];
int fa[1111111][22],len[1111111];
int up[1111111],dw[1111111];
void dfs(int p,int f=0)
{
	len[p]=len[f]+1,fa[p][0]=f;
	for(register int i=1;fa[p][i-1];i++)
		fa[p][i]=fa[fa[p][i-1]][i-1];
	for(auto t:v[p])
		if(t^f)dfs(t,p);
}
void sumize(int p,int f=0)
{
	len[p]=len[f]+1;
	for(auto t:v[p])
		if(t^f)sumize(t,p),up[p]+=up[t],dw[p]+=dw[t];
}
int lca(int x,int y)
{
	register int i;
	if(len[x]<len[y])x^=y^=x^=y;
	for(i=20;~i;i--)if(len[fa[x][i]]>=len[y])x=fa[x][i];
	if(x==y)return x;
	for(i=20;~i;i--)if(fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	retrun fa[x][0];
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	register int i;
	for(i=1;i<=m;i++)
		scanf("%d%d",x+i,y+i),build(x[i],y[i]),build(y[i],x[i]);
	for(i=1;i<=n;i++)
		if(!dfn[i])tarjan(i);
	for(i=1;i<=m;i++)
	{
		x[i]=col[x[i]],y[i]=col[y[i]];
		if(x[i]^y[i])
			v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
	}for(i=1;i<=ecc;i++)
		if(!len[i])dfs(i);
	for(i=1;i<=k;i++)
	{
		int s,t;
		scanf("%d%d",&s,&t),s=col[s],t=col[t];
		int p=lca(s,t);
		if(!p)Fail();
		else up[s]++,up[p]--,dw[t]++,dw[p]--;
	}for(i=1;i<=ecc;i++)len[i]=0;
	for(i=1;i<=ecc;i++)
		if(!len[i])sumize(i);
	for(i=1;i<=ecc;i++)
		if(up[i]&&dw[i])Fail();
	puts("Yes");
}
/*
Just go for it.
*/