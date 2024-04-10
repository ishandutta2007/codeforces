#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
char str[200010];
int mx;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf(" %s", str);
	for (int i = 0; i < n; i++)
	{
		mx = max(mx, a[i]);
		if (str[i] == '0')
		{
			if (mx != i+1)
			{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}