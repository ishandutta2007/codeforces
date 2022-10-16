#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int n;
typedef double db;
db w[1111111],del[1111111];
#include<vector>
struct pii
{int t;db l;};
std::vector<pii>v[1111111];
int siz[1111111];
bool vis[1111111];
void dfs(int p,int f=0)
{
	siz[p]=1;
	for(auto t:v[p])
		if(t.t^f)
			if(!vis[t.t])
				dfs(t.t,p),siz[p]+=siz[t.t];
}
int getg(int p)
{
	dfs(p);
	int rm=siz[p];
	for(;;)
	{
		for(auto t:v[p])
			if(!vis[t.t])
				if(siz[t.t]<siz[p])
					if(siz[t.t]*2>rm)
					{p=t.t;goto T;}
		break;T:;
	}return p;
}
#include<cmath>
db delta(int p,int f,db len)
{
	db ret=1.5*w[p]*sqrt(len);
	for(auto t:v[p])
		if(t.t^f)
			ret+=delta(t.t,p,len+t.l);
	return ret;
}db calc(int p,int f=0,db len=0)
{
	db ret=w[p]*len*sqrt(len);
	for(auto t:v[p])
		if(t.t^f)
			ret+=calc(t.t,p,len+t.l);
	return ret;
}
db mxx=1e100;
int asp;
void solve()
{
	int s=1;
	while(1)
	{
		s=getg(s),vis[s]=1;
		db ans=calc(s);
		if(ans<mxx)mxx=ans,asp=s;
		if(siz[s]==1)break;
		db ssd=0;
		for(auto t:v[s])
			if(!vis[t.t])
				ssd+=(del[t.t]=delta(t.t,s,t.l));
		for(auto t:v[s])
			if(!vis[t.t])
				if(delta(t.t,s,t.l)*2>=ssd)
				{s=t.t;goto T;}
		break;T:;
	}
}
int main()
{
	scanf("%d",&n);
	register int i;
	for(i=1;i<=n;i++)scanf("%lf",w+i);
	for(i=1;i<n;i++)
	{
		int x,y;
		db l;
		scanf("%d%d%lf",&x,&y,&l);
		v[x].push_back(pii{y,l}),v[y].push_back(pii{x,l});
	}solve(),printf("%d %.15lf\n",asp,mxx);
}
/*
Just go for it.
*/