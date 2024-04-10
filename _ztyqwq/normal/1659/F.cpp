#include <bits/stdc++.h>
using namespace std;
int n, k;
int d[200010], a[200010];
struct LOWBIT
{
	inline int lowbit(int x)
	{
		return x & -x;
	}
	int c[200010];
	inline void Init()
	{
		for(int i = 1; i <= n; i++)
			c[i] = 0;
	}
	inline void Modify(int u, int x)
	{
		for(int i = u; i <= n; i += lowbit(i))
			c[i] += x;
	}
	inline int Sum(int u)
	{
		int res = 0;
		for(int i = u; i; i -= lowbit(i))
			res += c[i];
		return res;
	}
	inline int Sum(int l, int r)
	{
		return Sum(r) - Sum(l - 1);
	}
}L;
int b[200010];
inline bool GetInv()
{
	for(int i = 1; i <= n; i++)
		b[a[i]] = i;
	L.Init();
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int u = b[i];
		ans += (L.Sum(u + 1, n) & 1);
		L.Modify(u, 1);
	}
	return ans & 1;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++)
			d[i] = 0;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			d[u]++, d[v]++;
		}
		int rt = 0;
		for(int i = 1; i <= n; i++)
			if(d[i] > 1)
				rt = (!rt) ? i : -1;
		for(int i = 1; i <= n; i++)
			scanf("%d", &b[i]), a[b[i]] = i;
		if(rt == -1)
		{
			printf("Alice\n");
			continue;
		}
		swap(a[1], a[rt]);
		for(int i = 1; i <= n; i++)
			if(a[i] == 1 || a[i] == rt)
				a[i] = rt + 1 - a[i];
		if(k == 1 || k == rt)
			k = rt + 1 - k;
		int x1 = 0, x2 = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] != i)
			{
				if(!x1)
					x1 = i;
				else if(!x2)
					x2 = i;
				else
					x1 = -1;
			}
		if(!x1)
		{
			printf("Alice\n");
			continue;
		}
		if(x1 != -1)
		{
			if(k == x1 || k == x2)
				printf("Bob\n");
			else
				printf("Alice\n");
			continue;
		}
		bool res = GetInv();
		if(a[1] == 1)
		{
			if((k == 1) ^ res)
				printf("Bob\n");
			else
				printf("Alice\n");
		}
		else if(res)
			printf("Bob\n");
		else if(k == 1 || k == b[1])
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}