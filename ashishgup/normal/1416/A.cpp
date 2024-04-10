#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

int n;
int a[N], ans[N];
vector<int> pos[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			pos[i].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans[i] = 1e9;
			pos[a[i]].push_back(i);
		}
		for(int i = 1; i <= n; i++)
		{
			if(!pos[i].size())
				continue;
			int diff = max(pos[i][0], n + 1 - pos[i].back());
			for(int j = 0; j + 1 < pos[i].size(); j++)
				diff = max(diff, pos[i][j + 1] - pos[i][j]);
			ans[diff] = min(ans[diff], i);
		}
		for(int i = 1; i <= n; i++)
		{
			if(i >= 2)
				ans[i] = min(ans[i], ans[i - 1]);
			int cur = ans[i];
			if(cur == 1e9)
				cur = -1;
			cout << cur << " ";
		}
		cout << endl;
	}
	return 0;
}