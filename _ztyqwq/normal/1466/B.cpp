#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] <= a[i - 1])
				a[i]++;
		for(int i = 1; i <= n; i++)
			if(a[i] != a[i - 1])
				ans++;
		printf("%d\n", ans);
	}
	return 0;
}