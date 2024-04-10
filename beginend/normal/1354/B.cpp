#include<bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, sum[N][4], a[N];
char str[N];

bool check(int l, int r)
{
	for (int i = 1; i <= 3; i++)
		if (sum[r][i] - sum[l - 1][i] == 0) return 0;
	return 1;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%s", str + 1);
		n = strlen(str + 1);
		for (int i = 1; i <= n; i++)
		{
			a[i] = str[i] - '0';
			for (int j = 1; j <= 3; j++) sum[i][j] = sum[i - 1][j];
			sum[i][a[i]]++;
		}
		if (!sum[n][1] || !sum[n][2] || !sum[n][3]) {puts("0"); continue;}
		int now = 1, ans = n;
		for (int i = 1; i <= n; i++)
		{
			while (now < i && check(now + 1, i)) now++;
			if (check(now, i)) ans = min(ans, i - now + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}