#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int dp[N];
const int mo=1e9+7;
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	dp[0]=1;
	rep(i,1,4e4)
	{
	  int k=i,ans=0;
	  while (k)
	  {
	  	ans=ans*10+k%10;
	  	k/=10;
	  }
	  if (ans!=i) continue;
	  rep(j,i,4e4)
	    (dp[j]+=dp[j-i])%=mo;
	}
	while (T--)
	{
		//cin>>n>>m;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}