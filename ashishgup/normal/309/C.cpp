#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 1e6 + 5;
 
int n, m;
int a[N], b[N], c[N];
int cnt[30];
 
bool check(int x)
{
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= x; i++)
		cnt[b[i]]++;
	for(int i = 1; i <= n; i++)
		c[i] = a[i];
	for(int i = 29; i >= 0; i--)
	{
		int reqd = cnt[i];
		for(int j = 1; j <= n; j++)
		{
			if(reqd == 0)
				break;
			int have = c[j] / (1 << i);
			int take = min(reqd, have);
			reqd -= take;
			c[j] -= (take * (1 << i));
		}
		if(reqd > 0)
			return 0;
	}
	return 1;
}
 
int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(check(mid))
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	int ans = binsearch(0, m);
	cout << ans;
	return 0;
}