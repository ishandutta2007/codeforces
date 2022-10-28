#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, m;
int a[N], l[N], r[N];

int check(int x)
{
	for(int i = 1; i <= n; i++)
	{
		l[i] = a[i];
		r[i] = (a[i] + x) % m;
	}
	int cur = 0;
	for(int i = 1; i <= n; i++)
	{
		if(r[i] >= l[i])
		{
			if(cur > r[i])
				return 0;
			cur = max(cur, l[i]);
		}
		else
		{
			if(cur > r[i])
				cur = max(l[i], cur);
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
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = binsearch(0, m - 1);
	cout << ans;
	return 0;
}