#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
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
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, d;
		int a[1000];
		cin >> n >> d;
		Loop(i, 0, n)
			cin >> a[i];
		Loop(i, 1, n)
		{
			int x = min(a[i], d / i);
			a[0] += x;
			d -= x * i;
			if (!d)
				break;
		}
		cout << a[0] << '\n';
	}
}