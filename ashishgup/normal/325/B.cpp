#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int calc(int x, int o)
{
	int n = (1LL << x) * o;
	int ans = 0;
	for(int i = 2; i <= (1LL << x); i *= 2)
	{
		ans += n / i;
		ans = min(ans, (int)2e18);
	}
	double xx = o;
	xx *= (xx - 1) / 2;
	if(xx > 2e18)
		return 2e18;
	ans += o * (o - 1) / 2;
	ans = min(ans, (int)2e18);
	return ans;
}	

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	vector<int> v;
	for(int x = 0; x <= 60; x++)
	{
		int o = 8e18 / (1LL << x);
		int base = 1, high = (o % 2 == 0)?(o - 1):o;
		int diff = (high - base) / 2;
		int lo = 0, hi = diff;
		int store = -1;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			int y = base + mid * 2;
			if(calc(x, y) < n)
				lo = mid + 1;
			else if(calc(x, y) > n)
				hi = mid - 1;
			else
			{
				store = y;
				break;
			}
		}
		if(calc(x, base + lo * 2) == n)
			store = base + lo * 2;
		if(store > -1)
			v.push_back((1LL << x) * store);
	}
	if(!v.size())
		cout << -1 << endl;
	else
	{
		sort(v.begin(), v.end());
		for(auto &it:v)
			cout << it << endl;
	}
	return 0;
}