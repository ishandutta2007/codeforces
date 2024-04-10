#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int sz[5], idx[5];
set<int> store[5];

int get(set<pair<int, int> > &s)
{
	vector<int> v;
	for(auto &it:s)
		v.push_back(it.first);
	int ans = 0;
	for(int i = 0; i < v.size(); i++)
		for(int j = i + 1; j < v.size(); j++)
			ans += (v[i] - v[j]) * (v[i] - v[j]);
	return ans;
}

int get2(int a, int b, int c)
{
	return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

int great(int idx, int val)
{
	auto it = store[idx].lower_bound(val);
	if(it == store[idx].end())
		return -1;
	return *it;
}

int lesser(int idx, int val)
{
	auto it = store[idx].lower_bound(val);
	if(it == store[idx].begin())
		return -1;
	it--;
	return *it;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int ans = 4e18;
		for(int i = 1; i <= 3; i++)
		{
			store[i].clear();
			idx[i] = 0;
			cin >> sz[i];
		}
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= sz[i]; j++)
			{
				int x;
				cin >> x;
				store[i].insert(x);
			}
		}
		for(auto &it:store[1])
		{
			int a = it;
			{
				int b = lesser(2, a);
				int c = lesser(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = lesser(2, a);
				int c = great(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(2, a);
				int c = lesser(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(2, a);
				int c = great(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
		}
		for(auto &it:store[2])
		{
			int a = it;
			{
				int b = lesser(1, a);
				int c = lesser(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = lesser(1, a);
				int c = great(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(1, a);
				int c = lesser(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(1, a);
				int c = great(3, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
		}
		for(auto &it:store[3])
		{
			int a = it;
			{
				int b = lesser(1, a);
				int c = lesser(2, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = lesser(1, a);
				int c = great(2, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(1, a);
				int c = lesser(2, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
			{
				int b = great(1, a);
				int c = great(2, a);
				if(b > 0 && c > 0)
					ans = min(ans, get2(a, b, c));
			}
		}
		cout << ans << endl;
	}
	return 0;
}