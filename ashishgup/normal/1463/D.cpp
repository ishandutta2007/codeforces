#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 4e5 + 5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= 2 * n; i++)
			b[i] = -1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			b[a[i]] = 1;
		}
		int mn = 0, mx = n;
		int pref = 0;
		for(int i = 1; i <= 2 * n; i++)
		{
			pref += b[i];
			mn = max(mn, pref);
		}
		for(int i = 2 * n; i >= 1; i--)
		{
			pref += b[i];
			mx = min(mx, n - pref);
		}
		cout << mx - mn + 1 << endl;
	}
	return 0;
}