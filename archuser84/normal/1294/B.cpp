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
		bool ans = true;
		bool ex[2001] = { 0 };
		int n;
		cin >> n;
		co pack[1000];
		Loop(i, 0, n)
		{
			cin >> pack[i].x >> pack[i].y;
			if (ex[pack[i].x + pack[i].y])
				ans = false;
			ex[pack[i].x + pack[i].y] = true;
		}
		if (!ans)
			cout << "NO\n";
		else
		{
			sort(pack, pack + n, co_sort);
			Loop(x, 1, n)
				if (pack[x].x < pack[x - 1].x)
				{
					cout << "NO";
					goto end;
				}
			Loop(y, 1, n)
				if (pack[y].y < pack[y - 1].y)
				{
					cout << "NO";
					goto end;
				}
			cout << "YES\n";
			Loop(x, 0, pack[0].x)
				cout << 'R';
			Loop(y, 0, pack[0].y)
				cout << 'U';
			Loop(i, 1, n)
			{
				Loop(x, 0, pack[i].x - pack[i - 1].x)
					cout << 'R';
				Loop(y, 0, pack[i].y - pack[i - 1].y)
					cout << 'U';
			}
			end:
			cout << '\n';
		}
	}
}