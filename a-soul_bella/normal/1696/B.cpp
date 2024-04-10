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
		int now=0,ans=0,n;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			if(x==0)
			{
				now=0;
				continue;
			}
			if(!now) ++ans,now=1;
		}
		cout << min(ans,2ll) << "\n";
	}
	return 0;
}