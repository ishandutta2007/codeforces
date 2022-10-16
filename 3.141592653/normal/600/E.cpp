#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include<cstdio>
#include<vector>
#include<set>
typedef long long ll;
int c[111111];
int n,h[111111],tot;
struct edg
{int p,t;}e[222222];
inline void build(int x,int y)
{e[++tot]=(edg){h[x],y},h[x]=tot;}
std::vector<int>v[111111];
int ext[111111];
int siz[111111],maxe[111111];
ll ans[111111];
int top[111111],ds[111111];
inline void insert(int C,int Id,int pos)
{
	v[Id].push_back(C);
	ext[C]++;
	if(ext[C]==maxe[pos])ans[pos]+=C;
	else if(ext[C]>maxe[pos])maxe[pos]=ext[C],ans[pos]=C;
}
void pre(int p=1,int f=0)
{
	register int i;
	int s=0;
	siz[p]=1;
	for(i=h[p];i;i=e[i].p)
	{
		int to=e[i].t;
		if(to==f)continue;
		pre(to,p);
		siz[p]+=siz[to];
		if(siz[to]>s)ds[p]=to,s=siz[to];
	}
}
void split(int p=1,int f=0,int t=1)
{
	register int i;
	top[p]=t;
	for(i=h[p];i;i=e[i].p)
	{
		int to=e[i].t;
		if(to==f)continue;
		if(to==ds[p])continue;
		split(to,p,to);
	}if(ds[p])split(ds[p],p,t);
}
void erase(int pos)
{
	register int i;
	for(i=0;i<v[pos].size();i++)
		ext[v[pos][i]]--;
}
void getans(int p=1,int f=0)
{
	register int i,ii;
	for(i=h[p];i;i=e[i].p)
	{
		int to=e[i].t;
		if(to==f)continue;
		if(to==ds[p])continue;
		getans(to,p);
	}if(ds[p])getans(ds[p],p);
	ans[p]=ans[ds[p]],maxe[p]=maxe[ds[p]];
	for(i=h[p];i;i=e[i].p)
	{
		int to=e[i].t;
		if(to==f)continue;
		if(to==ds[p])continue;
		for(ii=0;ii<v[to].size();ii++)
			insert(v[to][ii],top[p],p);
	}insert(c[p],top[p],p);
	if(p==top[p])erase(p);
}
int main()
{
	int n;
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y),build(x,y),build(y,x);
	}
	pre(),split(),getans();
	for(i=1;i<=n;i++)
		printf("%lld%c",ans[i],(i^n)?' ':'\n');
}