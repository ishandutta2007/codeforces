#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	int r, h;
	cin >> r >> h;
	int ans = h / r * 2;
	h %= r;
	if(h * 2 < r)
		ans++;
	else if(h * 2 < 1.732 * r)
		ans += 2;
	else
		ans += 3;
	cout << ans;
	return 0;
}