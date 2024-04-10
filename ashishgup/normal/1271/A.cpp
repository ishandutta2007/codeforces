#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	for(int i = 0; i <= 1e5; i++)
	{
		if(a < i || d < i)
			break;
		int j = min({b, c, d - i});
		ans = max(ans, i * e + j * f);
	}
	cout << ans;
	return 0;
}