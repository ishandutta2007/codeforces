#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	int n, m, d;
	int a[10000];
	cin >> n >> m >> d;
	int ans = 0;
	for (LoopN)
	{
		for (LoopM)
		{
			cin >> a[i * m + j];
			if (a[i * m + j] % d != a[0] % d)
				ans = -1;
		}
	}
	if (ans != -1)
	{
		int arr[10000];
		int next = n * m;
		int mod = a[0] % d;
		for (int i = 0; i < n * m; ++i)
		{
			arr[i] = (a[i] - (mod - d)) / d;
		}
		while (next > 0)
		{
			for (int i = 0; i < n * m; ++i)
			{
				--arr[i];
				if (arr[i] == 0)
					next -= 2;
			}
		}
		for (int i = 0; i < n * m; ++i)
		{
			ans += arr[i] >= 0 ? arr[i] : -arr[i];
		}
	}
	cout << ans << '\n';
}