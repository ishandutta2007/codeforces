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

const int N = 300000;
ll h[N], e[N];

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll hsum = 0;
		Loop(i, 0, n)
		{
			cin >> h[i] >> e[i];
			hsum += h[i];
		}
		ll esum = 0;
		ll mine = 1000000000000000LL;
		Loop(i, 0, n - 1)
		{
			e[i] = min(e[i], h[i + 1]);
			mine = min(mine, e[i]);
			esum += e[i];
		}
		e[n - 1] = min(e[n - 1], h[0]);
		mine = min(mine, e[n - 1]);
		esum += e[n - 1];
		cout << hsum - esum + mine << '\n';
	}
}