#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100000;
ll a[N], b[N], c[N];
int p1 = 0, p2 = 0, p3 = 0;

ll dif()
{
	return (a[p1] - b[p2]) * (a[p1] - b[p2]) + (a[p1] - c[p3]) * (a[p1] - c[p3]) + (c[p3] - b[p2]) * (c[p3] - b[p2]);
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		p1 = 0; p2 = 0; p3 = 0;
		int r, g, bl;
		cin >> r >> g >> bl;
		Loop(i, 0, r)
			cin >> a[i];
		sort(a, a + r);
		Loop(i, 0, g)
			cin >> b[i];
		sort(b, b + g);
		Loop(i, 0, bl)
			cin >> c[i];
		sort(c, c + bl);
		ll ans = dif();
		while (p1 + p2 + p3 < r + g + bl - 3)
		{
			ll md = 1LL << 61;
			int m = 0;
			if (p1 < r - 1)
			{
				p1++;
				ll h = dif();
				if (h < md)
				{
					md = h;
					m = 1;
				}
				p1--;
			}
			if (p2 < g - 1)
			{
				p2++;
				ll h = dif();
				if (h < md)
				{
					md = h;
					m = 2;
				}
				p2--;
			}
			if (p3 < bl - 1)
			{
				p3++;
				ll h = dif();
				if (h < md)
				{
					md = h;
					m = 3;
				}
				p3--;
			}
			switch (m)
			{
			case 1:p1++; break;
			case 2:p2++; break;
			case 3:p3++; break;
			}
			ans = min(ans, md);
		}
		ans = min(ans, dif());
		cout << ans << '\n';
	}
}