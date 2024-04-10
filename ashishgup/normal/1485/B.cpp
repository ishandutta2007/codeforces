#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, q, k;
int a[N], range[N], pref[N];

int32_t main()
{
	IOS;
	cin >> n >> q >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n - 1; i++)
		range[i] = a[i + 1] - a[i - 1] - 1;
	for(int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + range[i];
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		if(l == r)
			cout << k - 1 << endl;
		else
		{
			int ans = a[l + 1] - 1;
			ans += k - a[r - 1];
			ans += pref[r - 1] - pref[l];
			ans -= (r - l + 1);
			cout << ans << endl;
 		}
	}
	return 0;
}