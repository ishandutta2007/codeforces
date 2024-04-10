#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k;
map<int, vector<int> > m;

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		m[l].push_back(1);
		m[r + 1].push_back(-1);
	}
	vector<int> v;	
	int cur = 0;
	bool on = 0;
	for(auto &it:m)
	{
		for(auto &j:it.second)
			if(j == -1)
				cur--;
		if(cur < k && on)
		{
			v.push_back(it.first - 1);
			on = 0;
		}
		for(auto &j:it.second)
			if(j == 1)
				cur++;
		if(cur >= k && on == 0)
		{
			v.push_back(it.first);
			on = 1;
		}
	}
	cout << v.size() / 2 << endl;
	for(int i = 0; i < v.size(); i += 2)
		cout << v[i] << " " << v[i + 1] << endl;
	return 0;
}