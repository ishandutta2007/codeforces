#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1005;

int n, m, k;
string s, t;
int cache[N][N], cache2[N][N][11];

int dp(int i, int j)
{
	if(i == n || j == m)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	if(s[i] == t[j])
		ans = 1 + dp(i + 1, j + 1);
	else
		ans = 0;
	return ans;
}

int dp2(int i, int j, int k)
{
	if(i == n || j == m)
		return 0;
	if(k == 0)
		return 0;
	int &ans = cache2[i][j][k];
	if(ans != -1)
		return ans;
	ans = max(dp2(i + 1, j, k), dp2(i, j + 1, k));
	int len = dp(i, j);
	if(len > 0)
		ans = max(ans, len + dp2(i + len, j + len, k - 1));
	return ans;
}	

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	cin >> n >> m >> k;
	cin >> s >> t;
	int ans = dp2(0, 0, k);
	cout << ans;
	return 0;
}