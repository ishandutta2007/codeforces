#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

double ans = 1e10;

void check(int x, int y)
{
	if(x < 0)
		return;
	double k = 1. * x / 2;
	int l = 1, r = 2e9 + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if(k / m >= y)
			l = m;
		else
			r = m;
	}
	if(k / l >= y)
		ans = min(ans, k / l);
	
}

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if(b > 0)
    {
		check(a + b, b);
		check(a - b, b);
		if(ans == 1e10)
			cout << fixed << setprecision(12) << -1 << "\n";
		else
			cout << fixed << setprecision(12) << ans << "\n";
	}
    return 0;
}