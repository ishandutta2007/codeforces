#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100500
#define ll long long
int n,m,a,b,c,d,v[N],dp[N],ct;
ll x,y;
pair<ll,ll> s[N];
int main()
{
	scanf("%d",&n);
	scanf("%d/%d%d/%d",&a,&b,&c,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		ll nx=c*x-d*y,ny=b*y-a*x;
		if(nx<=0||ny<=0)continue;
		s[++m]=make_pair(nx,ny);
	}
	for(int i=1;i<=m;i++)s[i].second*=-1;
	sort(s+1,s+m+1);
	for(int i=1;i<=m;i++)s[i].first=-i,s[i].second*=-1,swap(s[i].first,s[i].second);
	sort(s+1,s+m+1);
	for(int i=1;i<=m;i++)v[i]=-s[i].second;
	for(int i=1;i<=m;i++)
	{
		int v1=lower_bound(dp+1,dp+ct+1,v[i])-dp;
		dp[v1]=v[i];ct+=v1==ct+1;
	}
	printf("%d\n",ct);
}