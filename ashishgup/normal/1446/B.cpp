#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 5005;

int n, m;
string a, b;
int cache[N][N];

int dp(int i, int j)
{
	if(i < 0 || j < 0)
		return 0;
	int &ans = cache[i][j];
	if(ans != -1)
		return ans;
	ans = 0;
	ans = max(ans, dp(i - 1, j) - 1);
	ans = max(ans, dp(i, j - 1) - 1);
	if(a[i] == b[j])
		ans = max(ans, dp(i - 1, j - 1) + 2);
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> a >> b;
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			ans = max(ans, dp(i, j));
	cout << ans;
	return 0;
}