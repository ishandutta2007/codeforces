#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int m;
set<int> s;
vector<int> v, v2;

int get(int m)
{
	int sum = 0, cur = 0;
	for(int i = 0; i < v2.size(); i++)
	{
		while((sum + v2[i] * v2[i] * v2[i] <= m) && (sum + v2[i] * v2[i] * v2[i]) < (v2[i] + 1) * (v2[i] + 1) * (v2[i] + 1))
		{
			sum += v2[i] * v2[i] * v2[i], cur++;
		}
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin >> m;
	for(int i = 1; i <= 1e5; i++)
		v.push_back(i * i * i);
	int cur = 0, sum = 0;
	for(int i = 0; i + 1 < v.size(); i++)
	{
		while(sum + v[i] <= m && sum + v[i] < v[i + 1])
		{
			s.insert(i + 1);
			sum += v[i], cur++;
		}
	}
	for(auto &it:s)
		v2.push_back(it);
	int ans = 0, left = cur;
	int take = 1e18;
	cout << cur << " ";
	for(int i = v.size() - 1; i >= 0; i--)
	{
		while(take >= v[i] && m >= v[i] && left >= 1 && (get(min({m - v[i], take - v[i]})) >= left - 1))
		{
			take -= v[i];
			m -= v[i];
			left--;
			ans += v[i];
		}
		take = min(take, v[i]);
	}
	cout << ans + left;
	return 0;
}