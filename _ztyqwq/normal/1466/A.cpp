#include <bits/stdc++.h>
using namespace std;
int a[51];
bool b[51];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		memset(b, false, sizeof(b));
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				b[abs(a[i] - a[j])] = true;
		int ans = 0;
		for(int i = 1; i <= 50; i++)
			ans += b[i];
		printf("%d\n", ans);
	}
	return 0;
}