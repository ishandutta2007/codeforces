#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;

int n, fir[N];
char str[N];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str + 1);
		n = strlen(str + 1);
		for (int i = 1; i <= n; i++) fir[i] = 0;
		int w = 0;
		for (int i = 1; i <= n; i++)
		{
			w += str[i] == '+' ? 1 : -1;
			if (w < 0 && !fir[-w]) fir[-w] = i;
		}
		LL ans = n;
		for (int i = 1; i <= n; i++) ans += fir[i];
		printf("%lld\n", ans);
	}
	return 0;
}