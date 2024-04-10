#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 100010;
const int smax = 448;
int a[N];
int n;
__int8 tmp[N];
ll ans = 1;

ll pow(ll a, int b)
{
	return b == 0 ? 1 : pow(a, b - 1) * a;
}

bool isPrime(int x)
{
	if ((x & 1) == 0)
		return x == 2;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0)
			return 0;
	}
	return 1;
}

int Do(int x)
{
	memset(tmp, 0, n);
	bool flg = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % x)
		{
			if (flg)
				return 1;
			flg = true;
		}
	}
	for (int i = 0;; i++)
	{
		if (i == n)
			i = 0;
		if (a[i] % x == 0)
		{
			a[i] /= x;
			tmp[i]++;
			if (a[i] % x)
			{
				if (flg)
					return pow(x,tmp[i]);
				flg = 1;
			}
		}
	}
}

void Remove(int i)
{
	for (int x = 2; x <= smax; x++)
		while (a[i] % x == 0)
			a[i] /= x;
}

void Solve()
{
	for (int x = 2; x <= smax; x++)
	{
		if (isPrime(x))
			ans *= Do(x);
	}
	if (n == 2)
	{
		if (a[0] == a[1])
			ans *= a[0];
		else
			ans *= (ll)a[0] * a[1];
		return;
	}
	int cnt = 0;
	Loop(i, 0, n)
	{
		Remove(i);
		cnt += a[i] == a[0];
	}
	if (cnt >= n - 1)
		ans *= a[0];
	else
	{
		cnt = 0;
		Loop(i, 0, n)
			cnt += a[i] == a[1];
		if (cnt >= n - 1)
			ans *= a[1];
	}
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	Solve();
	cout << ans;
}