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
	int n;
	int d;
	int a[1000];
	int ans = 0;
	cin >> n >> d;
	Loop(i, 0, n)
		cin >> a[i];
	Loop(i, 0, n)
	{
		Loop(j, i + 1, n)
		{
			int x = a[j] - a[i];
			if (x < 0)
				x = -x;
			if (x <= d)
				ans++;
		}
	}
	cout << 2 * ans;
}