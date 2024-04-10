#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for(int i = 0; i < 30; i++)
		{
			if((a >> i & 1) != (b >> i & 1))
				ans += (1 << i); 
		}
		cout << ans << endl;
	}
	return 0;
}