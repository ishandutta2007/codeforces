#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int m, d, w;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> m >> d >> w;
		int n = min(m, d);
		if(d == 1)
		{
			int ans = n * (n - 1) / 2;
			cout << ans << endl;
			continue;
		}
		if(d % w == 0)
		{
			int period = n / w;
			int ans = w * period * (period - 1) / 2;
			ans += (n % w) * period;
			cout << ans << endl;
			continue;
		}
		int x = d - 1, curw = w;
		for(int i = 2; i * i <= x; i++)
		{
			while(x % i == 0 && curw % i == 0)
			{
				x /= i;
				curw /= i;
			}
			while(x % i == 0)
				x /= i;
		}
		if(curw % x == 0)
			curw /= x;
		w = curw;
		int period = n / w;
		int ans = w * period * (period - 1) / 2;
		ans += (n % w) * period;
		cout << ans << endl;
	}
	return 0;
}