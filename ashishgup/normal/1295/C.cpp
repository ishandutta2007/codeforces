#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

string s, t;

int32_t main()
{
	IOS;
	int tc;
	cin >> tc;
	while(tc--)
	{
		map<char, vector<int> > pos;
		cin >> s >> t;
		int n = s.size();
		int m = t.size();
		for(int i = 0; i < n; i++)
			pos[s[i]].push_back(i);
		int ans = 1, idx = -1, flag = 1;
		for(auto &it:t)
		{
			if(!pos.count(it))
			{
				flag = 0;
				break;
			}
			auto nxt = upper_bound(pos[it].begin(), pos[it].end(), idx);
			if(nxt == pos[it].end())
			{
				ans++;
				idx = pos[it][0];
			}
			else
				idx = *nxt;
		}
		if(!flag)
			ans = -1;
		cout << ans << endl;
	}
	return 0;
}