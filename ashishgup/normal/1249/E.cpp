#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, c;
int a[N], b[N], ans[N];
int cache[N][2];

int dp(int idx, int elev)
{
	if(idx == 0)
		return 0;
	int &ans = cache[idx][elev];
	if(ans != -1)
		return ans;
	ans = dp(idx - 1, 0) + a[idx];
	if(!elev)
		ans = min(ans, c + b[idx] + dp(idx - 1, 1));
	else
		ans = min(ans, b[idx] + dp(idx - 1, 1));
	return ans;
}	

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> c;
	for(int i = 1; i <= n - 1; i++)
		cin >> a[i];
	for(int i = 1; i <= n - 1; i++)
		cin >> b[i];
	cout << 0 << " ";
	for(int i = 1; i <= n - 1; i++)
		cout << dp(i, 0) << " ";
	return 0;
}