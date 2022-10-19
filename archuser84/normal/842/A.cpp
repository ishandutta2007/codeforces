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
	int l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	int c = k;
	bool ans = false;
	while (c <= r)
	{
		if (l <= c && x <= c / k && c / k <= y)
		{
			ans = true;
			break;
		}
		c += k;
	}
	cout << YN(ans);
}