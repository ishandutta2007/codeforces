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

int a[2000], b[2000];

int main()
{
	int n, m, ans;
	cin >> n >> m;
	for (LoopN)
	{
		cin >> a[i];
	}
	for (LoopN)
	{
		cin >> b[i];
	}
	sort(b, b + n);
	sort(a, a + n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		x = b[i] - a[0];
		bool ansed = 1;
		if (x < 0)x += m;
		for (int j = 0; j < n; j++)
		{
			int y = b[(i + j) % n] - a[j];
			if (y < 0)y += m;
			if (y != x)
			{
				ansed = 0;
				break;
			}
		}
		if (ansed)
		{
			ans = x;
			break;
		}
	}
	while (ans < 0)ans += m;
	cout << ans << '\n';
}