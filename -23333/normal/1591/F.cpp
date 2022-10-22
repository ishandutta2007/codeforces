#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
const int mo=998244353;
const int N=3e5;
ll a[N],s[N],s2[N],top;
ll dp[N],sum[N];
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	ll ans=0;
	dp[0]=1; sum[0]=1;
	rep(i,1,n)
	{
		while (top&&a[s[top]]>a[i]) ans-=s2[top],top--;
		ll gg=1ll*sum[i-1]*a[i];
		if (s[top]) gg-=(sum[s[top]-1]*a[i]);
		gg%=mo;
		(ans+=gg)%=mo;
		s[++top]=i; s2[top]=gg;
		dp[i]=ans;
		if (i%2==0) dp[i]=-dp[i];
		sum[i]=sum[i-1];
		if (i%2==0) (sum[i]+=dp[i])%=mo; else (sum[i]-=dp[i])%=mo;
	}
	cout<<(dp[n]%mo+mo)%mo<<"\n";
	return 0;
}