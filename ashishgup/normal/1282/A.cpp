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
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if(a > b)
			swap(a, b);
		int ans = b - a;
		int L = max(a, c - r);
		int R = min(b, c + r);
		ans -= max(0LL, R - L);
		cout << ans << endl;
	}
	return 0;
}