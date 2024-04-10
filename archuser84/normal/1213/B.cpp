#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n;
		int a[150000];
		int ans = 0;
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> a[i];
		}
		int min = a[n - 1];
		LoopR(i, 0, n - 1)
		{
			if (a[i] > min)
				ans++;
			else
				min = a[i];
		}
		cout << ans << '\n';
	}
}