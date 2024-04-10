#include <bits/stdc++.h>
#define int long long
using namespace std;
bitset <20005> dp;
int a[105],b[105];
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
		int ans=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i++)
			cin >> b[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
				ans=(ans+(a[i]+a[j])*(a[i]+a[j])+(b[i]+b[j])*(b[i]+b[j]));
		}
		int x=0;
		for(int i=1;i<=n;i++) x+=a[i];
		ans-=x*x;
		x=0;
		for(int i=1;i<=n;i++) x+=b[i];
		ans-=x*x;
		dp.reset();
		dp[0]=1;
		for(int i=1;i<=n;i++)
			dp=(dp<<a[i])|(dp<<b[i]);
		int sum=0;
		for(int i=1;i<=n;i++) sum+=a[i]+b[i];
		int qsum=1e18;
		for(int i=n*200;i>=0;i--)
		{
			if(dp[i])
				qsum=min(qsum,i*i+(sum-i)*(sum-i));
		}
		cout << ans+qsum << "\n";
	}
	return 0;
}