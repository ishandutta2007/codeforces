#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N];

bool check(int x)
{
	int mn = 0, mx = 2e9;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != -1)
			continue;
		if(i - 1 >= 1 && a[i - 1] != -1)
		{
			mn = max(mn, a[i - 1] - x);
			mx = min(mx, a[i - 1] + x);
		}
		if(i + 1 <= n && a[i + 1] != -1)
		{
			mn = max(mn, a[i + 1] - x);
			mx = min(mx, a[i + 1] + x);
		}
	}
	if(mn <= mx)
		k = mn;
	return mn <= mx;
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
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int mn = 0;
		for(int i = 1; i + 1 <= n; i++)
		{
			if(a[i] != -1 && a[i + 1] != -1)
				mn = max(mn, abs(a[i + 1] - a[i]));
		}
		int m = binsearch(mn, 2e9);
		cout << m << " " << k << endl;
	}
	return 0;
}