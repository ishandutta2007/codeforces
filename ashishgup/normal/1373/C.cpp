//Need to leave around 9:30

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		n = s.size();
		int cur = 0, ans = 0;
		map<int, int> vis;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '+')
				cur++;
			else
				cur--;
			if(cur < 0 && !vis.count(cur))
			{
				vis[cur] = 1;
				ans += (i + 1);
			}
		}
		ans += n;
		cout << ans << endl;
	}
	return 0;
}