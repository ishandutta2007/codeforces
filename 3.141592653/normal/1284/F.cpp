#include<bits/stdc++.h>
int n;
struct Tree
{
	std::vector<int>v[1111111];
	void init()
	{
		for(register int i=1,x,y;i<n;i++)
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	}
	int fa[1111111],de[1111111],r[333333][22];
	int lca(int x,int y)
	{
		if(de[x]<de[y])x^=y^=x^=y;
		register int i;
		for(i=20;~i;i--)if(de[r[x][i]]>=de[y])x=r[x][i];
		if(x==y)return x;
		for(i=20;~i;i--)if(r[x][i]^r[y][i])x=r[x][i],y=r[y][i];
		return r[x][0];
	}
	void dfs(int p=1,int f=0)
	{
		fa[p]=r[p][0]=f,de[p]=de[f]+1;
		for(register int i=0;r[p][i];i++)r[p][i+1]=r[r[p][i]][i];
		for(int t:v[p])if(t^f)dfs(t,p);
	}
}T1,T2;
struct dsu
{
	int fa[1111111],tp[1111111];
	void init(){for(register int i=1;i<=n;i++)tp[i]=i;}
	int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
	int top(int x){return tp[rt(x)];}
	void merge(int x,int y)
	{
		x=rt(x),y=rt(y),fa[x]=y;
		if(T1.de[tp[x]]<T1.de[tp[y]])tp[y]=tp[x];
	}
}U;
void dfs(int p=1,int f=0)
{
	for(int t:T2.v[p])if(t^f)dfs(t,p);
	if(f)
	{
		int A=U.top(p),B=U.top(f),L=T1.lca(p,f);
		if(T1.de[A]<=T1.de[L])
		{
			for(register int i=20;~i;i--)
				if(T1.de[U.top(T1.r[B][i])]>T1.de[A])B=T1.r[B][i];
			printf("%d %d %d %d\n",T1.fa[B],B,f,p),U.merge(B,T1.fa[B]);
		}else printf("%d %d %d %d\n",T1.fa[A],A,f,p),U.merge(A,T1.fa[A]);
	}
}
int main()
{scanf("%d",&n),T1.init(),T2.init(),T1.dfs(),U.init(),printf("%d\n",n-1),dfs();}
/*
Please don't let me down.
*/