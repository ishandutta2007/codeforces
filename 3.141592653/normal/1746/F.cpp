#include<stdio.h>
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
using std::sort;
using std::min;
using std::max;
using std::swap;
typedef std::pair<int,int> pii;

void rddi(int*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%d",x+i);
	}
}
void rddl(ll*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lld",x+i);
	}
}
void rddd(db*x,int _C)
{
	for(int i=1;i<=_C;i++)
	{
		scanf("%lf",x+i);
	}
}
int n,k;
int a[1<<20],b[1<<20],s[1<<20],c[1<<20];
void clear()
{}
ll dp[1<<20][2];
std::vector<int>v[1<<20];
ll cs[1<<20];
void dfs(int p=1,int r=k)
{
	dp[p][0]=dp[p][1]=0;
	cs[p]=r-1;
	int ct=v[p].size();
	if(!ct)
	{
		dp[p][0]=(r-1)*1ll*s[p];
		dp[p][1]=s[p];
		return;
	}
	int d=(r-1)/ct+1;
	int rm=r-(d-1)*ct;
	ll ec=0,ex=0;
	std::vector<ll>det;
	for(int t:v[p])
		dfs(t,d),ec+=dp[t][0],det.push_back(dp[t][1]);
	std::sort(det.begin(),det.end());
	//printf("%d\n",rm); 
	for(int i=1;i<rm;i++)
	{
		ec+=det.back();
		det.pop_back();
	}
	ex=det.back();
	dp[p][0]=(r-1)*1ll*s[p]+ec;
	dp[p][1]=s[p]+ex;
	//printf("%d %d\n",dp[p][0],dp[p][1]);
}
std::mt19937_64 random_engine((size_t)(time(nullptr)));
std::map<int,int>ref;
typedef unsigned unt;
typedef unsigned long long chk;
chk sum[1<<20];
void upd(int x,chk det)
{
	for(;x<=n;x+=(x&(-x)))
		sum[x]+=det;
}
chk pfsum(int x)
{
	chk rt=0;
	for(;x;x-=(x&(-x)))
		rt+=sum[x];
	return rt;
}
int o[1<<20],x[1<<20],y[1<<20],z[1<<20];
unt f[1<<20],r[1<<20];
bool fx[1<<20];

void exec()
{
	scanf("%d%d",&n,&k);
	rddi(a,n);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!ref[a[i]])ref[a[i]]=++cnt;
		a[i]=ref[a[i]];
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",o+i,x+i,y+i);
		if(o[i]==2)
		{
			scanf("%d",z+i);
		}
		else
		{
			if(!ref[y[i]])ref[y[i]]=++cnt;
			y[i]=ref[y[i]];
		}
	}
	for(int T=1;T<=40;T++)
	{
		for(int i=1;i<=cnt;i++)
			r[i]=random_engine();
		for(int i=1;i<=n;i++)
			sum[i]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=r[a[i]];
			upd(i,f[i]);
		}
		for(int i=1;i<=k;i++)
		{
			if(o[i]==1)
			{
				unt z1=f[x[i]],z2=r[y[i]];
				f[x[i]]=z2;
				upd(x[i],(chk)z2-z1);
			}
			else if(!fx[i])
			{
				chk d = pfsum(y[i])-pfsum(x[i]-1);
				fx[i]=(d%z[i]!=0);
			}
		}
	}
	for(int i=1;i<=k;i++)
		if(o[i]==2)
			puts(fx[i]?"No":"Yes");
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}