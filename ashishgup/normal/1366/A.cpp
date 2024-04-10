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
		int a, b;
		cin >> a >> b;
		if(a < b)
			swap(a, b);
		int diff = a - b;
		int take = min(diff, b);
		int ans = take;
		a -= 2 * take, b -= take;
		ans += min({a, b, (a + b) / 3});
		cout << ans << endl;
	}
	return 0;
}