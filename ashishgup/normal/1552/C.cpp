#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, k;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector<pair<int, int> > v;
		map<int, int> vis;
		for(int i = 1; i <= k; i++)
		{
			int x, y;
			cin >> x >> y;
			vis[x] = vis[y] = 1;
			if(x > y)
				swap(x, y);
			v.push_back({x, y});
		}
		vector<int> unvis;
		for(int i = 1; i <= 2 * n; i++)
			if(!vis[i])
				unvis.push_back(i);
		int sz = unvis.size();
		for(int i = 0, j = sz / 2; j < sz; i++, j++)
			v.push_back({unvis[i], unvis[j]});
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i = 0; i < v.size(); i++)
		{
			for(int j = i + 1; j < v.size(); j++)
			{
				if(v[j].second > v[i].second && v[j].first < v[i].second)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}