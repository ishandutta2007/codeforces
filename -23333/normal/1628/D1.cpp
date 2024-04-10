#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=n;i--)
#define ll long long
const int N=5e5;
int n,m,k;
int dp[2005][2005];
const int mo=1e9+7;
int fsp(int x,int y)
{
	if (y==0) return 1;
	if (y==1) return x;
	ll ans=fsp(x,y/2);
	ans=ans*ans%mo;
	if (y%2==1) ans=ans*x%mo;
	return ans; 
}
int main()
{
	int T;
	cin>>T;
	int inv2=fsp(2,mo-2); 
	while (T--)
    {
    	cin>>n>>m>>k;
    	rep(i,1,n)
    	  rep(j,0,i)
		  {
		    if (j==0) dp[i][j]=dp[i-1][j];
		    else if (j==i) dp[i][j]=(dp[i-1][j-1]+k)%mo;
		    else dp[i][j]=1ll*(dp[i-1][j]+dp[i-1][j-1])*inv2%mo;
	      }
	    cout<<dp[n][m]<<endl;
	} 
	return 0; 
}