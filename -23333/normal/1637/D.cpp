#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=110;
int a[N],b[N],dp[N][N*N];
signed main()
{
//	freopen("1.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n; 
		cin>>n;
		int sum=0;
		int ans=0;
		rep(i,1,n) cin>>a[i],ans+=a[i],sum+=a[i]*a[i];
		rep(i,1,n) cin>>b[i],ans+=b[i],sum+=b[i]*b[i];
		rep(i,0,N-1)
		  rep(j,0,(N-1)*(N-1)) dp[i][j]=0;
		sum*=(n-2);
		dp[0][0]=1;
		rep(i,1,n)
		{
			rep(j,0,i*100)
			{
			  if (j>=a[i]) dp[i][j]|=dp[i-1][j-a[i]];
			  if (j>=b[i]) dp[i][j]|=dp[i-1][j-b[i]];
		    }
		}
		int gg=0;
		dep(i,(ans+1)/2,0) if (dp[n][i]) { gg=i; break;}
		sum+=gg*gg+(ans-gg)*(ans-gg);
		cout<<sum<<endl;
	}
	return 0; 
}