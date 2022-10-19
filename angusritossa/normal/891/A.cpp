#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}
int n, a[2010];
int lef[2010];
int righ[2010];
int sub, ans;
int main()
{
	scanf("%d", &n);
	ans = 999999999;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == 1) sub++;
	}
	if (n == 1)
	{
		if (a[0] == 1) printf("%d\n", 0);
		else printf("-1\n");
		return 0;
	}
	if (sub)
	{
		printf("%d\n", n-sub);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		lef[i] = righ[i] = a[i];
		for (int j = i-1; j >= 0; j--)
		{
			lef[j] = gcd(a[j], lef[j+1]);
		}
		for (int j = i+1; j < n; j++)
		{
			righ[j] = gcd(a[j], righ[j-1]);
		}
		int mn = 999999999;
		int r = i;
		for (int l = 0; l <= i; l++)
		{
			while (gcd(a[i], gcd(a[r], a[l])) != 1 && r < n) {	r++; }
			if (r == n)
			{
				r--;
			}
			else
			{
				mn = min(mn, (i-l) + (r-i));
			}

		}
		ans = min(ans, mn + n-1);

	}
	if (ans > 99999999) printf("-1\n");
	else printf("%d\n", ans);
}