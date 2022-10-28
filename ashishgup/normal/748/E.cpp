#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;
const int M = 1e7 + 5;

int n, k, mx;
int a[N], cnt[M];

int check(int x)
{
	for(int i = 0; i < x; i++)
		cnt[i] = 0;
	cnt[x] = 1;
	for(int i = x + 1; i <= mx; i++)
	{
		cnt[i] = 1;
		int couldBe = cnt[i / 2] + cnt[i / 2 + (i % 2)];
		cnt[i] = max(cnt[i], couldBe);  
	}
	long long have = 0;
	for(int i = 1; i <= n; i++)
	{
		have += cnt[a[i]];
		if(have >= k)
			return 1;
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
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if(sum < k)
	{
		cout << -1;
		return 0;
	}
	int ans = binsearch(1, mx);
	cout << ans;
	return 0;
}