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
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		int ans = abs(a - b);
		if(a > b)
			swap(a, b);
		int mv = a - 1 + n - b;
		mv = min(mv, x);
		ans += mv;
		cout << ans << endl;
	}
	return 0;
}