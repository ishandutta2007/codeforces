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
		int a[300000];
		int n;
		cin >> n;
		Loop(i, 0, n)
			cin >> a[i];
		bool ans = true;

		int p = n;
		Loop(i, 1, n)
		{
			if (a[i] < i)
			{
				p = i - 1;
				break;
			}
		}
		int min = a[p];
		Loop(i, p + 1, n)
		{
			if (a[i] < min - 1)
				min = a[i];
			else
				min--;
			if (min < 0)
			{
				ans = false;
				goto end;
			}
		}

		end:
		cout << (ans ? "Yes\n" : "No\n");
	}
}