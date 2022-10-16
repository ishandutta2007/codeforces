#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
#define psb push_back
int n,m;
typedef long long ll;
struct pii
{int t;ll l;}p[1111111];
bool operator<(cpnst pii x,cpnst pii y)
{return x.l<y.l;}
#include<vector>
std::vector<pii>v[1111111];
ll dis[1111111],len[1111111];
void dfs(int p,int f=0,ll l=0)
{
	if(len[p]<l)len[p]=l;
	dis[p]=l;
	for(auto t:v[p])
		if(t.t^f)	
			dfs(t.t,p,l+t.l);
}
#include<algorithm>
int fa[1111111],siz[1111111],label[1111111];
void precalc()
{
	register int i;
	dfs(1);
	int low=1;
	for(i=2;i<=n;i++)
		if(dis[i]>dis[low])low=i;
	dfs(low);
	for(i=1;i<=n;i++)
		if(dis[i]>dis[low])low=i;
	dfs(low);
	for(i=1;i<=n;i++)p[i]=(pii){i,len[i]};
	std::sort(p+1,p+n+1);
	for(i=1;i<=n;i++)label[p[i].t]=i;
}
int rt(int x){return fa[x]?fa[x]=rt(fa[x]):x;}
int insert(int x)
{
	for(auto t:v[x])
		if(label[t.t]>label[x])
		{
			int pp=rt(x),ps=rt(t.t);
			fa[ps]=pp,siz[pp]+=siz[ps];
		}
	return siz[rt(x)];
}
void erase(int x)
{x=rt(x),siz[x]--;}
void solve()
{
	ll L;
	scanf("%lld",&L);
	register int r=n,l=n,i;
	for(i=1;i<=n;i++)fa[i]=0,siz[i]=1;
	int ans=1;
	for(;r>1;)
	{
		for(;p[l].l-p[r-1].l>L;l--)erase(p[l].t);
		r--;
		int rm=insert(p[r].t);
		if(rm>ans)ans=rm;
	}printf("%d\n",ans);
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<n;i++)
	{
		int x,y,l;
		scanf("%d%d%d",&x,&y,&l),v[x].psb(pii{y,l}),v[y].psb(pii{x,l});
	}precalc();
	for(scanf("%d",&m);m--;)solve();
}
/*
Just go for it.
*/