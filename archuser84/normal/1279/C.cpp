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

/*int find(int* a, int value, int size)
{
	for (int i = 0; i < size; ++i)
		if (a[i] == value)
			return i;
	return -1;
}*/

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int n, m;
		cin >> n >> m;
		int a[100000], b[100000];
		int p[100010];
		for (LoopN)
		{
			cin >> a[i];
			p[a[i]] = i;
		}
		for (LoopM)
		{
			cin >> b[j];
			b[j] = p[b[j]];
		}
		int max = 0;
		ll ans = 0;
		for (LoopM)
		{
			if (b[j] == -1)
				cout << "ERROR\n";
			if (b[j] <= max)
				ans += 1;
			else
			{
				ans += 2 * ((ll)(b[j] - j)) + 1;
				max = b[j];
			}
		}
		cout << ans << '\n';
	}
}