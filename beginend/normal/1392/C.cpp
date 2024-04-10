#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		LL ans = 0;
		for (int i = n; i > 1; i--)
			if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
		printf("%lld\n", ans);
	}
	return 0;
}