#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (4400)
#define INF ((ll)1e9)

ll n,ans=1,a[N],dp[N][N];

int main()
{
	//ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for(int i=0;i<N;i++)dp[0][i]=1;
	for(int i=1;i<=n;i++)
	{
		ll last=0;
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++)
		{
			dp[j][i]=dp[last][j]+1;
			if(a[j]==a[i])last=j;
			ans=max(ans,dp[j][i]);
		}
			
	}	
	printf("%d",ans);		
    return 0;
}