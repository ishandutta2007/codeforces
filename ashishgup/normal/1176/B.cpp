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
		int n;
		cin >> n;
		map<int, int> m;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			m[x % 3]++;
		}
		int ans = 0;
		for(int take = 0; take <= m[1]; take++)
		{
			int rem1 = m[1] - take;
			int rem2 = m[2] - take;
			if(rem2 < 0)
				break;
			int cur = m[0] + take + rem1 / 3 + rem2 / 3;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}