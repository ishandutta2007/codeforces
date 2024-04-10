#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, m, q;
	cin >> n >> m >> q;
	while(q--)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		int g = __gcd(n, m);
		int inner = n / g;
		int outer = m / g;
		int loc1, loc2;
		if(sx == 1)
			loc1 = (sy - 1) / inner;
		if(sx == 2)
			loc1 = (sy - 1) / outer;
		if(ex == 1)
			loc2 = (ey - 1) / inner;
		if(ex == 2)
			loc2 = (ey - 1) / outer;
		if(loc1 == loc2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}