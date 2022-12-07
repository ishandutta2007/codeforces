#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=100005;
const LL M=200005;
const LL MOD=1e9+7;
LL n,m;
struct qq
{
	LL x,y,z,last;
}e[M*2];LL num,last[N];
void init (LL x,LL y,LL z)
{
	num++;
	e[num].x=x;e[num].y=y;e[num].z=z;
	e[num].last=last[x];
	last[x]=num;
}
bool vis[N];
LL ans=0;
LL dep[N];
LL f[65];//
LL p[65][2];
void Ins (LL x)// 
{
	for (LL u=62;u>=0;u--)
		if ((x>>u)&1)
		{
			if (f[u]==0)	{f[u]=x;return ;}
			x^=f[u];
		}
}
void dfs (LL x,LL fa)
{
	for (LL u=0;u<=62;u++)	p[u][(dep[x]>>u)&1]++;
	vis[x]=true;
	for (LL u=last[x];u!=-1;u=e[u].last)
	{
		LL y=e[u].y;
		if (y==fa) continue;
		if (vis[y])	Ins(dep[x]^e[u].z^dep[y]);
		else
		{
			dep[y]=(dep[x]^e[u].z);
			dfs(y,x);
		}
	}
}
void add (LL &x,LL y)	{x=(x+y)%MOD;}
int main()
{
	memset(vis,false,sizeof(vis));
	num=0;memset(last,-1,sizeof(last));
	scanf("%I64d%I64d",&n,&m);
	for (LL u=1;u<=m;u++)
	{
		LL x,y,z;
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		init(x,y,z);init(y,x,z);
	}
	for (LL u=1;u<=n;u++)
		if (!vis[u])
		{
			memset(f,0,sizeof(f));
			memset(p,0,sizeof(p));
			dfs(u,0);
			LL cnt=0;
			for (LL u=0;u<=62;u++)
				if (f[u]!=0)
					cnt++;
			for (LL u=0;u<=62;u++)// 
			{
				bool tf=false;//1
				LL tot=0;
				for (LL i=0;i<=62;i++)
				{
					if ((f[i]>>u)&1)
					{
						tf=true;
						break;
					}
				}
				LL x;
				if (tf==true)//1 
				{
					LL z=(1LL<<cnt-1)%MOD;
					x=p[u][0]*(p[u][0]-1)/2;
					x%=MOD;
					add(tot,x*z%MOD);
					x=p[u][1]*(p[u][1]-1)/2;
					x%=MOD;
					add(tot,x*z%MOD);
					x=p[u][0]*p[u][1];
					x%=MOD;
					add(tot,x*z%MOD);
				}
				else
				{
					x=p[u][0]*p[u][1];
					x%=MOD;
					add(tot,(1LL<<cnt)%MOD*x%MOD);
				}
				add(ans,(1LL<<u)%MOD*tot%MOD);
			}
		}
	printf("%I64d\n",ans);
	return 0;
}