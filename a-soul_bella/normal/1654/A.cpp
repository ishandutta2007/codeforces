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
		int n;
		cin >> n;
		int mx=0,cd=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			if(x>mx) cd=mx,mx=x;
			else if(x>cd) cd=x;
		}
		cout << mx+cd << "\n";
	}
	return 0;
}