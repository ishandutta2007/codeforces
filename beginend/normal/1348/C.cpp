#include<bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, k, s[26], a[N];
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		scanf("%s", str + 1);
		for (int i = 1; i <= n; i++) a[i] = str[i] - 'a';
		sort(a + 1, a + n + 1);
		bool flag1 = 0;
		for (int i = 2; i <= k; i++)
			if (a[i] != a[i - 1]) {flag1 = 1; break;}
		if (flag1) putchar(a[k] + 'a');
		else
		{
			putchar(a[1] + 'a');
			bool flag2 = 0;
			for (int i = k + 2; i <= n; i++)
				if (a[i] != a[i - 1]) {flag2 = 1; break;}
			if (flag2)
			{
				for (int i = k + 1; i <= n; i++)
					putchar(a[i] + 'a');
			}
			else
			{
				for (int i = 1; i <= (n - 1) / k; i++)
					putchar(a[k + 1] + 'a');
			}
		}
		puts("");
	}
	return 0;
}