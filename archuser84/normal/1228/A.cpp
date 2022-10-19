#define _CRT_SECURE_NO_WARNINGS
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

bool dif(int x)
{
	bool d[10] = {};
	while (x > 0)
	{
		if (d[x % 10])
			return false;
		d[x % 10] = true;
		x /= 10;
	}
	return true;
}

int main()
{
	int l, r;
	cin >> l >> r;
	Loop(i, l, r + 1)
	{
		if (dif(i))
		{
			cout << i;
			return 0;
		}
	}
	cout << "-1\n";
}