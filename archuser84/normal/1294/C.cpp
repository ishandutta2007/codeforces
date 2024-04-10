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

struct co
{
	int x, y;
};

bool co_sort(co a, co b)
{
	return a.x + a.y < b.x + b.y;
}

int main()
{
	int t;
	cin >> t;
	Loop(loop, 0, t)
	{
		int n;
		cin >> n;
		int p = 0;
		int ans[3]; ans[2] = -1;
		int sq = sqrt(n);
		Loop(i, 2, sq + 1)
		{
			if(n%i==0)
			{
				ans[p] = i;
				p++;
				n /= i;
				if (p == 2)
				{
					ans[2]=n;
					break;
				}
			}
		}
		if (ans[2] == -1 || ans[2] == ans[0] || ans[2] == ans[1])
			cout << "NO\n";
		else
			printf("YES\n%i %i %i\n", ans[0], ans[1], ans[2]);
	}
}