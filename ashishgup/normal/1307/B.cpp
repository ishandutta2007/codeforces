#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, x;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x;
		int mx = -1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(a[i] <= x)
				mx = max(mx, a[i]);
		}
		sort(a + 1, a + n + 1);
		int ans = 2e9;
		if(mx > 0)
		{
			ans = x / mx;
			if(x % mx)
				ans++;
		}
		if(a[n] > x)
			ans = min(ans, 2LL);
		cout << ans << endl;
	}	
	return 0;
}