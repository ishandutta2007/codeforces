#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 400005;

int n;
LL m, a[N], s[N], w[N];

LL get_sum(LL l, LL r)
{
	return (r - l + 1) * (r + l) / 2;
}

int main()
{
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i + n] = a[i];
	for (int i = 1; i <= n * 2; i++) s[i] = s[i - 1] + a[i], w[i] = w[i - 1] + get_sum(1, a[i]);
	int r = 1, p = 0, l = 1;
	while (s[r] < m) r++;
	LL ans = w[r - 1] + get_sum(1, a[r] - s[r] + m);
	while (l <= n)
	{
		if (l == r)
		{
			ans = max(ans, get_sum(a[l] - m + 1, a[l]));
			r++;
			p = 1;
		}
		else if (!p)
		{
			int tmp = s[r] - s[l - 1] - m;
			if (tmp <= a[l])
			{
				ans = max(ans, w[r] - w[l - 1] - get_sum(1, tmp));
				p = 1;
				r++;
				if (tmp == a[l]) l++;
			}
			else
			{
				l++;
				ans = max(ans, w[r] - w[l - 1] - get_sum(m - (s[r - 1] - s[l - 1]) + 1, a[r]));
			}
		}
		else
		{
			int tmp = s[r - 1] - s[l - 1] - m;
			if (a[l] - tmp == a[r]) l++, r++; 
			else if (a[l] - tmp > a[r]) r++;
			else
			{
				l++;
				p = 0;
				ans = max(ans, w[r] - w[l - 1] - get_sum(m - (s[r - 1] - s[l - 1]) + 1, a[r]));
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}