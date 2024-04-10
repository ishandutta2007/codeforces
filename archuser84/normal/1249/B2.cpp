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
		int n;
		int p[200000];
		int ans[200000];
		int Ans[200000];
		cin >> n;
		for (LoopN)
		{
			cin >> p[i];
			--p[i];
			ans[i] = -1;
		}
		for (LoopN)
		{
			if (ans[i] != -1)
				cout << Ans[ans[i]] << ' ';
			else
			{
				int x = p[i];
				int a;
				for (a = 1; x != i; ++a)
				{
					ans[x] = i;
					x = p[x];
				}
				Ans[i] = a;
				cout << a << ' ';
			}
		}
		cout << '\n';
	}
}