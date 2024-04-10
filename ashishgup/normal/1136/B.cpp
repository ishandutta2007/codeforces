#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, k, ans = 0;

int get(int x, int y, int z)
{
	return abs(y - x) + abs(z - y);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	ans = 2 * n;
	ans += min(get(k, 1, n), get(k, n, 1));
	ans += 1;
	cout<<ans;
	return 0;
}