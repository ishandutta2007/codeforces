//By Don4ick
//#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;

#define forn(i, n) for (int i = 1; i <= n; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define y1 qwer1234

const double PI = acos(-1.0);
const int DIR = 4;
const int X[] = {1, 0, -1, 0};
const int Y[] = {0, 1, 0, -1};

const int N = (int)3e5 + 228;
const int MOD = (int)1e9 + 7;

using namespace std;

ll f[N], rf[N];

ll binpow(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if (b & 1)
			res = res * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}
	return res;
}

ll C(int x, int y)
{
	if (y < 0){
		return (x < 0);
	}
	return f[x] * rf[y] % MOD * rf[x - y] % MOD;
}

ll func(int len, int bit, int c00, int c01, int c10, int c11)
{
	if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0)
		return 0ll;
	if (c00 + c01 + c10 + c11 + 1 != len)
		return 0ll;
	int cnt = c01 + c10 + 1;	
	int x, y;
	if (bit)
	{
		x = (cnt + 1) / 2;
		y = cnt - x;
		if (c10 != y || c01 != x - 1)
			return 0;
	}
	else
	{
		y = (cnt + 1) / 2;
		x = cnt - y;
		if (c01 != x || c10 != y - 1)
			return 0;
	}
	return C(c11 + x - 1, x - 1) * C(c00 + y - 1, y - 1) % MOD;
}

ll calc(string s, int c00, int c01, int c10, int c11)
{
	ll res = 0;
	if (c00 + c01 + c10 + c11 == 0)
		res+= bool((int)s.size() > 1);
	for (int i = 2; i < (int)s.size(); i++)
		res = (res + func(i, 1, c00, c01, c10, c11)) % MOD;
	string t;
	t += '1';
	for (int i = 1; i < (int)s.size(); i++)
	{
		if (s[i] == '1')
		{
			t += '0';
			if ((int)t.size() > 1)
			{
				c00 -= bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '0');
				c01 -= bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '1');
				c10 -= bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '0');
				c11 -= bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '1');
			}
			res = (res + func((int)s.size() - i, 0, c00, c01, c10, c11)) % MOD;
			if ((int)t.size() > 1)
			{
				c00 += bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '0');
				c01 += bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '1');
				c10 += bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '0');
				c11 += bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '1');
			}
			t.pop_back();
		}
		t += s[i];
		if ((int)t.size() > 1)
		{
			c00 -= bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '0');
			c01 -= bool(t[(int)t.size() - 2] == '0' && t[(int)t.size() - 1] == '1');
			c10 -= bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '0');
			c11 -= bool(t[(int)t.size() - 2] == '1' && t[(int)t.size() - 1] == '1');
		}	
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);

	//~precalc_f
	f[0] = rf[0] = 1;
	for (int i = 1; i < N; i++)
	{
		f[i] = f[i - 1] * i % MOD;
		rf[i] = binpow(f[i], MOD - 2);
	}
	//~read
	string a, b;
	int c00, c01, c10, c11;
	cin >> a >> b >> c00 >> c01 >> c10 >> c11;
	//~solve
	ll ans = (calc(b, c00, c01, c10, c11) - calc(a, c00, c01, c10, c11) + MOD) % MOD;
	for (int i = 1; i < (int)b.size(); i++)
	{
		c00 -= bool(b[i - 1] == '0' && b[i] == '0');
		c01 -= bool(b[i - 1] == '0' && b[i] == '1');
		c10 -= bool(b[i - 1] == '1' && b[i] == '0');
		c11 -= bool(b[i - 1] == '1' && b[i] == '1');
	}
	if (!c00 && !c01 && !c10 && !c11)
		ans = (ans + 1) % MOD;
	cout << ans << endl;
	
	return 0;
}