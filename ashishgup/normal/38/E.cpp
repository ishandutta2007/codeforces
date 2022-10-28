#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3005;
 
int n;
int x[N], c[N];
pair<int, int> a[N];
bool vis[N][N];
int cache[N][N];
 
int dp(int i, int prv)
{
	if(i > n)
		return 0;
	int &ans = cache[i][prv];
	if(vis[i][prv])
		return ans;
	vis[i][prv] = 1;
	ans = min(c[i] + dp(i + 1, i), abs(x[i] - x[prv]) + dp(i + 1, prv));
	return ans;
}
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		x[i] = a[i].first;
		c[i] = a[i].second;
	}
	int ans = dp(2, 1) + c[1];
	cout << ans;
	return 0;
}