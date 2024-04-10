#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans = 0, sum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		sort(a + 1, a + n + 1);
		for(int i = 1; i <= n; i++)
		{
			int mx = a[n];
			if(i == n)
				mx = a[n - 1];
			int reqd = mx * (n - 1) - (sum - a[i]);
			int have = a[i];
			if(have <= reqd)
				ans = max(ans, reqd - have);
			else
			{
				have -= reqd;
				ans = max(ans, (n - 1 - (have % (n - 1))) % (n - 1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}