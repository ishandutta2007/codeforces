#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 500005;

int n, k, d;
int a[N];

int dp[N], p[N];

int byn(int i)
{
	if (i == n)
		cout << "";
	int l = 1, r = i;
	while ((r - l) > 4)
	{
		int m = (l + r) / 2;
		if (a[i] - a[m] <= d)
			r = m;
		else
			l = m;
	}
	for (int m = l; m <= r; ++m)
		if (a[i] - a[m] <= d)
			return m;
}

int main()
{
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	dp[0] = 1;
	p[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (i == n)
			cout << "";
		int l = byn(i);
		int r = i - k + 1;
		--l;
		--r;
		if (r >= l)
		{
			l = max(l, 0);
			if (l == 0)
				dp[i] = 1;
			else
				dp[i] = !!(p[r] - p[l - 1]);
		}
		p[i] = p[i - 1] + dp[i];
	}
	if (dp[n])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}