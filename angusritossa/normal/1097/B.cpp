#include <bits/stdc++.h>
using namespace std;
int n, a[100];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int b = 0; b < (1 << n); b++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (b & (1 << i)) sum += a[i];
			else sum -= a[i];
		}
		while (sum < 0) sum += 360;
		sum %= 360;
		if (!sum)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}