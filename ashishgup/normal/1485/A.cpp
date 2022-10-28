#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		int ans = 2e9;
		for(int i = b; i <= b + 100; i++)
		{
			if(i == 1)
				continue;
			int cur = i - b;
			int val = a;
			while(val > 0)
			{
				val /= i;
				cur++;
			}
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}