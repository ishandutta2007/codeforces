#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
#define me(x) memset(x,0,sizeof(x))
#define IL inline
#define rint register int
const int N=1e6;
int dp[N],b[N],c[N];
int g[1010][1010*20];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	dp[1]=0;
	rep(i,2,1000) dp[i]=1e9;
	rep(i,1,1000)
	  rep(j,1,i)
	  {
	  	dp[i+i/j]=min(dp[i+i/j],dp[i]+1);
	  }
	rep(i,1,1000) assert(dp[i]<=20);
	while (T--)
	{
		int n,k;
		cin>>n>>k;
		rep(i,1,n) cin>>b[i],b[i]=dp[b[i]];
		int ans=0;
		rep(i,1,n) cin>>c[i],ans+=c[i];
		if (k>=20*n)
		{
			cout<<ans<<endl;
			continue;
		}
		rep(i,0,n)
		  rep(j,0,k) g[i][j]=-1e9;
		g[0][k]=0;
		rep(i,1,n)
		  rep(j,0,k)
		  {
		  	  g[i][j]=max(g[i][j],g[i-1][j]);
		  	  if (j+b[i]<=k) g[i][j]=max(g[i][j],g[i-1][j+b[i]]+c[i]);
		  }
		ans=0;
		rep(j,0,k) ans=max(ans,g[n][j]);
		cout<<ans<<endl;
	}
	return 0;
}