#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n, p, a[100000], b[100000];

inline bool can(ld t)
{
	ld tot = 0;
	for(int i = 0; i < n; i++) tot += max((ld)0, (t * a[i] - b[i]) / p);
	return tot <= t;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> p;
	ld s = 0;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i], s += a[i];
	if(s <= p) return cout << -1, 0;
	ld bl = 0, br = 1e16;
	for(int i = 0; i < 200; i++)
	{
		ld bm = (bl + br) / 2;
		if(can(bm)) bl = bm;
		else br = bm;
	}
	cout << fixed << setprecision(10) << bl;
}