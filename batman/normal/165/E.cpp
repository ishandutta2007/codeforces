#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n) {ll p=1;while(n>0){if(n%2){p=p*a;}n>>=1;a*=a;}return p;}
#define N (1001*1000)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,a[N],dp[5*N],now;

void dfs(ll x)
{
	dp[x]=now;
	ll x2=x;
	for(ll j=0;j<=21;j++)
	{
		if(x2%2==0 && !dp[x+(1<<j)])dfs(x+(1<<j));
		x2/=2;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		now=a[i];
		if(!dp[a[i]])dfs(a[i]);
	}
	for(int i=0;i<n;i++)
		printf("%d ",((dp[(1<<22)-1-a[i]]==0)?-1:dp[(1<<22)-1-a[i]]));
		
    return 0;
}