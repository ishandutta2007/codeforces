#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], pos[N], ans[N];
set<int> active;

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]] = i;
		active.insert(i);
	}
	int cur = 1;;
	for(int i = n; i >= 1; i--)
	{
		if(active.find(pos[i]) != active.end())
		{
			ans[pos[i]] = cur;
			vector<int> v;
			v.push_back(pos[i]);
			int idx = pos[i];
			int take = k;
			while(take > 0)
			{
				auto it = active.upper_bound(idx);
				if(it == active.end())
					break;
				v.push_back(*it);
				idx = *it;
				take--;
			}	
			take = k;
			idx = pos[i];
			while(take > 0)
			{
				auto it = active.lower_bound(idx);
				if(it == active.begin())
					break;
				it--;
				v.push_back(*it);
				idx = *it;
				take--;
			}
			for(auto &it:v)
				active.erase(it), ans[it] = cur;
			if(cur == 1)
				cur = 2;
			else
				cur = 1;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i];
	return 0;
}