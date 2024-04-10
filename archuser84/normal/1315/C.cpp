#include <iostream>
#include <string.h>
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

const int N = 100;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		bool ans = true;
		int a[2 * N] = {};
		bool ex[2 * N + 1] = {};
		int n;
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> a[2 * i];
			if (a[2 * i] > 2 * n || ex[a[2 * i]])
				ans = false;
			else
				ex[a[2 * i]] = true;
		}
		if (!ans)
		{
			cout << "-1\n";
			continue;
		}
		Loop(i, 1, 2 * n + 1)
		{
			if (ex[i])
				continue;
			bool flag = false;
			Loop(j, 0, n)
			{
				if (a[2 * j] < i && !a[2 * j + 1])
				{
					a[2 * j + 1] = i;
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				ans = false;
				break;
			}
		}
		if (!ans)
			cout << "-1\n";
		else
		{
			Loop(i, 0, 2 * n)
			{
				cout << a[i] << ' ';
			}
			cout << '\n';
		}
	}
}