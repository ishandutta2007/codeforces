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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

char s[200010];

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n >> s;
		int l = n, r = -1;
		Loop(i, 0, n)
		{
			if (s[i] == '1')
			{
				l = i;
				break;
			}
		}
		LoopR(i, 0, n)
		{
			if (s[i] == '0')
			{
				r = i;
				break;
			}
		}
		Loop(i, 0, l)
			cout << '0';
		if (l <= r)
			cout << '0';
		Loop(i, r + 1, n)
			cout << '1';
		cout << '\n';
	}
}