#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n, q, a[N], b[N];

bool check(int mid)
{
	int s0 = 0, s1 = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= mid) s0++;
		else s1++;
	for (int i = 1; i <= q; i++)
		if (b[i] > 0)
		{
			if (b[i] <= mid) s0++;
			else s1++;
		}
		else
		{
			if (-b[i] <= s0) s0--;
			else s1--;
		}
	return s0 > 0;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= q; i++) scanf("%d", &b[i]);
	int l = 1, r = n;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	if (r == n) r = -1;
	printf("%d\n", r + 1);
	return 0;
}