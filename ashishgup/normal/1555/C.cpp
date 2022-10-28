#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[3][N], pref[3][N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= 2; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin >> a[i][j];
				pref[i][j] = pref[i][j - 1] + a[i][j];
			}
		}
		int ans = 1e12;
		for(int i = 1; i <= n; i++)
		{
			int curSum = max(pref[2][i - 1], (pref[1][n] - pref[1][i]));
			ans = min(ans, curSum);
		}
		cout << ans << endl;
	}
	return 0;
}