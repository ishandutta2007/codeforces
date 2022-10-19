#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
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
		int a[200000];
		Loop(i, 0, 2 * n)
			cin >> a[i];
		sort(a, a + 2*n);
		int min = 1e+9;
		Loop(i, 0, n)
		{
			int x = abs(a[i] - a[n]);
			if (x < min)
				min = x;
		}
		Loop(i, n, 2 * n)
		{
			int x = abs(a[i] - a[n - 1]);
			if (x < min)
				min = x;
		}
		cout << min << '\n';
	}
}