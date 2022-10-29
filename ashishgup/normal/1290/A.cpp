#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		k = min(k, m - 1);
		int ans = 0;
		for(int f = 0; f <= k; f++)
		{
			int l = 1 + f;
			int r = (n - (m - 1 - f));
			int mn = 2e9;
			while(r <= (n - (k - f)))
			{
				mn = min(mn, max(a[l], a[r]));
				l++;
				r++;
			}
			ans = max(ans, mn);
		}
		cout << ans << endl;
	}
	return 0;
}