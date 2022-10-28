#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int x[N], y[N], z[N];
map<pair<int, int>, vector<pair<int, int> > > m;
map<int, vector<pair<int, int> > > m2;
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
		m[{x[i], y[i]}].push_back({z[i], i});
	}
	for(auto &it:m)
	{
		sort(it.second.begin(), it.second.end());
		int sz = it.second.size();
		for(int i = 0; i + 1 < sz; i += 2)
			cout << it.second[i].second << " " << it.second[i + 1].second << endl;
		if(sz % 2)
			m2[it.first.first].push_back({it.first.second, it.second.back().second});
	}
	for(auto &it:m2)
	{
		sort(it.second.begin(), it.second.end());
		int sz = it.second.size();
		for(int i = 0; i + 1 < sz; i += 2)
			cout << it.second[i].second << " " << it.second[i + 1].second << endl;
		if(sz % 2)
			v.push_back({it.first, it.second.back().second});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i += 2)
		cout << v[i].second << " " << v[i + 1].second << endl;
	return 0;
}