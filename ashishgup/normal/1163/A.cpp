#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	int n, m;
	cin >> n >> m;
	if(m <= 1)
		cout << 1;
	else if(n == m)
		cout << 0;
	else
	{
		int ans = min(m, n - m);
		cout << ans;
	}
	return 0;
}