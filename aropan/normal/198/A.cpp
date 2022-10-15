#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long k, b, n, t;
long long ll, rr, cc;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	cin >> k >> b >> n >> t;
	
	ll = 0;
	rr = n;
	while (ll < rr)
	{
		cc = (ll + rr) / 2;
		long long res = 0;
		long long K = 1;
		for (int i = cc; i < n && res <= t; i++)
		{
			res += b * K;
			K *= k;
		}
		if (res <= t && res + K <= t)
			rr = cc;
		else
			ll = cc + 1;
	}
	cout << ll << endl;
	return 0;
}