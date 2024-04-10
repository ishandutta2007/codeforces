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

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	int b[200002],e[200002];
	int size = 0;
	for (LoopN)
	{
		int m;
		cin >> m;
		int x[200002];
		for (LoopM)
		{
			cin >> x[j];
		}
		if (is_sorted(x, x + m, comp))
		{
			b[size] = x[0];
			e[size] = x[m - 1];
			++size;
		}
	}
	sort(b, b + size);
	sort(e, e + size);
	ll ans = (ll)n * (ll)n;
	int p = 0;
	for (int i=0;i<size;++i)
	{
		while (e[p] < b[i])
			++p;
		if (p >= size)
			break;
		ans -= (ll)size - (ll)p;
	}
	cout << ans << '\n';
}