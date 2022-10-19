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

const int N = 50000;

int main()
{
	int t;
	cin >> t;
	char s[N];
	__int8 a[N], b[N];
	while (t--)
	{
		int n;
		cin >> n;
		cin >> s;
		bool f = 0;
		Loop(i, 0, n)
		{
			switch (s[i])
			{
			case '0': a[i] = 0; b[i] = 0; break;
			case '1': if (!f) { a[i] = 0; b[i] = 1; f = 1; }
					else { a[i] = 1; b[i] = 0; } break;
			case '2': if (!f) { a[i] = 1; b[i] = 1; }
					else { a[i] = 2; b[i] = 0; } break;
			}
		}
		Loop(i, 0, n)
			cout << (int)a[i];
		cout << '\n';
		Loop(i, 0, n)
			cout << (int)b[i];
		cout << '\n';
	}
}