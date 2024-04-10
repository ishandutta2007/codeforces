#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1005;

int n, m;
long double ans=0;
long double dp[N][N];

int32_t main()
{
    IOS;
    cin>>n>>m;
    dp[1][1]=1;
    for(int i=1;i<n;i++)
    {
    	for(int j=0;j<=i;j++)
    	{
    		long double rem_fav=m-j;
    		long double rem_nonfav=(n-1)*m - (i-j);
    		if(rem_fav<0 || rem_nonfav<0)
    			continue;
    		dp[i+1][j+1] += dp[i][j] * rem_fav/(rem_fav+rem_nonfav);
    		dp[i+1][j] += dp[i][j] * rem_nonfav/(rem_fav+rem_nonfav);
    	}
    }
    for(int i=1;i<=min(m, n);i++)
    {
    	ans+= dp[n][i] * (long double)i/n;
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}