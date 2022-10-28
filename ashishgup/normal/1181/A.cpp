//Forgot to register

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int x, y, z;
	cin >> x >> y >> z;
	int mx = (x + y) / z;
	int rem1 = z - (x % z);
	rem1 %= z;
	int rem2 = (z - (y % z));
	rem2 %= z;
	int have = x / z + y / z;
	int reqd = 0;
	if(have < mx)
		reqd += min(rem1, rem2);
	cout << mx << " " << reqd;
	return 0;
}