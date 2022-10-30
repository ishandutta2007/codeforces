#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int a[100001], c[100001];
int b[100001];
inline int Work(int n)
{
	for(int i = 1; i <= n; i++)
		c[i] = a[i];
	int pos0 = 1, pos1 = 1;
	while(pos0 <= n && c[pos0] != 0)
		pos0++;
	while(pos1 <= n && c[pos1] != 1)
		pos1++;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(b[i] == 0)
		{
			ans += pos0 - i;
			swap(c[i], c[pos0++]);
			while(pos0 <= n && c[pos0] != 0)
				pos0++;
			while(pos1 <= n && c[pos1] != 1)
				pos1++;
		}
		else
		{
			ans += pos1 - i;
			swap(c[i], c[pos1++]);
			while(pos0 <= n && c[pos0] != 0)
				pos0++;
			while(pos1 <= n && c[pos1] != 1)
				pos1++;
		}
	}
	return ans;
}
signed main()
{
	int t;
	scanf("%lld", &t);
	while(t--)
	{
		int n;
		scanf("%lld", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			int x;
			scanf("%lld", &x);
			a[i] = x & 1;
			sum += a[i];
		}
		if(n & 1)
		{
			if(sum == n / 2)
			{
				for(int i = 1; i <= n; i++)
					b[i] = ((i - 1) & 1);
				printf("%lld\n", Work(n));
			}
			else if(sum == n / 2 + 1)
			{
				for(int i = 1; i <= n; i++)
					b[i] = (i & 1);
				printf("%lld\n", Work(n));
			}
			else
				printf("-1\n");
		}
		else
		{
			if(sum == n / 2)
			{
				int ans;
				for(int i = 1; i <= n; i++)
					b[i] = (i & 1);
				ans = Work(n);
				for(int i = 1; i <= n; i++)
					b[i] = !b[i];
				printf("%lld\n", min(ans, Work(n)));
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}