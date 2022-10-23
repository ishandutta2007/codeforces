#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int ans[1000005];
int ksm(int x,int y)
{
	int rtn=1;
	while(y)
	{
		if(y&1) rtn=rtn*x%mod;
		x=x*x%mod,y>>=1;
	}
	return rtn;
}
int inv(int x)
{
	return ksm(x,mod-2);
}
int sum[1000005];
const int inv2=(mod+1)/2;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		for(int i=0;i<=n+1;i++) sum[i]=ans[i]=0;
		for(int i=n;i>=1;i--)
		{
			if(i*2>n)
			{
				ans[i]=1;
				sum[i]=(sum[i+1]+ans[i]*ksm(inv2,i))%mod;
				continue;
			}
			ans[i]+=(sum[i+1]-sum[min(n,i*2)])*ksm(2,i);
			ans[i]=(ans[i]%mod+mod)%mod;
			sum[i]=(sum[i+1]+ans[i]*ksm(inv2,i))%mod;
		}
		ans[n]=(ans[n]*2)%mod;
		for(int i=1;i<=n;i++)
		{
			cout << ans[i]*ksm(inv(2),(i+1)/2)%mod%mod << "\n";
		}
	}
	return 0;
}