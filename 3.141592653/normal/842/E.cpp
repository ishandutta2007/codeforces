#include<bits/stdc++.h>
int n;
int max(int x,int y){return x<y?y:x;}
struct segt
{
	int Mx[1111111],Ct[1111111],tg[1111111];
	void pushu(int p)
	{
		Mx[p]=max(Mx[p<<1],Mx[p<<1|1]),Ct[p]=0;
		if(Mx[p]==Mx[p<<1])Ct[p]+=Ct[p<<1];
		if(Mx[p]==Mx[p<<1|1])Ct[p]+=Ct[p<<1|1];
	}
	void push(int p,int d){Mx[p]+=d,tg[p]+=d;}
	void pushd(int p){push(p<<1,tg[p]),push(p<<1|1,tg[p]),tg[p]=0;}
	void addt(int l,int r,int d,int p=1,int pl=1,int pr=n)
	{
		if(l>pr||pl>r)return;
		if(l<=pl&&pr<=r)return push(p,d);
		int pm=(pl+pr)>>1;
		pushd(p),addt(l,r,d,p<<1,pl,pm),addt(l,r,d,p<<1|1,pm+1,pr),pushu(p);
	}
	void ins(int x,int v,int p=1,int pl=1,int pr=n)
	{
		if(pl==pr){Ct[p]=1,Mx[p]=v;return;}
		int pm=(pl+pr)>>1,dr=x>pm;
		dr?pl=pm+1:pr=pm,pushd(p),ins(x,v,p<<1|dr,pl,pr),pushu(p); 
	}
}T;
int C=1,P=0,Cd=0,et;
int dfn[1111111],dfr[1111111],fa[1111111][22],dep[1111111];
std::vector<int>v[1111111];
void dfs(int p=1,int f=0)
{
	dep[p]=dep[f]+1,dfn[p]=++et;
	for(int t:v[p])dfs(t,p);
	dfr[p]=et;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])x^=y^=x^=y;
	register int i;
	for(i=20;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(i=20;~i;i--)if(fa[x][i]^fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int gtfa(int x,int k){for(register int i=0;k;k>>=1,i++)if(k&1)x=fa[x][i];return x;}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca(x,y)];}
int main()
{
	scanf("%d",&n),n++;
	register int i,ii;
	for(i=2;i<=n;i++)
		for(scanf("%d",fa[i]),v[fa[i][0]].push_back(i),ii=0;fa[i][ii];ii++)
			fa[i][ii+1]=fa[fa[i][ii]][ii];
	dfs(),T.addt(1,n,-1e9),T.ins(1,0);
	for(i=2;i<=n;i++)
	{
		int L;
		if(P==1)
		{
			int a=dis(C,i),b=dis(fa[C][0],i);
			L=a+b;
			if(L>Cd)
			{
				if(a>b)T.addt(dfn[C],dfr[C],2),T.addt(1,n,-1),C=fa[C][0];
				else T.addt(1,n,1),T.addt(dfn[C],dfr[C],-2);
				P=0,L--,Cd++;
			}
		}
		else
		{
			int X=lca(C,i);
			L=(dep[C]+dep[i]-2*dep[X])*2;
			if(L>Cd)
			{
				if(C==X)C=gtfa(i,(L>>1)-1),T.addt(1,n,1),T.addt(dfn[C],dfr[C],-2);
				else T.addt(dfn[C],dfr[C],2),T.addt(1,n,-1);
				P=1,L--,Cd++;
			}
		}T.ins(dfn[i],L),printf("%d\n",T.Ct[1]);
	}
}
/*
Please don't let me down.
*/