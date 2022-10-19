#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
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
		int n, k;
		cin >> n >> k;
		int a = n - 1, b;
		k--;
		for (int i = 1;; i++)
		{
			if (i > k)
			{
				a = n - i - 1;
				break;
			}
			k -= i;
		}
		for (int i = 1;; i++)
		{
			if (k == 0)
			{
				b = n - i;
				break;
			}
			k--;
		}
		Loop(i, 0, a)
			cout << 'a';
		cout << 'b';
		Loop(i, a + 1, b)
			cout << 'a';
		cout << 'b';
		Loop(i, b + 1, n)
			cout << 'a';
		cout << '\n';
	}
}