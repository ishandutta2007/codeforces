#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

bool check(int x)
{
	map<int, int> vis;
	int prv = -1e9;
	for(int i = x + 1, j = n; i <= j; true)
	{
		int mn = min(a[i], a[j]);
		if(mn < prv)
			return 0;
		if(vis[mn])
			return 0;
		while(i <= j && a[i] == mn)
			i++;
		while(j >= i && a[j] == mn)
			j--;
		vis[mn] = 1;
		prv = mn;
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
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = binsearch(0, n - 1);
		cout << ans << endl;
	}
	return 0;
}