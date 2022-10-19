#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod2 998244353
using namespace std;

const __int64 p10[12] = { 1,10,100,1000,10000,
	100000,1000000,10000000,100000000,1000000000,
	10000000000,100000000000 };
int cunt[10] = { 0 };

int main()
{
	int n;
	cin >> n;
	__int64 ans=0;
	int a[100000];
	for (LoopN)
	{
		cin >> a[i];
		++cunt[(int)log10(a[i])];
	}
	for(LoopN)
	{
		__int64 x = a[i];
		__int64 y;
		__int64 ys = 0;
		for (int p = 0; p < 10; ++p)
		{
			y = x / p10[p+1];
			for (int j = p; j >= 0; --j)
			{
				y *= 10;
				y += (x / p10[j]) % 10;
				y *= 10;
				y %= Mod2;
			}
			ys = (ys + y * cunt[p]) % Mod2;
			y = x / p10[p+1];
			for (int j = p; j >= 0; --j)
			{
				y *= 100;
				y += (x / p10[j]) % 10;
				y %= Mod2;
			}
			ys = (ys + y * cunt[p]) % Mod2;
		}
		ans = (ans + ys) % Mod2;
	}
	cout << ans << '\n';
}