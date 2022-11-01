#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (4444)
#define T (86401)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll n,k,dp[2*T],ans,t[N],d[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<2*T;i++)dp[i]=INF;
	t[0]=d[0]=0;
	t[n+1]=86401;
    for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&d[i]);
	for(int i=0;i<=n+1;i++)
	{
		bool mark[2*T]={};
		for(int j=T-1;j>=t[i]+d[i];j--)
			if(dp[j-d[i]]<INF && dp[j-d[i]]<=dp[j])
				dp[j]=dp[j-d[i]],mark[j]=1;
				
		ll mini=INF;
		for(int j=0;j<t[i];j++)
			mini=min(mini,dp[j]);		
		if(mini<=dp[t[i]+d[i]-1])
			dp[t[i]+d[i]-1]=mini,mark[t[i]+d[i]-1]=1;	
			
		for(int j=0;j<T;j++)
		{
			if(!mark[j])
				dp[j]++;
			if(dp[j]<=k)
				ans=max(ans,t[i+1]-j-1);		
		}	
		//cout<<dp[30000]<<" "<<dp[40000]<<"\n";
	}
	cout<<ans;
	
    return 0;
}