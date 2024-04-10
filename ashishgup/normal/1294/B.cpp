#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
vector<pair<int, int> > v;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int x, y;
			cin >> x >> y;
			v.push_back({x, y});
		}
		sort(v.begin(), v.end());
		int curX = 0, curY = 0;
		string ans = "";
		bool flag = 1;
		for(auto &it:v)
		{
			if(it.first < curX || it.second < curY)
			{
				flag = 0;
				break;
			}
			while(curX < it.first)
			{
				curX++;
				ans += 'R';
			}
			while(curY < it.second)
			{
				curY++;
				ans += 'U';
			}
		}
		if(!flag)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			cout << ans << endl;
		}
	}
	return 0;
}