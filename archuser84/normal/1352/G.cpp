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

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (n <= 3)
		{
			cout << "-1\n";
			continue;
		}
		for (int i = 1+!(n&1); i <= n; i += 2)
			cout << i << ' ';
		cout << n - 3 << ' ' << n - 1 << ' ';
		for (int i = n - 5; i > 0; i -= 2)
			cout << i << ' ';
		cout << '\n';
	}
}