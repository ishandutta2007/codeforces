#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int x;
		int mx = 0;
		for(int i = 1; i <= n; i++)
		{
			int cur;
			cin >> cur;
			if(i == 1)
				x = cur;
			else
				mx += cur;
		}
		mx = min(mx, m - x);
		x += mx;
		cout << x << endl;
	}
	return 0;
}