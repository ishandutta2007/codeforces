#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (101)
#define INF ((ll)1e16)
#define MOD ((ll)1e9+7)

ll n,a[10],dp[2][N][10],c[N][N],ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<N;i++)c[i][i]=c[i][0]=1;
	for(int i=1;i<N;i++)
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1],c[i][j]%=MOD;
	for(int i=0;i<10;i++)cin>>a[i],dp[0][0][i]=1;
	
	for(int i=1;i<=n;i++)
	{
		if(i>=a[0])dp[0][i][0]=1;
		for(int j=1,sum=a[0];j<10;sum+=a[j],j++)
			for(int k=a[j];k<=i-sum;k++)
			{
				dp[0][i][j]+=dp[0][i-k][j-1]*c[i][k],dp[0][i][j]%=MOD;
				if(k)dp[1][i][j]+=dp[0][i-k][j-1]*c[i-1][k-1],dp[1][i][j]%=MOD;
				dp[1][i][j]+=dp[1][i-k][j-1]*c[i-1][k],dp[1][i][j]%=MOD;
			}
		ans+=dp[1][i][9],ans%=MOD;			
	}
	cout<<ans;
    return 0;
}