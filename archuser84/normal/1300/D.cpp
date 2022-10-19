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

int n;
int x[100000];
int y[100000];
ll sumX = 0;
ll sumY = 0;

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> x[i] >> y[i];
		sumX += x[i];
		sumY += y[i];
	}
	if (n % 2)
	{
		cout << "NO\n";
		return 0;
	}
	sumX *= 2;
	sumY *= 2;
	if (sumX % n || sumY % n)
	{
		cout << "NO\n";
		return 0;
	}
	sumX /= n;
	sumY /= n;
	bool ans = 1;
	n /= 2;
	Loop(i, 0, n)
	{
		if (sumX - x[i] != x[i + n])
		{
			ans = 0;
			break;
		}
		if (sumY - y[i] != y[i + n])
		{
			ans = 0;
			break;
		}
	}
	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
}