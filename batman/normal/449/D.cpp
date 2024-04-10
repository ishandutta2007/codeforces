#include <bits/stdc++.h>
using namespace std; 
#define ll int
#define N ((ll)1001*1000)
#define MOD ((ll)1e9+7)

ll n,dp[N],tvn[N];

int main()
{
	tvn[0]=1;for(int i=1;i<N;i++)tvn[i]=(tvn[i-1]*2)%MOD;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		ll x;scanf("%d",&x);
		dp[x]++;
	}
	for(int i=0;i<21;i++)
		for(int j=0;j<(1<<21);j++)
			if(!(j&(1<<i)) && j+(1<<i)<N)
				dp[j]+=dp[j+(1<<i)];
	ll ans=tvn[n];
	for(int i=1;i<N;i++)ans+=tvn[dp[i]]*((__builtin_popcount(i)%2)?-1:1),ans%=MOD;
	ans+=MOD;ans%=MOD;
	cout<<ans;
	return 0;
}