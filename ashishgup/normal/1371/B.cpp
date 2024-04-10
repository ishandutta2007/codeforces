#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, r;
		cin >> n >> r;
		int ans = 0;
		r = min(r, n);
		if(r < n)
			ans += r * (r + 1) / 2;
		else
			ans += (n - 1) * n / 2;
		if(r == n)
			ans++;
		cout << ans << endl;
	}
	return 0;
}