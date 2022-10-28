#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;
 
int n, m;
int store[N];
vector<int> g[5];
 
int calc(int i, int x)
{
	int val = g[2][x];
	int idx = min((int)g[1].size() - 1, i - 2 * (x + 1) - 1);
	if(idx >= 0)
		val += g[1][idx];
	return val;
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int w, c;
		cin >> w >> c;
		g[w].push_back(c);
	}
	for(int i = 1; i <= 3; i++)
	{
		sort(g[i].rbegin(), g[i].rend());
		int cur = 0;
		for(auto &it:g[i])
		{
			cur += it;
			it = cur;
		}
	}
	int ans = 0;
	store[1] = g[1].size()?g[1][0]:0;
	ans = max(ans, store[1]);
	for(int i = 2; i <= m; i++)
	{
		int ones = min(i, (int)g[1].size());
		if(ones - 1 >= 0)
			store[i] = g[1][ones - 1];
		int lo = 0, hi = min((int)g[2].size() - 1, i / 2 - 1);
		while(lo < hi - 2)
		{
			int m1 = (lo * 2 + hi) / 3;
			int m2 = (lo + hi * 2) / 3;
			if(calc(i, m1) > calc(i, m2))
				hi = m2;
			else
				lo = m1;
		}
		for(int j = lo; j <= hi; j++)
			store[i] = max(store[i], calc(i, j));
		ans = max(ans, store[i]);
		store[i] = max(store[i - 1], store[i]);
	}
	for(int i = 0; i < g[3].size() && (i + 1) * 3 <= m; i++)
		ans = max(ans, g[3][i] + store[m - 3 * (i + 1)]);
	cout << ans;
	return 0;
}