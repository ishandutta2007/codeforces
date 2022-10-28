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
		int x, y;
		cin >> x >> y;
		set<int> vis;
		while(x > 1 && x < y)
		{
			if(vis.find(x) != vis.end())
				break;
			vis.insert(x);
			while(x % 2 == 0 && x < y)
			{
				x *= 3;
				x /= 2;
			}
			if(x > 1 && x < y)
				x--;
		}
		if(x >= y)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}