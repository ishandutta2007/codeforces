#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int f[2000],ni[2000];
const int mo=998244353;
int dp[60000][1026];
ll fsp(int x,int y)
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
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	rep(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		f[x]|=(1<<(y));
		f[y]|=(1<<(x)); 
	}
	rep(i,0,9) f[i]|=(1<<(i));
	dp[0][0]=1;
	ni[0]=1;
	rep(i,1,20) ni[i]=fsp(i,mo-2);
	ll ans=0;
	rep(i,0,n)
	  rep(j,0,1023)
	    if (dp[i][j])
	    {
	    	dp[i][j]=1ll*dp[i][j]*ni[__builtin_popcount(j)]%mo;
			if (i==n) (ans+=dp[i][j])%=mo;
	    	rep(k,0,9)
	    	{
	    		(dp[i+1][(j&f[k])|(1<<(k))]+=dp[i][j])%=mo; 
	    	}
	    }
	cout<<(ans%mo+mo)%mo<<endl;
	return 0; 
}