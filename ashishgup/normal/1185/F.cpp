#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1024;

int n, m;
int satisfied[N];
vector<pair<int, int> > g[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		int mask = 0;
		for(int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			x--;
			mask |= (1 << x);
		}
		satisfied[mask]++;
	}
	for(int i = 1; i <= m; i++)
	{
		int cost;
		cin >> cost;
		int k;
		cin >> k;
		int mask = 0;
		for(int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			x--;
			mask |= (1 << x);
		}
		g[mask].push_back({cost, i});
	}
	for(int i = 0; i < 512; i++)
		sort(g[i].begin(), g[i].end());
	int idx1 = 1, idx2 = 2;
	int best = 0, minCost = 2e9 + 5;
	for(int i = 0; i < 512; i++)
	{
		if(!g[i].size())
			continue;
		for(int j = i; j < 512; j++)
		{
			if(!g[j].size())
				continue;
			if(i == j && g[i].size() < 2)
				continue;
			int curCost = 0;
			if(i != j)
				curCost = g[i][0].first + g[j][0].first;
			else
				curCost = g[i][0].first + g[i][1].first;
			int cur = 0;
			for(int k = 0; k < 512; k++)
			{
				bool check = 0;
				check |= (((i | j) & k) == k);
				if(check)
					cur += satisfied[k];
			}
			if(cur > best || (cur == best && curCost < minCost))
			{
				best = cur;
				minCost = curCost;
				idx1 = g[i][0].second;
				if(i == j)
					idx2 = g[i][1].second;
				else
					idx2 = g[j][0].second;
			}
		}
	}
	cout << idx1 << " " << idx2;
	return 0;
}