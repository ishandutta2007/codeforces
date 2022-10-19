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
		cin >> n;
		int v[100];
		for (LoopN)
		{
			cin >> v[i];
		}
		int a = 0;
		while (a < n - 1)
		{
			int min = a;
			for (int i = a; i < n; ++i)
			{
				if (v[i] < v[min])
					min = i;
			}
			int h = v[min];
			for (int i = min; i > a; --i)
			{
				v[i] = v[i - 1];
			}
			v[a] = h;
			if (min == a)
				++a;
			else
				a = min;
		}
		for (LoopN)
		{
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
}