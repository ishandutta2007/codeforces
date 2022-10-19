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
	int q[1000001] = { 0 };
	bool ql[1000001] = { 0 };
	bool qr[1000001] = { 0 };
	int n;
	cin >> n;
	for (LoopN)
	{
		int a, b;
		cin >> a >> b;
		q[a] = b;
		ql[a] = 1;
		qr[b] = 1;
	}
	int a, b = q[0];
	for (int i = 1; i <= 1000000; ++i)
	{
		if (ql[i] && !qr[i])
		{
			a = i;
			break;
		}
	}
	cout << a << ' ';
	for (int i = 1; i < n; ++i)
	{
		cout << b << ' ';
		int h = a;
		a = b;
		b = q[h];
	}
	cout << '\n';
}