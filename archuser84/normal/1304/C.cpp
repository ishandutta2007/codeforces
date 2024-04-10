#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int q;
	cin >> q;
	ll t[1000];
	ll l[1000],r[1000];
	while (q--)
	{
		int n, m;
		cin >> n >> m;
		ll tl = m, tr = m;
		Loop(i, 0, n)
			cin >> t[i] >> l[i] >> r[i];
		LoopR(i, 1, n)
			t[i] -= t[i - 1];
		bool OK = 1;
		Loop(i, 0, n)
		{
			tl = max(l[i], tl - t[i]);
			tr = min(r[i], tr + t[i]);
			if (tl > tr)
			{
				OK = false;
				break;
			}
		}
		if (OK)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}