#include <bits/stdc++.h>
using namespace std;
int am[100010], n, m, q;
char a[100010], b[1000010];
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	scanf(" %s", a);
	scanf(" %s", b);
	for (int i = 0; i < n; i++)
	{
		bool works = 1;
		for (int j = 0; j < m; j++)
		{
			if (a[i+j] != b[j]) { works = 0; break; }
		}
		if (works)
		{
			am[i]++;
		}
		if (i) am[i] += am[i-1];
	//	printf("%d ", am[i]);
	}
	//printf("\n");
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r-=m;
		int ans = 0;
		if (l <= r)
		{
			ans = am[r];
			if (l) ans -= am[l-1];
		}
		printf("%d\n", ans);
	}
}