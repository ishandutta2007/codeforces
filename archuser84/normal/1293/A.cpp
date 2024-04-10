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
		int n,s,k;
		cin >> n >> s >> k; s--;
		int a[1000];
		Loop(i, 0, k)
		{
			cin >> a[i];
			a[i]--;
		}
		int A = n, B = n;
		Loop(i, s, n)
		{
			bool can = true;
			Loop(j, 0, k)
			{
				if (a[j] == i)
				{
					can = false;
					break;
				}
			}
			if (can)
			{
				A = i - s;
				break;
			}
		}
		LoopR(i, 0, s)
		{
			bool can = true;
			Loop(j, 0, k)
			{
				if (a[j] == i)
				{
					can = false;
					break;
				}
			}
			if (can)
			{
				B = s - i;
				break;
			}
		}
		if (A > B)
			A = B;
		cout << A << '\n';
	}
}