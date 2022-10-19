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

const int N = 1000010;
int a[N];
int n, k;
int b[N] = {};

int Getnew1(int x)
{
	int ans = 1;
	for (int i = 2; i * i <= x; i++)
	{
		int m = 0;
		while (x % i == 0)
		{
			x /= i;
			m++;
		}
		m %= k;
		while (m > 0)
		{
			ans *= i;
			m--;
		}
	}
	return ans * x;
}
int Getnew2(int x)
{
	ll ans = 1;
	for (int i = 2; i * i <= x; i++)
	{
		int m = 0;
		while (x % i == 0)
		{
			x /= i;
			m++;
		}
		m = (k - m) % k;
		while (m > 0)
		{
			ans *= i;
			if (ans >= N)
				return -1;
			m--;
		}
	}
	if(x > 1)
		Loop(i, 1, k)
		{
			ans *= x;
			if (ans >= N)
				return -1;
		}
	return ans;
}

int main()
{
	FAST;
	cin >> n >> k;
	Loop(i, 0, n)
	{
		cin >> a[i];
		a[i] = Getnew1(a[i]);
		b[a[i]]++;
	}
	ll ans = 0;
	Loop(i, 0, n)
	{
		int x = Getnew2(a[i]);
		if (x == -1)
			continue;
		ans += b[x];
		ans -= x == a[i];
	}
	cout << ans / 2;
}