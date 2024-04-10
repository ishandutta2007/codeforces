#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n;
int a[N], b[N], c[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
			cin >> a[i] >> b[i];
		for(int i = 0; i < n; i++)
			c[i] = (a[i] - b[(i - 1 + n) % n]);
		int reqd = 0;
		for(int i = 0; i < n; i++)
			if(c[i] >= 0)
				reqd += c[i];
		int ans = 1e18;
		for(int i = 0; i < n; i++)
		{
			int cur = reqd - (c[i] > 0?c[i]:0) + a[i];
			ans = min(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}