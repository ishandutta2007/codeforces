#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

vector<pair<char, int> > compress(string &s)
{
	vector<pair<char, int> > v;
	for(int i = 0; i < s.size();)
	{
		int j = i;
		while(j < s.size() && s[i] == s[j])
			j++;
		v.push_back({s[i], j - i});
		i = j;
	}
	return v;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		vector<pair<char, int> > v1 = compress(a), v2 = compress(b);
		if(v1.size() != v2.size())
			cout << "NO" << endl;
		else
		{
			bool check = 1;
			for(int i = 0; i < v1.size(); i++)
			{
				check &= (v1[i].first == v2[i].first);
				check &= (v1[i].second <= v2[i].second);
			}
			if(check)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}