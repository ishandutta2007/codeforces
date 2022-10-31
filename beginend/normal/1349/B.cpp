#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k, a[N], s[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		bool flag = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] == k) flag = 1, a[i] = 1;
			else if (a[i] < k) a[i] = 0;
			else a[i] = 2;
		}
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (!a[i] ? -1 : 1);
		int mn = 0;
		bool tag = 0;
		for (int i = 2; i <= n; i++)
		{
			if (s[i] > mn)
			{
				tag = 1;
				break;
			}
			mn = min(mn, s[i - 1]);
		}
		if (tag && flag || flag && n == 1) puts("yes");
		else puts("no");
	}
	return 0;
}