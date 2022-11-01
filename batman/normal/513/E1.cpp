#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)31*1000)
#define INF ((ll)2e9)

ll n,k,a[N],dp[2][N][2],ans;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int t=1;t<k;t++)
    {
    	bool p=(t&1),q=!p;
    	dp[p][0][0]=dp[p][0][1]=-INF;
    	ll maxi[2]={-INF,-INF};
    	ll now[2]={-INF,-INF};
    	for(int i=1;i<=n;i++)
    	{
    		now[1]=max(now[1],dp[q][i-1][0])+a[i]+(t!=1?a[i]:0);
    		now[0]=max(now[0],dp[q][i-1][1])-a[i]-(t!=1?a[i]:0);
    		dp[p][i][1]=max(now[1],maxi[1]);
    		dp[p][i][0]=max(now[0],maxi[0]);
			if(t!=1)maxi[0]=max(maxi[0],dp[q][i][0]);
			if(t!=1)maxi[1]=max(maxi[1],dp[q][i][1]);
		}
	}
	bool p=!(k&1);
	ll now0=-INF,now1=-INF;
	for(int i=1;i<=n;i++)
	{
		now1=max(now1,dp[p][i-1][0])+a[i];
		now0=max(now0,dp[p][i-1][1])-a[i];
		ans=max(ans,max(now0,now1));
	}
	cout<<ans;
	return 0;
}