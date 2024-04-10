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
		int n,m;
		cin >> n >> m;
		int mn=1e18;
		pair<int,int> mx={0,0};
		for(int i=1;i<=n;i++)
		{
			int s=0;
			for(int j=1;j<=m;j++)
			{
				int x;
				cin >> x;
				s+=x*j;
			}
			mx=max(mx,{s,i});
			mn=min(mn,s);
		}
		cout << mx.second << " " << mx.first-mn << "\n";
	}
	return 0;
}