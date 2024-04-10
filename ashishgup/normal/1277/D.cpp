#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int n;
vector<int> c[2][2];
string s[N];
set<string> have;
 
int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				c[i][j].clear();
		have.clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			have.insert(s[i]);
			c[s[i][0] - '0'][s[i].back() - '0'].push_back(i);
		}
		if(c[0][0].size() && c[1][1].size() && c[0][1].size() == 0 && c[1][0].size() == 0)
		{
			cout << -1 << endl;
			continue;
		}
		int sz1 = c[0][1].size(), sz2 = c[1][0].size();
		if(abs(sz1 - sz2) <= 1)
		{
			cout << 0 << endl;
			continue;
		}
		else if(sz1 > sz2)
		{
			int take = (sz1 - sz2) / 2;
			cout << take << endl;
			for(auto &it:c[0][1])
			{
				string rev = s[it];
				reverse(rev.begin(), rev.end());
				if(have.find(rev) != have.end())
					continue;
				take--;	
				cout << it << " ";
				if(take == 0)
					break;
			}
			cout << endl;
		}
		else
		{
			int take = (sz2 - sz1) / 2;
			cout << take << endl;
			for(auto &it:c[1][0])
			{
				string rev = s[it];
				reverse(rev.begin(), rev.end());
				if(have.find(rev) != have.end())
					continue;
				take--;	
				cout << it << " ";
				if(take == 0)
					break;
			}
			cout << endl; 
		}
	}
	return 0;
}