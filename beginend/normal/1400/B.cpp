#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL p, f, s, w;
int c1, c2;

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%lld%lld", &p, &f);
		scanf("%d%d", &c1, &c2);
		scanf("%lld%lld", &s, &w);
		if (w < s) swap(c1, c2), swap(s, w);
		int ans = 0;
		for (int i = 0; i <= c1; i++)
			if (i * s <= p)
			{
				int ret = c2 - min((p - i * s) / w, (LL)c2), k = c2 - ret + i;
				if ((c1 - i) * s >= f) k += f / s;
				else k += c1 - i + min((LL)ret, (f - (c1 - i) * s) / w);
				ans = max(ans, k);
			}
		printf("%d\n", ans);
	}
	return 0;
}