#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <=n; i++) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		int ans = 0, s = 0;
		for (int i = 1; i <= n; i++)
		{
			s++;
			if (s >= a[i]) ans++, s = 0;
		}
		printf("%d\n", ans);
	}
	return 0;
}