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

int main()
{
	FAST;
	static char s[N];
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		int n;
		int z = 0, o = 0;
		for (n = 0; s[n] != '\0'; n++)
		{
			if (s[n] == '0')
				z++;
			else
				o++;
		}
		int ans = n + 1;
		int lz = 0, lo = 0;
		Loop(i, 0, n)
		{
			ans = min(ans, lz + o);
			ans = min(ans, lo + z);
			if (s[i] == '0')
			{
				lz++;
				z--;
			}
			else
			{
				lo++;
				o--;
			}
		}
		ans = min(ans, lz + o);
		ans = min(ans, lo + z);
		cout << ans << '\n';
	}
}