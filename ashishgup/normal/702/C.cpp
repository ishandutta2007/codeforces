#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];

int check(int r)
{
	int idx = 1;
	for(int i = 1; i <= m; i++)
	{
		while(idx <= n && a[idx] >= b[i] - r && a[idx] <= b[i] + r)
			idx++;
		if(idx > n)
			return 1;
	}
	return 0;
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
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	int ans = binsearch(0, 2e9);
	cout << ans;
	return 0;
}