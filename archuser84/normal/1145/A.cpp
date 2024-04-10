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
	int n;
	int a[16];
	int ans = 1;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	LoopR(i, 1, 5)
	{
		if (1 << i <= n)
		{
			Loop(j, 0, n / (1 << i))
			{
				if (is_sorted(a + j * (1 << i), a + (j + 1) * (1 << i)))
				{
					ans = 1 << i;
					goto end;
				}
			}
		}
	}
end:
	cout << ans;
}