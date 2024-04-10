#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int l, r;

int get(int x, int y)
{
	y = max(y, l);
	y = min(y, r);
	return x % y;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> l >> r;
		int m = max(l, r / 2 - 1);
		int ans = max({get(r, m), get(r, m + 1), get(r, m + 2), get(r, m + 3)});
		cout << ans << endl;
	}
	return 0;
}