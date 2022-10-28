#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, K;
char a[N][N];
int cache[N][N][11];

int dp(int i, int j, int k)
{
	if(j < 1 || j > m)
		return -1e9;
	if(i == 0)
	{
		if(k == 0)
			return 0;
		return -1e9;
	}
	int &ans = cache[i][j][k];
	if(ans != -1)
		return ans;
	int nxtk = (k + a[i][j] - '0') % K;
	ans = a[i][j] - '0' + max(dp(i - 1, j - 1, nxtk), dp(i - 1, j + 1, nxtk));
	return ans;
}

void path(int i, int j, int k)
{
	if(i == 1)
		return;
	int &ans = cache[i][j][k];
	int nxtk = (k + a[i][j] - '0') % K;
	if(ans == (a[i][j] - '0' + dp(i - 1, j - 1, nxtk)))
	{
		cout << "L";
		path(i - 1, j - 1, nxtk);
	}
	else
	{
		cout << "R";
		path(i - 1, j + 1, nxtk);
	}
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> m >> K;
	K++;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	int maxAns = -1e9, idx = 0;
	for(int i = 1; i <= m; i++)
	{
		if(dp(n, i, 0) > maxAns)
		{
			maxAns = dp(n, i, 0);
			idx = i;
		}
	}
	if(maxAns < 0)
		cout << -1;
	else
	{
		cout << maxAns << endl;
		cout << idx << endl;
		path(n, idx, 0);
	}
	return 0;
}