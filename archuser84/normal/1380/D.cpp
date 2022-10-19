#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 200010;
int a[N], b[N];
int n, m, k;
ll x, y;
ll ans = 0;

bool destroy(int l, int r, bool bigdes)
{
	if (r < l)
		return 1;
	int lngth = r - l + 1;
	if (k * y <= x)
	{
		if (bigdes)
			ans += y * lngth;
		else if (lngth < k)
			return 0;
		else
			ans += x + y * (lngth - k);
	}
	else
	{
		if (lngth >= k)
			ans += y * (lngth % k) + x * (lngth / k);
		else if (!bigdes)
			return 0;
		else
			ans += y * lngth;
	}
	return 1;
}

int main()
{
	FAST;
	cin >> n >> m;
	cin >> x >> k >> y;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, m)
		cin >> b[i];
	int l = -1, r = 0, p = 0;
	int big = 0, maax = 0;
	while (r < n)
	{
		if (a[r] == b[p])
		{
			if (!destroy(l + 1, r - 1, max(a[r], big) > maax))
				Kill(-1);
			l = r;
			big = a[r];
			p++;
			maax = 0;
		}
		else
			maax = max(maax, a[r]);
		r++;
	}
	if (!destroy(l + 1, r - 1, big > maax))
		Kill(-1);
	if (p < m)
		Kill(-1);
	cout << ans;
}