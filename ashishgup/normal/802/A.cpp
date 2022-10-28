#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 4e5 + 5;
 
int n, k;
int a[N], cur[N];
set<pair<int, int> > s;
vector<int> pos[N];
set<int> have;
 
int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++)
	{
		pos[i].push_back(1e9);
		reverse(pos[i].begin(), pos[i].end());
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		s.erase({pos[a[i]].back(), a[i]});
		pos[a[i]].pop_back();
		if(have.find(a[i]) != have.end())
		{
			s.insert({pos[a[i]].back(), a[i]});
			continue;
		}
		ans++;
		if(have.size() == k)
		{
			pair<int, int> p = *s.rbegin();
			have.erase(p.second);
			s.erase(p);
		}
		have.insert(a[i]);
		s.insert({pos[a[i]].back(), a[i]});
	}
	cout << ans;
	return 0;
}