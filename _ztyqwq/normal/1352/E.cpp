#include <bits/stdc++.h>
using namespace std;
int a[8001], s[8001];
bool vis[8001];
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		s[0] = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]), s[i] = s[i - 1] + a[i];
		memset(vis, false, sizeof(vis));
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(s[j] - s[i - 1] <= n)
					vis[s[j] - s[i - 1]] = true;
		int ans = 0;
		for(int i = 1; i <= n; i++)
			ans += vis[a[i]];
		printf("%d\n", ans);
	}
	return 0;
}