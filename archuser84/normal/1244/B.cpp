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

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int n;
		cin >> n;
		char s[2000];
		cin >> s;
		int l = -1, r = n;
		for (LoopN)
		{
			if (s[i] == '1')
			{
				if (l == -1)
					l = i;
				r = i;
			}
		}
		if (l != -1)
			cout << 2*max(r + 1, n - l) << '\n';
		else
			cout << n << '\n';
	}
}