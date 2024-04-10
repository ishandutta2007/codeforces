
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;
 
int n, k;
int l[N], r[N];
int good[N], tot[N];
double cache[N][N];
 
int f(int x)
{
	int cur = 1;
	int cnt = 0;
	while(cur <= x)
	{
		int mx = cur + (cur - 1);
		mx = min(mx, x);
		cnt += max(0LL, mx - cur + 1);
		cur *= 10;
	}
	return cnt;
}
 
double dp(int i, int taken)
{
	if(i > n)
		return (taken * 100 >= n * k);
	double &ans = cache[i][taken];
	if(ans >= 0)
		return ans;
	ans = (double)good[i] / tot[i] * dp(i + 1, taken + 1) + ((double)tot[i] - good[i]) / tot[i] * dp(i + 1, taken);
	return ans;
 }
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i];
		good[i] = f(r[i]) - f(l[i] - 1);
		tot[i] = r[i] - l[i] + 1;
	}
	cin >> k;
	double ans = dp(1, 0);
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}