#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)10*1000*1000+10)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)

ll dp[N],n,x,y;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x>>y;
    for(int i=1;i<=n;i++)dp[i]=min(dp[i-1]+x,dp[(i+1)/2]+y+((i%2)*x));
    cout<<dp[n];
	return 0;
}