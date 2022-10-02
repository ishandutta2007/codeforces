#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >> x;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		x*=2;
		int mn=a[1],mx=a[1],ans=0;
		for(int i=1;i<=n;i++)
		{
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
			if(mx-mn>x) ++ans,mn=mx=a[i];
		}
		cout << ans << "\n";
	}
	return 0;
}