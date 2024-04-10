#include<bits/stdc++.h>
class music
{
	struct pii{int t;char c;};
	friend bool operator<(const pii&x,const pii&y){return x.c<y.c;}
	std::vector<pii>v[22222];
	char c[22222],ec[44444];
	int n,m;
	int fa[22222],dep[22222],siz[22222];
	char fac[22222];
	int fs[22222][22];
	int dfn[22222],rev[22222],tot;
	void dfs(int p=1,int f=0)
	{
		rev[dfn[p]=++tot]=p,fa[dfn[p]]=dfn[f],fs[p][0]=f,siz[p]=1,dep[p]=dep[f]+1;
		for(register int i=0;fs[p][i];i++)fs[p][i+1]=fs[fs[p][i]][i];
		for(pii&t:v[p])if(t.t^f)dfs(t.t,p),fac[dfn[t.t]]=t.c,siz[p]+=siz[t.t];
	}
	int lca(int x,int y)
	{
		if(dep[x]>dep[y]){int t=x;x=y,y=t;}
		for(register int i=18;~i;i--)if(dep[fs[y][i]]>=dep[x])y=fs[y][i];
		if(x==y)return x;
		for(register int i=18;~i;i--)if(fs[x][i]^fs[y][i])x=fs[x][i],y=fs[y][i];
		return fs[x][0];
	}
	void extract(int x,int y)
	{
		int L=lca(x,y),ds=dep[x]+dep[y]-2*dep[L];
		x=dfn[x],y=dfn[y];
		for(register int i=1;x!=dfn[L];i++,x=fa[x])c[i]=fac[x];
		for(register int i=ds;y!=dfn[L];i--,y=fa[y])c[i]=fac[y];
		c[ds+1]=0;
	}
	int tp[44444],sz[44444],Lf[22222],Rf[22222];
	int q[22222],d[22222],frm[22222];
	void bfs(int x)
	{
		int sum=0;
		q[1]=x,d[1]=1;
		register int ql=1,qr=1;
		for(;ql<=qr;ql++)
		{
			int p=q[ql];
			register char c0=c[d[ql]];
			for(register int i=Lf[p];i<=Rf[p];i++)
			{
				if(frm[ql]!=tp[i])
				{
					if(ec[i]<c0)sum+=sz[i];
					else if(ec[i]==c0)q[++qr]=tp[i],d[qr]=d[ql]+1,frm[qr]=p;
				}
			}
		}
		while(qr&&!c[d[qr]])qr--;
		printf("%d\n",sum+qr-1);
	}
	void ask(int x,int y){extract(x,y),bfs(dfn[x]);}
	public:
	void solve()
	{
		scanf("%d%d",&n,&m);
		for(register int i=1;i<n;i++)
		{
			int x,y;char z[5];
			scanf("%d%d%s",&x,&y,z);
			v[x].push_back(pii{y,*z}),v[y].push_back(pii{x,*z});
		}
		dfs();
		for(register int i=1,ds;i<=n;i++)
		{
			ds=Lf[i]=Rf[i-1]+1,Rf[i]=Lf[i]+(int)v[rev[i]].size()-1;
			std::sort(v[rev[i]].begin(),v[rev[i]].end());
			for(pii&P:v[rev[i]])
				tp[ds]=dfn[P.t],ec[ds]=P.c,sz[ds]=(fs[P.t][0]==rev[i])?siz[P.t]:(n-siz[rev[i]]),ds++;
		}
		for(register int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y),ask(x,y);
		}
	}
}Solver;
int main()
{
	Solver.solve();
}
/*
This end-of-file is just the beginning.
*/