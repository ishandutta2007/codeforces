#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n, m;
int r[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> r[i];
		cin >> m;
		for(int i = 1; i <= m; i++)
			cin >> b[i];
		int ans = 0;
		int mx1 = 0, mx2 = 0;
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			sum += r[i];
			mx1 = max(mx1, sum);
		}
		sum = 0;
		for(int i = 1; i <= m; i++)
		{
			sum += b[i];
			mx2 = max(mx2, sum);
		}
		sum = 0;
		for(int i = 1; i <= n; i++)
		{
			sum += r[i];
			ans = max(ans, sum + mx2);
		}
		sum = 0;
		for(int i = 1; i <= m; i++)
		{
			sum += b[i];
			ans = max(ans, sum + mx1);
		}
		cout << ans << endl;
	}
	return 0;
}