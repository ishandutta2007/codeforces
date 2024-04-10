#include <bits/stdc++.h>
using namespace std; 
#define ll int
#define N ((ll)101*1000)
#define K ((ll)20)

ll n,m,dp[2][(1<<K)+5][K];
string s[K];
char ex[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf(" %s",&ex),s[i]=ex;
	for(int i=0;i<m;i++)
	{
		ll res=0;
		for(int j=0;j<n;j++)if(s[j][i]=='1')res+=(1<<j);
		dp[1][res][0]++;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			for(int k=0;k<=n;k++)
				dp[(i&1)][j][k]=dp[!(i&1)][j][k]+dp[!(i&1)][j^(1<<i)][k-1];
	ll ans=(ll)1e9;
	for(int i=0;i<(1<<n);i++)
	{
		ll res=0;
		for(int k=0;k<=n;k++)res+=dp[!(n&1)][i][k]*min(k,n-k);
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}