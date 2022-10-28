#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k, ans = 0;
int l[N], r[N];
map<int, set<pair<int, int> > > events;
set<pair<int, int> > have;
vector<int> toRemove;

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		events[l[i]].insert({r[i] + 1, i});
		events[r[i] + 1].insert({-1, i});
	}	
	int cnt = 0;	
	for(auto &it:events)
	{
		for(auto &cur:it.second)
			if(cur.first < 0)
				cnt--;
		for(auto &cur:it.second)
		{
			if(cur.first > 0)
			{
				cnt++;
				have.insert(cur);
			}
		}
		while(cnt > k)
		{
			ans++;
			cnt--;
			pair<int, int> lastEnd = *have.rbegin();			
			have.erase(lastEnd);
			toRemove.push_back(lastEnd.second);
			events[lastEnd.first].erase({-1, lastEnd.second});
		}
	}
	cout << toRemove.size() << endl;
	for(auto &it:toRemove)
		cout << it << " ";
	return 0;
}