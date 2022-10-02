#include <bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
int a[1000005],mx[100005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int ans=1;
		for(int i=n;i>=n-k+1;i--)
			if(a[i]!=-1&&a[i]!=0) ans=0;
		for(int i=1;i<=k;i++) ans=ans*i%mod;
		for(int i=1;i<=n-k;i++)
		{
			if(a[i]>=i) ans=0;
			else if(a[i]==-1) ans=(ans*(i+k))%mod;
			else if(a[i]==0) ans=(ans*(k+1))%mod;
		}
		cout << ans << "\n";
	}
	return 0;
}