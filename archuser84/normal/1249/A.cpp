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
		int a[100];
		cin >> n;
		for (LoopN)
			cin >> a[i];
		sort(a, a + n);
		int max = 1;
		for (int i = 1; i < n; ++i)
		{
			if (a[i] - a[i - 1] == 1)
			{
				max = 2;
				break;
			}
		}
		cout << max << '\n';
	}
}