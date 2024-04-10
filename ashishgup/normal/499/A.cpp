#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, x;
int l[N], r[N];
 
int32_t main()
{
	IOS;
	cin >> n >> x;
	for(int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	int t = 1, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int mn = (l[i] - t) / x;
		t += mn * x;
		ans += (r[i] - t + 1);
		t = r[i] + 1;
	}
	cout << ans;
	return 0;
}