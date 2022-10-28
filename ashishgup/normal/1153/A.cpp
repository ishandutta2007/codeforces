#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, t, mx = 1e9, idx = 1;
int s[N], d[N];

int32_t main()
{
	IOS;
	cin >> n >> t;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i] >> d[i];
		if(s[i] >= t)
		{
			if(s[i] - t < mx)
				mx = s[i] - t, idx = i;
		}
		else
		{
			int x = t - s[i];
			x /= d[i];
			int cur = s[i] + x * d[i];
			if(cur < t)
				cur += d[i];
			if(cur - t < mx)
				mx = cur - t, idx = i;
		}
	}
	cout << idx;
	return 0;
}