#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

const int N = 300000;

int main()
{
	ll n;
	ll m = 1;
	cin >> n;
	int cnt = 0;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			m = i;
			cnt++;
			do
			{
				n /= i;
			} while (n % i == 0);
		}
	}
	if (n > 1)
	{
		m = n;
		cnt++;
	}
	if (cnt <= 1)
		cout << m;
	else if (cnt >= 2)
		cout << 1;
}