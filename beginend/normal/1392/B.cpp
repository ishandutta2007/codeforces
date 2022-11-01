#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;
const int inf = 1e9;

int n, a[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		LL k;
		scanf("%d%lld", &n, &k);
		int mx = -inf;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
		int w = 0;
		for (int i = 1; i <= n; i++) a[i] = mx - a[i], w = max(w, a[i]);
		k--;
		if (k & 1)
		{
			for (int i = 1; i <= n; i++) printf("%d ", w - a[i]);
		}
		else
		{
			for (int i = 1; i <= n; i++) printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}