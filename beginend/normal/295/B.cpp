#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 505;

int n, p[N], a[N][N];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	vector<LL> res;
	for (int k = n; k >= 1; k--)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[p[i]][p[j]] = min(a[p[i]][p[j]], a[p[i]][p[k]] + a[p[k]][p[j]]);
		LL ans = 0;
		for (int i = k; i <= n; i++)
			for (int j = k; j <= n; j++)
				ans += a[p[i]][p[j]];
		res.push_back(ans);
	}
	for (vector<LL>::reverse_iterator it = res.rbegin(); it != res.rend(); it++)
		printf("%lld ", *it);
	return 0;
}