#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], b[N];

bool check(int x)
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i] >= x)
			b[i] = 1;
		else
			b[i] = -1;
	}
	map<int, int> mn, mx;
	int cur = 0;
	mn[cur] = 0;
	mx[cur] = 0;
	for(int i = 1; i <= n; i++)
	{
		cur += b[i];
		if(!mn.count(cur))
			mn[cur] = i, mx[cur] = i;
		else
			mx[cur] = i;
	}
	int store = n;
	for(auto &it:mn)
	{
		store = min(store, it.second);
		it.second = store;
		auto val = mx.upper_bound(it.first);
		if(val != mx.end())
		{
			int dist = val -> second - it.second;
			if(dist >= k)
				return 1;
		}
	}
	return 0;

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
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = binsearch(1, n);
	cout << ans;
	return 0;
}