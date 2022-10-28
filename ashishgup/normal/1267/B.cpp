#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	vector<pair<char, int> > v;
	for(int i = 0; i < s.size(); i++)
	{
		int j = i;
		while(j + 1 < s.size() && s[i] == s[j + 1])
			j++;
		v.push_back({s[i], j - i + 1});
		i = j;
	}
	for(int i = 0, j = v.size() - 1; i < j; i++, j--)
	{
		if(v[i].first != v[j].first)
		{
			cout << 0;
			return 0;
		}
		if(v[i].second + v[j].second < 3)
		{
			cout << 0;
			return 0;
		}
	}
	int ans = 0;
	int sz = v.size();
	if(sz % 2)
	{
		if(v[sz / 2].second < 2)
			cout << 0;
		else
			cout << v[sz / 2].second + 1;
	}
	else
		cout << 0;
	return 0;
}