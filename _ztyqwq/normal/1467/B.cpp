#include <bits/stdc++.h>
using namespace std;
int n;
int a[300001];
bool is[300001];
bool isp(int x)
{
	if(x <= 1 || x >= n)
		return false;
	return (a[x] < a[x - 1] && a[x] < a[x + 1]) || (a[x] > a[x - 1] && a[x] > a[x + 1]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int tot = 0, del = 0;
		for(int i = 1; i <= n; i++)
			tot += (is[i] = isp(i));
		is[0] = is[n + 1] = false;
		for(int i = 1; i <= n; i++)
		{
			if(i != 1)
			{
				int tmp = a[i];
				a[i] = a[i - 1];
				int d = 0;
				d += isp(i - 1) - is[i - 1];
				d += isp(i) - is[i];
				if(i != n)
					d += isp(i + 1) - is[i + 1];
				del = min(del, d);
				a[i] = tmp;
			}
			if(i != n)
			{
				int tmp = a[i];
				a[i] = a[i + 1];
				int d = 0;
				if(i != 1)
					d += isp(i - 1) - is[i - 1];
				d += isp(i) - is[i];
				d += isp(i + 1) - is[i + 1];
				del = min(del, d);
				a[i] = tmp;
			}
		}
		printf("%d\n", tot + del);
	}
	return 0;
}