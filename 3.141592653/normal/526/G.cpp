#include<cstdio>
#include<vector>
#include<algorithm>
struct pii{int p,l;};
bool operator<(const pii x,const pii y)
{return x.l>y.l;}
int n,q;
int mx(int x,int y){return x<y?y:x;}
struct tree
{
	int fa[222222][22],len[222222],ds[222222],rt,
	tp[222222],dep[222222];
	std::vector<pii>v[222222];
	void ins(int x,int y,int z)
	{
		v[x].push_back(pii{y,z}),
		v[y].push_back(pii{x,z});
	}
	int dis[222222];
	void findfar(int p=1,int f=0)
	{
		if(!f)dis[p]=0;
		for(pii t:v[p])if(t.p^f)
			dis[t.p]=dis[p]+t.l,findfar(t.p,p);
	}
	int init()
	{
		findfar();
		register int i;
		for(i=2,rt=1;i<=n;i++)if(dis[i]>dis[rt])rt=i;
		findfar(rt);
		int ret=1;
		for(i=2;i<=n;i++)if(dis[i]>dis[ret])ret=i;
		return ret;
	}
	void dfs(int p,int f=0)
	{
		fa[p][0]=f;
		for(register int i=0;fa[p][i];i++)
			fa[p][i+1]=fa[fa[p][i]][i];
		for(pii t:v[p])if(t.p^f)
		{
			dep[t.p]=dep[p]+t.l,
			dfs(t.p,p),len[t.p]+=t.l;
			if(len[t.p]>=len[p])
				len[p]=len[t.p],ds[p]=t.p;
		}
	}
	void split(int p,int f,int t)
	{
		tp[p]=t;
		if(!ds[p])return;
		split(ds[p],p,t);
		for(pii q:v[p])
			if(q.p^f)if(q.p^ds[p])split(q.p,p,q.p);
	}
	pii P[222222];
	int tot;
	int S[222222],rnk[222222];
	void build()
	{
		register int i;
		for(i=1;i<=n;i++)
			if(tp[i]==i)P[++tot]=pii{i,len[i]};
		std::sort(P+1,P+tot+1);
		for(i=1;i<=tot;i++)
			rnk[P[i].p]=i,S[i]=S[i-1]+P[i].l;
	}
	int cut(int x,int y)
	{
		for(register int i=18;~i;i--)
			if(rnk[tp[fa[x][i]]]>y)x=fa[x][i];
		x=fa[x][0];
		return len[ds[x]];
	}
	int lev(int x,int y)
	{
		int ret=len[tp[x]]+dep[fa[tp[x]][0]];
		for(register int i=18;~i;i--)
			if(rnk[tp[fa[x][i]]]>y)x=fa[x][i];
		x=fa[x][0];
		return ret-dep[x];
	}
	int ask(int x,int y)
	{
		y=y*2-1;
		if(y>=tot)return S[tot];
		if(y>=rnk[tp[x]])return S[y];
		return S[y]+lev(x,y)+mx(-cut(x,y),-P[y].l);
	}
}T1,T2;
int main()
{
	scanf("%d%d",&n,&q);
	for(register int i=1;i<n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c),T1.ins(a,b,c);
	}int loc=T1.init();
	T2=T1,T2.rt=loc;
	T1.dfs(T1.rt),T1.split(T1.rt,0,T1.rt),T1.build(); 
	T2.dfs(T2.rt),T2.split(T2.rt,0,T2.rt),T2.build();
	int la=0;
	for(register int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),
		x=(x+la-1)%n+1,y=(y+la-1)%n+1,
		printf("%d\n",la=mx(T1.ask(x,y),T2.ask(x,y)));
	}
}
/*
Please don't let me down.
*/