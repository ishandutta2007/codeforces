#include<cstdio>
#include<vector>
int n,m;
const int blk=350;
int cnt[290][200021],det[322];
#define Bel(x) ((x-1)/blk+1)
#define Lsh(x) ((x-1)*blk+1)
#define Rsh(x) ((x)*blk)
int c[111111],o[111111],ans,Z=100010;
void upd(int L,int R,int d)
{
	int A=Bel(L),B=Bel(R);
	register int i;
	if(A==B)
	{
		for(i=L;i<=R;i++)
		{
			if(!o[i])cnt[A][c[i]]--;
			c[i]+=d;
			if(!o[i])
			{
				cnt[A][c[i]]++;
				if(d>0){if(c[i]+det[A]==Z+1)ans++;} 
				else if(c[i]+det[A]==Z)ans--;
			}
		}
	}else
	{
		for(i=L;i<=Rsh(A);i++)
		{
			if(!o[i])cnt[A][c[i]]--;
			c[i]+=d;
			if(!o[i])
			{
				cnt[A][c[i]]++;
				if(d>0){if(c[i]+det[A]==Z+1)ans++;} 
				else if(c[i]+det[A]==Z)ans--;
			}
		}
		for(i=A+1;i<B;i++)
		{
			if(d>0)ans+=cnt[i][Z-det[i]],det[i]+=d;
			else det[i]+=d,ans-=cnt[i][Z-det[i]];
		}
		for(i=Lsh(B);i<=R;i++)
		{
			if(!o[i])cnt[B][c[i]]--;
			c[i]+=d;
			if(!o[i])
			{
				cnt[B][c[i]]++;
				if(d>0){if(c[i]+det[B]==Z+1)ans++;} 
				else if(c[i]+det[B]==Z)ans--;
			}
		}
	}
}
void ins(int x)
{
	o[x]=0,cnt[Bel(x)][c[x]]++;
	if(c[x]+det[Bel(x)]>Z)ans++;
}
void des(int x)
{
	if(c[x]+det[Bel(x)]>Z)ans--;
	o[x]=1,cnt[Bel(x)][c[x]]--;
}
int dfn[111111],tp[111111],
fa[111111],sz[111111],ds[111111],td;
std::vector<int>v[111111];
void dfs(int p=1)
{
	sz[p]=1;
	for(int t:v[p])dfs(t),sz[p]+=sz[t],sz[t]>sz[ds[p]]?ds[p]=t:0;
}
void split(int p=1,int tpp=1)
{
	dfn[p]=++td,tp[p]=tpp;
	if(ds[p])split(ds[p],tpp);
	for(int t:v[p])if(t^ds[p])split(t,t);
}
void insp(int x)
{
	for(register int p=fa[x];p;p=fa[tp[p]])
		upd(dfn[tp[p]],dfn[p],-1);
	ins(dfn[x]);
}
void desp(int x)
{
	for(register int p=fa[x];p;p=fa[tp[p]])
		upd(dfn[tp[p]],dfn[p],1);
	des(dfn[x]);
}
int t[111111];
int main()
{
	scanf("%d%d",&n,&m);
	register int i,x;
	for(i=2;i<=n;i++)scanf("%d",fa+i),v[fa[i]].push_back(i);
	dfs(),split();
	for(i=1;i<=n;i++)scanf("%d",t+i),c[dfn[i]]=Z-t[i],cnt[Bel(dfn[i])][c[dfn[i]]]++;
	for(i=1;i<=m;i++)
		scanf("%d",&x),(x<0)?insp(-x):desp(x),printf("%d ",ans);
	puts("");
}
/*
Please don't let me down.
*/