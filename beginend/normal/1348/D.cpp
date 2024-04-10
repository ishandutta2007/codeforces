#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, bin[35];

void solve(LL n, int ret, LL s)
{
	if (!ret) return;
	LL l = s, r = s * 2, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if ((LL)mid * ret <= n && (LL)mid * (bin[ret] - 1) >= n) break;
		else if ((LL)mid * ret > n) r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld ", mid - s);
	solve(n - mid, ret - 1, mid);
}

int main()
{
	bin[0] = 1;
	for (int i = 1; i <= 30; i++) bin[i] = bin[i - 1] * 2;
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int ans;
		for (int i = 1; i <= 30; i++)
			if (bin[i] - 1 >= n) {ans = i - 1; break;}
		printf("%d\n", ans);
		solve(n - 1, ans, 1);
		puts("");
	}
	return 0;
}