//#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
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

const int N = 1000010;
int n, p;
int a[N];

ll pow1(ll a, ll b)
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}ll my_pow(ll a, ll b)
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans = ans * a % Mod1;
		a = a * a % Mod1;
		b >>= 1;
	}
	return ans;
}
int my_log(int x, int base)
{
	int ans = 0;
	while (x > 0)
	{
		x /= base;
		ans++;
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		Loop(i, 0, n)
			cin >> a[i];
		if (p == 1)
		{
			cout << (n & 1) << '\n';
			continue;
		}
		sort(a, a + n);
		bool flag = 0;
		ll dif = 0;
		int last = a[n - 1];
		int zz = my_log(1000000, p);
		LoopR(i, 0, n)
		{
			if (dif != 0 && last - a[i] > zz)
				flag = true;
			if (flag)
			{
				dif *= my_pow(p, last - a[i]);
				dif--;
				dif %= Mod1;
			}
			else
			{
				dif *= pow1(p, last - a[i]);
				if (dif != 0)
					dif--;
				else
					dif++;
			}
			last = a[i];
			if (dif > 1000000)
			{
				flag = true;
				dif %= Mod1;
			}
		}
		dif *= my_pow(p, last);
		dif %= Mod1;
		while (dif < 0)
			dif += Mod1;
		cout << (long long)dif << '\n';
	}
}