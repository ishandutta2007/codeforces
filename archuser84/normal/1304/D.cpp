#include <iostream>
#include <string>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

int main()
{
	FAST;
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		char s[300000];
		cin >> s;
		Loop(i, 0, n)
		{
			if (s[i] != '<')
				cout << n - i << ' ';
			else
			{
				int count = 1;
				for (int j = i + 1; j < n; j++)
				{
					if (s[j] != '<')
					{
						count = j - i;
						break;
					}
				}
				LoopR(j, i, i + count + 1)
					cout << n - j << ' ';
				i += count;
			}
		}
		cout << '\n';
		Loop(i, 0, n)
		{
			if (s[i] != '>')
				cout << i + 1 << ' ';
			else
			{
				int count = 1;
				for (int j = i + 1; j < n; j++)
				{
					if (s[j] != '>')
					{
						count = j - i;
						break;
					}
				}
				LoopR(j, i, i + count + 1)
					cout << j + 1 << ' ';
				i += count;
			}
		}
		cout << '\n';
	}
}