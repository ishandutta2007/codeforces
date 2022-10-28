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
	set<int> s;
	while(t--)
	{
		int x;
		cin >> x;
		int lo = 1, hi = 1e9;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			int r = mid * (mid + 1) / 2;
			if(r < x)
				lo = mid + 1;
			else
			{
				int mnsub = 2, mxsub = r + mid;
				int reqd = r - x;
				if(reqd == 0)
					lo = hi = mid;
				else if(reqd < mnsub || reqd > mxsub)
					lo = mid + 1;
				else
					hi = mid;
			}
		}
		cout << lo << endl;
	}
	return 0;
}