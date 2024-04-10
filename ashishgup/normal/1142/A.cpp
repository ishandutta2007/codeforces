#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	int mn = n * k;
	int mx = 1;
	for(int i = 1; i <= n; i++)
	{
		int p1 = i * k + 1 + b;
		int p2 = i * k + 1 - b;
		if(p1 > n * k)
			p1 -= n * k;
		if(p2 < 1)
			p2 += n * k;
		int d1 = 1 + a - p1;
		int d2 = 1 + a - p2;
		if(d1 < 0)
			d1 += n * k;
		if(d2 < 0)
			d2 += n * k;
		mn = min(mn, n * k / __gcd(d1, n * k));
		mn = min(mn, n * k / __gcd(d2, n * k));
		mx = max(mx, n * k / __gcd(d1, n * k));
		mx = max(mx, n * k / __gcd(d2, n * k));
	}
	cout << mn << " " << mx;
	return 0;
}