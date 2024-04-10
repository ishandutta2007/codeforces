#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k, z;
int a[N];
int cache[N][6][2];

int dp(int idx, int left, int prev, int moves)
{
	if(moves == k)
		return a[idx];
	int &ans = cache[idx][left][prev];
	if(ans != -1)
		return ans;
	ans = a[idx] + dp(idx + 1, left, 0, moves + 1);
	if(prev == 0 && left + 1 <= z)
		ans = max(ans, a[idx] + dp(idx - 1, left + 1, 1, moves + 1));
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k >> z;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= 5; j++)
				for(int k = 0; k <= 1; k++)
					cache[i][j][k] = -1;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = dp(1, 0, 1, 0);
		cout << ans << endl;
	}
	return 0;
}