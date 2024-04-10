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
		int n,k;
		cin >> n >> k;
		if (n & 1 && !(k & 1))
		{
			cout << "NO\n";
			continue;
		}
		if (k & 1 && !(n & 1))
		{
			if (n < (k << 1))
			{
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			Loop(i, 0, k - 1)
				cout << "2 ";
			cout << n - ((k - 1) << 1) << '\n';
		}
		else
		{
			if (n < k)
			{
				cout << "NO\n";
				continue;
			}
			cout << "YES\n";
			Loop(i, 0, k - 1)
				cout << "1 ";
			cout << n - (k - 1) << '\n';
		}
	}
}