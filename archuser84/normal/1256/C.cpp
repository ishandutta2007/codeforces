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

int my_min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int n, m, d;
	int c[1000];
	int x[1000];
	int csum=0;
	cin >> n >> m >> d;
	for (LoopM)
	{
		cin >> c[j];
		csum += c[j];
	}
	int l = n - csum;
	x[0] = my_min(d - 1,l);
	l -= x[0];
	for (int j=1;j<m;++j)
	{
		int mi = my_min(d - 1, l);
		x[j] = x[j - 1] + c[j - 1] + mi;
		l -= mi;
	}
	if (l > d-1)
		cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (int i = 0; i < x[0]; ++i)
			cout << "0 ";
		for (int i = 0; i < c[0]; ++i)
			cout << 1 << ' ';
		for (int j = 1; j < m; ++j)
		{
			for (int i = 0; i < x[j] - x[j-1] - c[j - 1]; ++i)
				cout << "0 ";
			for (int i = 0; i < c[j]; ++i)
				cout << j + 1 << ' ';
		}
		for (int i = 0; i < l; ++i)
			cout << "0 ";
		cout << '\n';
	}
}