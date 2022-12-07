#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,m;
LL exgcd (LL a,LL b,LL &x,LL &y)
{
	if (a==0)	{x=0;y=1;return b;}
	LL tx,ty;
	LL d=exgcd(b%a,a,tx,ty);
	x=ty-(b/a)*tx;y=tx;
	return d;
}
bool ok[N];
struct qq
{
	LL x,y,last;
}e[N*30];LL num,last[N];
LL d[N];
void init (LL x,LL y)
{
	num++;d[y]++;
	e[num].x=x;e[num].y=y;
	e[num].last=last[x];
	last[x]=num;
}
LL tx,ty;
vector<LL> vec[N];
LL sta[N],belong[N],top,cnt;
LL dfn[N],low[N],id;
bool in[N];
LL tot[N];
void dfs (LL x)
{
	low[x]=dfn[x]=++id;
	in[x]=true;sta[++top]=x;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (dfn[y]==-1)	{dfs(y);low[x]=min(low[x],low[y]);}
		else if (in[y]) low[x]=min(low[x],dfn[y]);
	}
	if (low[x]==dfn[x])
	{
		cnt++;LL now;
		do
		{
			now=sta[top--];
			belong[now]=cnt;
			in[now]=false;
			if (ok[now]==true) 
			{
				tot[cnt]++;
				
				vec[cnt].push_back(now);
			}
		}while (now!=x);
	}
}
LL f[N];
LL from[N];
LL Ans[N];
void solve ()
{
	queue<int> q;
	for (LL u=1;u<=cnt;u++)
		if (d[u]==0)
			{q.push(u);from[u]=-1;}
	while (!q.empty())
	{
		LL x=q.front();q.pop();
	//	printf("YES:%lld %lld %lld\n",x,tot[x],f[x]);
		for (LL u=last[x];u!=-1;u=e[u].last)
		{
			LL y=e[u].y;
			if (f[x]+tot[x]>f[y])
			{
				from[y]=x;
				f[y]=f[x]+tot[x];
			}
			d[y]--;
			if (d[y]==0)
				q.push(y);
		}
	}
	LL ans=0,id;
	for (LL u=1;u<=cnt;u++)
	{
		if (tot[u]+f[u]>ans)
		{
			ans=tot[u]+f[u];
			id=u;
		}
	}
	if (ok[0]) ans++;
	printf("%lld\n",ans);
	cnt=0;
	while (id!=-1)
	{
		for (LL u=0;u<vec[id].size();u++)
			Ans[++cnt]=vec[id][u];
		id=from[id];
	}
	/*for (LL u=cnt;u>=1;u--) printf("%lld ",Ans[u]);
	printf("\n");*/
	if (cnt!=0) printf("%lld ",Ans[cnt]);
	for (LL u=cnt-1;u>=1;u--)
	{
		LL d=exgcd(Ans[u+1],m,tx,ty);
		tx=(tx*(Ans[u]/d)%(m/d)+(m/d))%(m/d);
		printf("%lld ",tx);
	//	printf("%lld %lld %lld %lld %lld\n",Ans[u-1],Ans[u],tx,m,d);
	}
	if (ok[0]) printf("0");
}
int main()
{
	num=0;memset(last,-1,sizeof(last));
	memset(ok,true,sizeof(ok));
	scanf("%lld%lld",&n,&m);
	if (m==1)
	{
		if (n==0) printf("1\n0");
		else printf("0\n");
		return 0;
	}
	for (LL u=1;u<=n;u++)	{LL x;scanf("%lld",&x);ok[x]=false;}
	for (LL u=1;u<m;u++)
	{
		for (LL i=u+u;i<m;i+=u)	init(u,i);
		LL d=exgcd(u,m,tx,ty);
		
		//printf("%lld %lld\n",u,d);
		if (d!=u) init(u,d);
	}
	/*for (LL u=1;u<=num;u++)
		printf("%lld %lld\n",e[u].x,e[u].y);*/
	memset(in,false,sizeof(in));
	memset(dfn,-1,sizeof(dfn));
	dfs(1);
	/*for (LL u=1;u<=cnt;u++) printf("%lld ",tot[u]);
	printf("\n");*/
	num=0;memset(last,-1,sizeof(last));
	memset(d,0,sizeof(d));
	for (LL u=1;u<m;u++)
	{
		for (LL i=u+u;i<m;i+=u)	
		{
			if (belong[u]!=belong[i])	init(belong[u],belong[i]);
		}
		LL d=exgcd(u,m,tx,ty);
		if (d!=u) 
		{
			if (belong[u]!=belong[d])	init(belong[u],belong[d]);
		}
	}
/*	for (LL u=1;u<=cnt;u++)
	{
		printf("%lld:",u);
		for (LL i=0;i<vec[u].size();i++)
			printf("%lld ",vec[u][i]);
		printf("\n");
	}*/
	/*for (LL u=1;u<=num;u++)
		printf("%lld %lld\n",e[u].x,e[u].y);*/
	solve();
	return 0;
}