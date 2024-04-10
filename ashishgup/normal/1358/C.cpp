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
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int k = min(x2 - x1, y2 - y1);
		int ans = k * (k + 1);
		if(max(x2 - x1, y2 - y1) == k)
			ans -= k;
		else
		{
			int totDiag = x2 - x1 + y2 - y1 - 1;
			totDiag -= 2 * k;
			ans += totDiag * k;
		}
		ans++;
		cout << ans << endl;
	}
	return 0;
}