#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int x, y;

vector<int> get(int x, int y)
{
	int cur = 3;
	vector<int> v;
	v.push_back(cur);
	while(cur < y + 1)
	{
		int lo = cur + 1, hi = y + 1;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			if(x / cur != x / mid)
				hi = mid;
			else
				lo = mid + 1;
		}
		if(x / lo != x / cur)
		{
			cur = lo;
			v.push_back(cur);
		}
		else
			break;
	}
	v.push_back(y + 2);
	return v;
}

int32_t main()
{
	IOS;
	//O(y log x)
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x >> y;
		int ans = 0;
		vector<int> v = get(x, y);
		for(int i = 3; i <= y + 1; i++)
		{
			int lo = 0, hi = x;
			while(lo < hi)
			{
				int mid = (lo + hi + 1) / 2;
				if(mid <= i * i - 2 * i)
					lo = mid;
				else
					hi = mid - 1;
			}
			ans += lo / i;
			if(lo == x)
			{
				i++;
				for(auto &it:v)
				{
					int range = max(0LL, it - i);
					ans += range * (x / i);
					i = max(i, it);
				}
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}