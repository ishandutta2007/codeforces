#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 55;

int n;
string s;
int a[N];
bool vis[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> s;
		map<char, int> have;
		for(auto &it:s)
			have[it]++;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		string ans(n + 1, '?');
		while(true)
		{
			map<int, vector<int> > idx;
			for(int i = 1; i <= n; i++)
			{
				if(!vis[i])
					idx[a[i]].push_back(i);
			}
			if(!idx.size())
				break;
			auto it = idx.begin();
			int reqd = it -> second.size();
			while(have.rbegin() -> second < reqd)
				have.erase(--have.end());
			for(auto &pos:it->second)
			{
				vis[pos] = 1;
				for(int i = 1; i <= n; i++)
					a[i] -= abs(i - pos);
				ans[pos] = have.rbegin() -> first;
			}
			have.erase(--have.end());
			idx.erase(it);
		}
		ans = ans.substr(1);
		cout << ans << endl;
	}
	return 0;
}