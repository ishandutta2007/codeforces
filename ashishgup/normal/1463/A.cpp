#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int lo = 1, hi = 1e9;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			int red = mid / 7;
			int cura = max(0LL, a - red);
			int curb = max(0LL, b - red);
			int curc = max(0LL, c - red);
			if(min({cura, curb, curc}) == 0)
				hi = mid - 1;
			else
			{
				int midval = mid - mid / 7;
				if(midval == cura - 1 + curb - 1 + curc - 1)
					lo = hi = mid;
				else if(midval < cura - 1 + curb - 1 + curc - 1)
					lo = mid + 1;
				else
					hi = mid - 1;
			}
		}
		if((lo + 1) % 7 == 0 && 2 * (lo / 7) + lo + 3 == a + b + c)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}