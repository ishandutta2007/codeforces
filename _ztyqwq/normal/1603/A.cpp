#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010], l[100010], r[100010];
int c[100010];
inline int lowbit(int x)
{
	return x & -x;
}
inline void ad(int u, int x)
{
	for(int i = u; i <= n; i += lowbit(i))
		c[i] += x;
}
inline int sum(int u)
{
	int res = 0;
	for(int i = u; i; i -= lowbit(i))
		res += c[i];
	return res;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), l[i] = i - 1, r[i] = i + 1, c[i] = 0;
		l[n + 1] = n, r[0] = 1;
		int cnt = 0;
		while(cnt < n)
		{
			bool flag = false;
			for(int i = l[n + 1]; i; i = l[i])
				if(a[i] % (i - sum(i - 1) + 1) != 0)
				{
					l[r[i]] = l[i], r[l[i]] = r[i];
					ad(i, 1);
					cnt++;
					flag = true;
					break;
				}
			if(!flag)
				break;
		}
		if(cnt == n)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}