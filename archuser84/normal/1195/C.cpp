#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
#define ll long long
using namespace std;

__int64 my_max(__int64 a, __int64 b)
{
	return a > b ? a : b;
}

int main()
{
	int h1[100000] = { 0 };
	int h2[100000] = { 0 };
	int n;
	cin >> n;
	for (LoopN)
	{
		cin >> h1[i];
	}
	for (LoopN)
	{
		cin >> h2[i];
	}
	__int64 ans[100010][2];
	ans[0][0] = h1[0];
	ans[0][1] = h2[0];
	ans[1][0] = my_max(h1[0], h2[0] + h1[1]);
	ans[1][1] = my_max(h2[0], h1[0] + h2[1]);
	for (int i = 2; i < n; ++i)
	{
		ans[i][0] = my_max(ans[i - 1][1] + h1[i], ans[i - 1][0]);
		ans[i][1] = my_max(ans[i - 1][0] + h2[i], ans[i - 1][1]);
	}
	cout << my_max(ans[n-1][0],ans[n-1][1]) << '\n';
}