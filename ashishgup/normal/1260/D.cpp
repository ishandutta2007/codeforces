#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
 
int m, n, k, t;
int a[N];
int l[N], r[N], d[N];
 
bool check(int x)
{
	int lim = a[x];
	int moves = n + 1, prv = 0, cur = 0;
	vector<pair<int, int> > v;
	for(int i = 1; i <= k; i++)
	{
		if(d[i] > lim)
			v.push_back({l[i], r[i]});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++)
	{
		int j = i;
		int r = v[i].second;
		while(j + 1 < v.size() && v[j + 1].first <= r)
		{
			j++;
			r = max(v[j].second, r);
		}
		moves += (r - v[i].first + 1) * 2;
		i = j;
	}
	return moves <= t;
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
	if(!check(lo))
		lo = 0;
	return lo;
}
 
int32_t main()
{
	IOS;
	cin >> m >> n >> k >> t;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	sort(a + 1, a + m + 1);
	reverse(a + 1, a + m + 1);
	for(int i = 1; i <= k; i++)
		cin >> l[i] >> r[i] >> d[i];
	int ans = binsearch(1, m);
	cout << ans;
	return 0;
}