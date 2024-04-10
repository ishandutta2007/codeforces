#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

int n, m;
int k[N], reqd[N];
bool vis[N];
vector<int> g[N], cur[N];

int check(int x)
{
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++)
		reqd[i] = k[i];
	for(int i = 1; i <= 2e5; i++)
		cur[i].clear();
	for(int i = x; i >= 1; i--)
	{
		for(auto &it:g[i])
		{
			if(vis[it])
				continue;
			vis[it] = 1;
			cur[i].push_back(it);
		}
	}
	int have = 0;
	for(int i = 1; i <= x; i++)
	{
		have++;
		for(auto &it:cur[i])
		{
			int take = min(reqd[it], have);
			reqd[it] -= take;
			have -= take;
		}
	}
	int left = 0;
	for(int i = 1; i <= n; i++)
		left += reqd[i];
	left *= 2;
	return (left <= have);
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi) / 2;
		if(check(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	for(int i = 1; i <= m; i++)
	{
		int d, t;
		cin >> d >> t;
		g[d].push_back(t);
	}
	int ans = binsearch(1, 4e5);
	cout << ans << endl;
	return 0;
}