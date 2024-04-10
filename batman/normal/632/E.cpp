#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll int
ll tavan(ll a,ll n,ll mod){ll res=1;while(n)res*=(n&1)?a:1,res%=mod,a*=a,a%=mod,n/=2;return res;}
const ll N=1001;
const ll MOD=((ll)1e9+7);
const ll INF=((ll)2e9);

ll n,k,a[N],base,dp[N*N];

int main()
{
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	base=a[0]*k;
	for(int i=1;i<N*N;i++)dp[i]=INF;
	for(int i=1;i<n;i++)
	{
		a[i]-=a[0];
		for(int j=a[i];j<N*N;j++)
			dp[j]=min(dp[j],dp[j-a[i]]+1);
	}
	for(int i=0;i<N*N;i++)
		if(dp[i]<=k)
			printf("%d ",i+base);
	return 0;
}