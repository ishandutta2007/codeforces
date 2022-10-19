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

int p[500000];
int c[500000];

int min(int a, int b)
{
	return a < b ? a : b;
}

int Get(int x)
{
	if (p[x] == x)
		return x;
	return Get(p[x]);
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (LoopN)
	{
		p[i] = i;
		c[i] = 1;
	}
	for (LoopM)
	{
		int k;
		cin >> k;
		if (k > 0)
		{
			int l;
			cin >> l; --l;
			for (int i = 1; i < k; ++i)
			{
				int x;
				cin >> x; --x;
				int a = Get(x), b = Get(l);
				if (a != b)
				{
					if (a > b)
					{
						int h = a;
						a = b;
						b = h;
					}
					c[a] += c[b];
					p[b] = p[a];
				}
				l = x;
			}
		}
	}
	for (LoopN)
	{
		cout << c[Get(i)] << ' ';
	}
	cout << '\n';
}