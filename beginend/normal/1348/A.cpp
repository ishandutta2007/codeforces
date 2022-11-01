#include<bits/stdc++.h>
using namespace std;

int n, bin[35];

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		bin[0] = 1;
		for (int i = 1; i <= n; i++) bin[i] = bin[i - 1] * 2;
		int ans = bin[n];
		for (int i = 1; i < n / 2; i++) ans += bin[i];
		for (int i = n / 2; i < n; i++) ans -= bin[i];
		printf("%d\n", ans);
	}
	return 0;
}