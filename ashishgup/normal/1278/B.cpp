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
		int a, b;
		cin >> a >> b;
		int d = abs(a - b);
		int x = 0, cur = 1;
		int ans = 0;
		while(x < d)
		{
			x += cur;
			ans++;
			cur++;
		}
		if(x == d)
			cout << ans << endl;
		else
		{
			while((d - x) % 2)
			{
				x += cur;
				cur++;
				ans++;
			}
			cout << ans << endl;
		}
	}
	return 0;
}