#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		map<pair<pair<int, int>, int>, int> m;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			int num = y2 - y1;
			int den = x2 - x1;
			int g = __gcd(num, den);
			num /= g;
			den /= g;
			if(num == 0)
				den = 1;
			if(den == 0)
				num = 0;
			if(num * den < 0 && num < 0)
				num *= -1, den *= -1;
			int cur = (x1 != x2) ? (x1 < x2) : (y1 < y2);
			pair<pair<int, int>, int> reqd = {{num, den}, cur ^ 1};
			ans += m[reqd];
			m[{{num, den}, cur}]++;
		}
		cout << ans << endl;
	}
	return 0;
}