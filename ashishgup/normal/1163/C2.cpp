#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;
 
int n, ans = 0;
int x[N], y[N];
map<pair<int, int>, int> m;
map<pair<int, int>, int> vis[N];
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int ydiff = y[j] - y[i];
			int xdiff = x[j] - x[i];
			if(xdiff == 0)
			{
				ydiff = 0;
				pair<int, int> p = {ydiff, xdiff};
				vis[j][p] = 1;
				if(vis[i][p])
					continue;
				vis[i][p] = 1;
				m[{ydiff, xdiff}]++;
			}
			else
			{
				int g = __gcd(ydiff, xdiff);
				ydiff /= g;
				xdiff /= g;
				if(xdiff < 0)
					xdiff *= -1, ydiff *= -1;
				if(ydiff == 0)
					xdiff = 1;
				pair<int, int> p = {ydiff, xdiff};
				vis[j][p] = 1;
				if(vis[i][p])
					continue;
				vis[i][p] = 1;
				m[{ydiff, xdiff}]++;
			}
		}
	}
	int sum = 0;
	for(auto &it:m)
	{
		sum += it.second;
		ans -= (it.second * (it.second - 1)) / 2;
	}
	ans += sum * (sum - 1) / 2;
	cout << ans;
	return 0;
}