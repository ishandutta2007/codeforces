#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, p, k;
int a[N];

bool check(int x)
{
	int cost = 0;
	for(int i = x; i >= 1; i -= k)
	{
		cost += a[i];
		if(cost > p)
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
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> p >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int ans = binsearch(0, n);
		cout << ans << endl;
	}
	return 0;
}