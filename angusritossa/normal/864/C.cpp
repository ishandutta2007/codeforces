#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, f, k, has;
int ans;
int main()
{
	scanf("%I64d%I64d%I64d%I64d", &a, &b, &f, &k);
	has = b;
	for (int i = 1; i < k; i++)
	{
		if (i % 2)
		{
		if (has < a+a-f)
		{
			if (has < f)
			{
				printf("-1");
				return 0;
			}
			has = b-(a-f);
			ans++;
		}
		else has-=a;
		}
		else
		{
		if (has < a+f)
		{
			if (has < a-f)
			{
				printf("-1");
				return 0;
			}
			has = b-f;
			ans++;
		}
		else has-=a;
		}
	}
	if (k % 2)
	{
	if (has < a)
	{
		if (has < f || b < a-f)
		{
			printf("-1");
			return 0;
		}
		ans++;
	}
	}
	else
	{
	if (has < a)
	{
		if (has < a-f)
		{
			printf("-1");
			return 0;
		}

		ans++;
	}
	}
	printf("%d\n", ans);
}