#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)87)
#define K ((ll)11)
#define INF ((ll)1e18+1000)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll t,n,dp[2][N],f[N];
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<N && INF-f[i-1]>f[i-2];i++)f[i]=f[i-1]+f[i-2];
	while(t--)
	{
		cin>>n;
		for(int i=N-1;i>0;i--)
		{
			if(n>=f[i])n-=f[i],mark[i]=1;
			else mark[i]=0;
		}
		dp[1][1]=1;dp[0][1]=1-mark[1];
		dp[1][2]=1;dp[0][2]=1-mark[2];
		
		for(int i=3;i<N;i++)
		{
			if(!mark[i])
			{
				dp[1][i]=dp[1][i-1];
				if(mark[i-1])dp[0][i]=dp[1][i-1];
				else dp[0][i]=dp[1][i-1]+dp[0][i-2];	
			}
			else 
			{
				dp[1][i]=dp[0][i-2]+dp[1][i-1];
				if(mark[i-1])dp[0][i]=0;
				else dp[0][i]=dp[0][i-2];
			}
		}
		cout<<dp[1][N-1]<<"\n";
	}
	return 0;
}