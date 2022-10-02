#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[200],h[10005],k[10005];
pair <int,int> a[1005];
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
		for(int i=1;i<=n;i++)
			cin >> k[i];
		for(int i=1;i<=n;i++)
			cin >> h[i];
		for(int i=1;i<=n;i++)
			a[i]={k[i]-h[i]+1,k[i]};
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(a[i-1].second>=a[i].first)
				a[i]={a[i-1].first,max(a[i-1].second,a[i].second)},a[i-1]={0ll,-1ll};
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=(a[i].second-a[i].first+1)*(a[i].second-a[i].first+2)/2;
		//	cout << a[i].first << " " << a[i].second << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}