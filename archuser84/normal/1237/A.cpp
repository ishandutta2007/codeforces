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

int main()
{
	FAST;
	int t;
	cin >> t;
	bool o = 0;
	while (t--)
	{
		int x;
		cin >> x;
		if (x & 1)
		{
			cout << o + x / 2 - (x < 0) << '\n';
			o = !o;
		}
		else
			cout << x / 2 << '\n';
	}
}