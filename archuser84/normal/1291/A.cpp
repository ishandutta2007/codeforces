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
		int n;
		cin >> n;
		char s[5000];
		cin >> s;
		ll sum = 0;
		bool del[5000];
		int fo = -1;
		int lo = -1;
		Loop(i, 0, n)
		{
			int x = s[i] - '0';
			if (x % 2 == 1)
			{
				if (fo == -1)
					fo = i;
				lo = i;
			}
			sum += x;
		}
		int l = s[n - 1] - '0';
		if (lo == -1)
			cout << "-1\n";
		else if (sum % 2 == 0)
		{
			Loop(i, 0, lo + 1)
			{
				cout << s[i];
			}
			cout << '\n';
		}
		else
		{
			if (lo == fo)
				cout << "-1\n";
			else
			{
				bool flag = false;
				Loop(i, 0, lo + 1)
				{
					if (i != fo)
					{
						if (s[i] != '0')
							flag = true;
						if (flag)
							cout << s[i];
					}
				}
				cout << '\n';
			}
		}
	}
}