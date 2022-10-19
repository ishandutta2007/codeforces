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
	int t;
	cin >> t;
	for (Loop)
	{
		char s[1000000];
		int size;
		int x;
		int l = 0;
		cin >> x >> s;
		size = strlen(s);
		ll ans = size;
		while (l != x)
		{
			if (s[l] < '1' || s[l]>'3')
				cout << "ERROR: l=" << l << " s[l]=" << (int)s[l] << '\n';
			ans += (ans - l - 1) * ((ll)s[l] - '0' - 1);
			while(ans < 0)
				ans += Mod1;
			ans %= Mod1;
			if (size < x)
			{
				int h = (size - l - 1) * (s[l] - '0' - 1) + size;
				for (int i = size; i < h && i < x; ++i)
				{
					s[i] = s[(i - l - 1) % (size - l - 1) + (l + 1)];
				}
				size = h;
			}
			++l;
		}
		cout << ans << '\n';
	}
}