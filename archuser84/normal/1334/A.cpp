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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool ans = true;
		int n;
		cin >> n;
		int pc = 0, pp = 0;
		Loop(i, 0, n)
		{
			int c, p;
			cin >> c >> p;
			if (p > c || p < pp || c < pc || p - pp > c - pc)
				ans = false;
			pp = p;
			pc = c;
		}
		cout << YN(ans);
	}
}