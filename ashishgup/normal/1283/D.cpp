#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N];
vector<int> ans;
map<int, int> vis;
set<pair<int, int> > s;

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		vis[a[i]] = 1;
		s.insert({0, a[i]});
	}
	int dist = 0;
	while(ans.size() < m)
	{
		auto x = *s.begin();
		s.erase(x);
		if(!vis[x.second])
		{
			dist += x.first;
			ans.push_back(x.second);
		}
		if(!vis.count(x.second + 1))
			s.insert({x.first + 1, x.second + 1});
		if(!vis.count(x.second - 1))
			s.insert({x.first + 1, x.second - 1});
		vis[x.second] = 1;
	}
	cout << dist << endl;
	sort(ans.begin(), ans.end());
	for(auto &it:ans)
		cout << it << " ";
	return 0;
}