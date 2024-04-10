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
void exec()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)v[i].clear();
	rddi(a+1,n-1);
	rddi(s,n);
	for(int i=2;i<=n;i++)
		v[a[i]].push_back(i);
	dfs(1);
	printf("%lld\n",dp[1][1]+dp[1][0]);
} 
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}