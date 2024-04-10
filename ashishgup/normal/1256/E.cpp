#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, cnt = 0;
pair<int, int> a[N];
int cache[N];
int store[N];

int dp(int idx)
{
	if(idx > n)
		return 0;
	int &ans = cache[idx];
	if(ans != -1)
		return ans;
	ans = 1e18;
	int mn = min(a[idx].first, a[idx + 1].first);
	int mx = max(a[idx].first, a[idx + 1].first);
	for(int j = idx + 2; j <= min(n, idx + 10); j++)
	{
		mn = min(mn, a[j].first);
		mx = max(mx, a[j].first);
		ans = min(mx - mn + dp(j + 1), ans);
	}
	return ans;
}


void path(int idx)
{
	if(idx > n)
		return;
	int ans = dp(idx);
	int mn = min(a[idx].first, a[idx + 1].first);
	int mx = max(a[idx].first, a[idx + 1].first);
	for(int j = idx + 2; j <= min(n, idx + 10); j++)
	{
		mn = min(mn, a[j].first);
		mx = max(mx, a[j].first);
		if(ans == mx - mn + dp(j + 1))
		{
			cnt++;
			for(int k = idx; k <= j; k++)
				store[a[k].second] = cnt;
			return path(j + 1);
		}
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + n + 1);
	int ans = dp(1);
	path(1);
	cout << ans << " " << cnt << endl;
	for(int i = 1; i <= n; i++)
		cout << store[i] << " "; 
	return 0;
}