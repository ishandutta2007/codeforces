#include <bits/stdc++.h>
using namespace std;
int ans[100010];
int ans7[8] = {0, 3, 6, 1, 5, 4, 7, 2};
inline void Connect(int x, int y)
{
	ans[x] = y, ans[y] = x;
}
inline void Work1(int n)
{
	if(n & 1)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	memset(ans, 0, sizeof(ans));
	int N = n;
	while(n)
	{
		int m = 1;
		while(m <= n)
			m <<= 1;
		m >>= 1;
		for(int i = m, j = m - 1; i <= n; i++, j--)
			Connect(i, j);
		n = (m << 1) - n - 2;
	}
	for(int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
	putchar('\n');
}
inline void Work2(int n)
{
	if((n & 1) && n <= 5)
	{
		printf("NO\n");
		return;
	}
	int m = 1;
	while(m <= n)
		m <<= 1;
	m >>= 1;
	if(n == m)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	memset(ans, 0, sizeof(ans));
	int N = n, mn = (n & 1) ? 8 : 2, rem = 0;
	for(; m >= mn; m >>= 1)
	{
		int st = m;
		if(!(n & 1))
		{
			Connect(m, m + 2);
			st += 3;
			rem = m + 1;
		}
		for(int i = st; i <= n; i += 2)
			Connect(i, i + 1);
		n = m - 1;
	}
	if(N & 1)
		for(int i = 1; i <= 7; i++)
			ans[i] = ans7[i];
	else
		Connect(1, rem);
	for(int i = 1; i <= N; i++)
		printf("%d ", ans[i]);
	putchar('\n');
}
int main()
{
	int n;
	scanf("%d", &n);
	Work1(n);
	Work2(n);
	return 0;
}