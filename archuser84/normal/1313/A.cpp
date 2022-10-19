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

const int N = 200000;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans = 0;
		if (a)
		{
			ans++;
			a--;
		}
		if (b)
		{
			ans++;
			b--;
		}
		if (c)
		{
			ans++;
			c--;
		}
		if (a < b)
			swap(a, b);
		if (b < c)
			swap(b, c);
		if (a < b)
			swap(a, b);
		if (a && b)
		{
			ans++;
			a--;
			b--;
		}
		if (a && c)
		{
			ans++;
			a--;
			c--;
		}
		if (b && c)
		{
			ans++;
			b--;
			c--;
		}
		if (a && b && c)
			ans++;
		cout << ans << '\n';
	}
}