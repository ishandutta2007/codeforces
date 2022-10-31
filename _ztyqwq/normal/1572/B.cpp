#include <bits/stdc++.h>
using namespace std;
int a[200010];
bool b[200010];
vector<int> ans;
inline void Work2(int l, int r)
{
	for(int i = l; i <= r - 2; i += 2)
		ans.push_back(i);
	for(int i = r - 4; i >= l; i -= 2)
		ans.push_back(i);
}
inline void Work1L(int l, int r)
{
	for(int i = l; i <= r - 3; i += 2)
	{
		ans.push_back(i);
		ans.push_back(i - 1);
	}
	ans.push_back(r - 2);
}
inline void Work1R(int l, int r)
{
	for(int i = r; i >= l + 3; i -= 2)
	{
		ans.push_back(i - 2);
		ans.push_back(i - 1);
	}
	ans.push_back(l);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if(x)
				a[++m] = i;
		}
		if(m & 1)
		{
			printf("NO\n");
			continue;
		}
		m >>= 1;
		for(int i = 0; i <= m + 1; i++)
			b[i] = false;
		if(a[1] > 1)
			b[0] = true;
		if(a[m << 1] < n)
			b[m + 1] = true;
		ans.clear();
		for(int i = 1; i <= m; i++)
		{
			int l = a[(i << 1) - 1], r = a[i << 1];
			if(!((r - l) & 1))
			{
				Work2(l, r);
				b[i] = true;
			}
		}
		int flag = 0;
		for(int i = 1; i <= m; i++)
			if(!b[i])
			{
				if(b[i + 1] || a[(i << 1) + 1] - a[i << 1] >= 2)
				{
					for(int j = i; j >= 1 && !b[j]; j--)
						Work1R(a[(j << 1) - 1], a[j << 1]), b[j] = true;
					flag = 2;
				}
				if(b[i - 1] || a[(i << 1) - 1] - a[(i << 1) - 2] >= 2)
				{
					for(int j = i; j <= m && !b[j]; j++)
						Work1L(a[(j << 1) - 1], a[j << 1]), b[j] = true;
					flag = 2;
				}
				if(!flag)
					flag = 1;
			}
		if(flag == 1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		printf("%d\n", ans.size());
		for(auto x: ans)
			printf("%d ", x);
		if(ans.size())
			putchar('\n');
	}
	return 0;
}