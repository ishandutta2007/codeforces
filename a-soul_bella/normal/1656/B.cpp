#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
map <int,int> mp;
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
		mp.clear();
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			mp[a[i]]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(mp[a[i]-k]) ans=1;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}