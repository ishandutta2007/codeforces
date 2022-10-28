#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, m, x, y, have;
int a[N];

bool check(int idx)
{
	int keep = abs(x - y);
	if(idx >= keep)
		return 0;
	int haveTime = ((x < y) ? x : n - x + 1) + abs(x - y);
	int cur = 0;
	for(int i = idx; i >= 1; i--)
		if(a[i] + (++cur) >= haveTime)
			return 0;
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
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> x >> y;
		for(int i = 1; i <= m; i++)
			cin >> a[i];
		// int diff = abs(x - y);
		// have = (diff + 1) / 2 - 1;
		// if(x < y)
		// 	have = have * 2 + x - 1;
		// else
		// 	have = have * 2 + n - x;
		sort(a + 1, a + m + 1);
		int ans = binsearch(0, m);
		cout << ans << endl;
	}
	return 0;
}