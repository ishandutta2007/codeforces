#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, h;
int a[N];

int check(int x)
{
	vector<int> v;
	for(int i = 1; i <= x; i++)
		v.push_back(a[i]);
	sort(v.begin(), v.end());
	int reqd = 0;
	while(v.size())
	{
		int cur = v.back();
		v.pop_back();
		if(v.size())
			v.pop_back();
		reqd += cur;
		if(reqd > h)
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
	cin >> n >> h;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = binsearch(1, n);
	cout << ans;
	return 0;
}