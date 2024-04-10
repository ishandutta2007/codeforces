#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int M = 2005;

int n, m, k;
int a[N], pref[N];
int disc[N];
int cache[M];

int dp(int idx)
{
	if(idx == 0)
		return 0;
	int &ans = cache[idx];
	if(ans != -1)
		return ans;
	ans = 1e18;
	for(int j = 1; j <= idx; j++)
		ans = min(ans, pref[idx] - pref[idx - j + disc[j]] + dp(idx - j));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + a[i];
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		disc[x] = max(disc[x], y);
	}
	int ans = dp(k);
	cout << ans;
	return 0;
}