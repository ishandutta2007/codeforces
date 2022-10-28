//Started 2 mins late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

int solve(int cur, int period)
{
	int nxt = cur / period;
	int val = period * nxt;
	if(val < cur)
		val += period;
	return val - cur;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int p, a, b, c;
		cin >> p >> a >> b >> c;
		int ans = min({solve(p, a), solve(p, b), solve(p, c)});
		cout << ans << endl;
	}
	return 0;
}