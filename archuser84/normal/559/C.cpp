#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

ll fac[200001];

void calcFac()
{
	fac[0] = 1;
	Loop(i, 1, 200001)
		fac[i] = (fac[i - 1] * i) % Mod1;
}

ll C(int n, int r)
{
	if (r < 0 || r > n)
		return 0;

	ll ans = fac[n];
	ans = modDivide(ans, (fac[r] * fac[n - r]) % Mod1, Mod1);

	return ans;
}

struct cell
{
	int r, c;
	ll v;
};

bool cellSort(cell a, cell b)
{
	return a.r + a.c < b.r + b.c;
}

int main()
{
	calcFac();

	int h, w, n;
	cin >> h >> w >> n;
	cell b[2000];
	Loop(i, 0, n)
		cin >> b[i].r >> b[i].c;
	sort(b, b + n, cellSort);

	Loop(i, 0, n)
	{
		b[i].v = C(b[i].r + b[i].c - 2, b[i].r - 1);
		Loop(j, 0, i)
		{
			b[i].v = (b[i].v - b[j].v * C(b[i].r - b[j].r + b[i].c - b[j].c, b[i].r - b[j].r)) % Mod1;
		}
		b[i].v = (b[i].v + Mod1) % Mod1;
	}

	ll ans = C(h + w - 2, h - 1);
	Loop(j, 0, n)
	{
		ans = (ans - b[j].v * C(h - b[j].r + w - b[j].c, h - b[j].r)) % Mod1;
	}
	ans = (ans + Mod1) % Mod1;

	cout << ans;
}