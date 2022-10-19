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
		int a[5];
		a[0] = n % 10; n /= 10;
		a[1] = n % 10; n /= 10;
		a[2] = n % 10; n /= 10;
		a[3] = n % 10; n /= 10;
		a[4] = n % 10; n /= 10;
		cout << (bool)a[0] + (bool)a[1] + (bool)a[2] + (bool)a[3] + (bool)a[4] << '\n';
		LoopR(i, 0, 5)
		{
			if (a[i])
			{
				cout << a[i];
				Loop(j, 0, i)
					cout << '0';
				cout << ' ';
			}
		}
		cout << '\n';
	}
}