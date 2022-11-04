#include <bits/stdc++.h>

using namespace std;

int S[2010][2010], D[2010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
		{
			int x;
			scanf("%d", &x);
			S[j][i] = S[i][j] = x;
			if(x != -1) ans += x, D[i]++, D[j]++;
		}
	if(m != 2) return printf("%lld\n", ans * 2 / n), 0;
	for(int i = 1; i <= n; i++)
		if(D[i] == n - 1)
		{
			long long k = 0;
			for(int j = 1; j <= n; j++) if(j != i) k += S[i][j];
			return printf("%lld\n", (k * (n - 1) + (ans - k) * 2) / (n * (n - 1) / 2)), 0;
		}
}