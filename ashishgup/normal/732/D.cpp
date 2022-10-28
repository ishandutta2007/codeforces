#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, m;
int d[N], a[N], mark[N], vis[N];
 
int check(int x)
{
	memset(vis, 0, sizeof(vis));
	memset(mark, 0, sizeof(mark));
	for(int i = x; i >= 1; i--)
	{
		if(!d[i])
			continue;
		if(!vis[d[i]])
			mark[i] = 1;
		vis[d[i]] = 1;
	}
	for(int i = 1; i <= m; i++)
		if(!vis[i])
			return 0;	
	int have = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!mark[i])
			have++;
		else
		{
			int reqd = a[d[i]];
			if(reqd > have)
				return 0;
			have -= reqd;
		}
	}
	return 1;
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
	if(!check(lo))
		lo = -1;
	return lo;
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> d[i];
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	int ans = binsearch(1, n);
	cout << ans;
	return 0;
}