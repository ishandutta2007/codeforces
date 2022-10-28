//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N], b[N];
vector<int> g[5];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		g[1].clear();
		g[2].clear();
		int sum = 0, totsum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			totsum += a[i];
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> b[i];
			sum += b[i];
			g[b[i]].push_back(a[i]);
		}
		if(totsum < m)
		{
			cout << -1 << endl;
			continue;
		}
		sort(g[1].rbegin(), g[1].rend());
		sort(g[2].rbegin(), g[2].rend());
		for(int i = 1; i <= 2; i++)
		{
			int sum = 0;
			for(auto &j:g[i])
			{
				sum += j;
				j = sum;
			}
		}
		int idx = (int)g[2].size() - 1;
		int ans = 0, lose = g[2].size() * 2, cursum = 0;
		for(int i = 0; i <= g[1].size(); i++)
		{
			if(i >= 1)
				cursum = g[1][i - 1], lose++;
			while(idx - 1 >= 0 && g[2][idx - 1] + cursum >= m)
			{
				lose -= 2;
				idx--;
			}
			if(idx >= 0 && g[2][idx] + cursum >= m)
				ans = max(ans, sum - lose);
			if(i >= 1 && g[1][i - 1] >= m)
				ans = max(ans, sum - i);
		}
		cout << sum - ans << endl;
	}
	return 0;
}