#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 150005;

int n;
int a[N], f[N];
int cache[N][2][2];

int dp(int idx, int taken, int have)
{
	if(f[idx] - taken < 0)
		return -1e9;
	if(idx >= N)
		return 0;
	int &ans = cache[idx][taken][have];
	if(ans != -1)
		return ans;
	int curF = f[idx];
	if(taken)
		curF--;
	ans = dp(idx + 1, 0, 0);
	ans = max(ans, 1 + dp(idx + 1, 1, 0));
	if(curF > 0 || have > 0)
		ans = max(ans, 1 + dp(idx + 1, 0, 0));
	if(curF > 1 || (curF > 0 && have > 0))
		ans = max(ans, 1 + dp(idx + 1, 0, 1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	int ans = dp(1, 0, 0);
	cout << ans;
	return 0;
}