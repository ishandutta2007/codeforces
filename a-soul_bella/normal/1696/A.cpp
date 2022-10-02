#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,z,ans=0;
		cin >> n >> z;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			ans=max(ans,x|z);
		}
		cout << ans << "\n";
	}
	return 0;
}