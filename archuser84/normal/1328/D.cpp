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

const int N = 200000;

int main()
{
	FAST;
	int t;
	cin >> t;
	pair<int, int> fig[N];
	int figg[N];
	int C[N];
	while (t--)
	{
		int n;
		cin >> n;
		int k = -1;
		int p = -1;
		bool canre = 0;
		Loop(i, 0, n)
		{
			int t;
			cin >> t;
			figg[i] = t;
			if (t != k)
			{
				k = t;
				p++;
				fig[p].first = t;
				fig[p].second = 0;
			}
			fig[p].second++;
			if (fig[p].second > 1)
				canre = 1;
		}
		p++;
		if (p == 1)
		{
			cout << "1\n";
			Loop(i, 0, n)
				cout << "1 ";
			cout << '\n';
		}
		else
		{
			if (n % 2 == 0 || (n%2 == 1 && figg[0]==figg[n-1]))
			{
				cout << "2\n";
				Loop(i, 0, n)
					cout << 1 + i % 2 << ' ';
				cout << '\n';
			}
			else if (canre)
			{
				cout << "2\n";
				bool c = 0;
				Loop(i, 0, n - 1)
				{
					cout << 1 + (c != i % 2) << ' ';
					if (figg[i + 1] == figg[i])
						c = 1;
				}
				cout << 1 + (c != (n - 1) % 2) << '\n';
			}
			else
			{
				cout << "3\n";
				Loop(i, 0, n - 1)
					cout << 1 + i % 2 << ' ';
				cout << 3 << '\n';
			}
		}
	}
}