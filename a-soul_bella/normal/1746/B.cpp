#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int inf=1e18;
int a[1000005],n,c1[1000005],c0[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n;
		int flag=0;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=0;i<=n+1;i++) c1[i]=c0[i]=0;
		for(int i=1;i<=n;i++)
			c1[i]=c1[i-1]+(a[i]==1);
		for(int i=n;i>=0;i--)
			c0[i]=c0[i+1]+(a[i]==0);
		int ans=inf;
//		cout << c0[0] << "\n";
		for(int i=0;i<=n;i++) ans=min(ans,max(c1[i],c0[i+1]));
		cout << ans << "\n";
	}
	return 0;
}