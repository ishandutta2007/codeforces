#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];
int ans = -999999999;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		if ((int)sqrt(abs(a))*(int)sqrt(abs(a)) != a)
		{
			ans = max(ans, a);
		}
	}
	printf("%d\n", ans);
}