#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1000005;
const int MOD = 1000000007;

int n, len[N], nx[N], nx0[N], nx1[N], pos[N], f[N];
char str[N];

int main()
{
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for (int i = 1; i <= n; i++)
		if (str[i] == '0') len[i] = len[i - 1] + 1;
	for (int i = n; i >= 1; i--)
	{
		nx1[i] = i < n && str[i + 1] == '1' ? i + 1 : nx1[i + 1];
		nx0[i] = i < n && str[i + 1] == '0' ? i + 1 : nx0[i + 1];
		if (str[i] == '0') nx[i] = pos[len[i] + 1], pos[len[i]] = i;
	}
	if (len[n] == n) {printf("%d\n", n); return 0;}
	for (int i = n; i >= 1; i--)
	{
		if (str[i] == '0')
		{
			if (len[i] <= len[n]) f[i] = 1;
			if (nx1[i]) (f[i] += f[nx1[i]]) %= MOD;
			if (nx[i]) (f[i] += f[nx[i]]) %= MOD;
		}
		else
		{
			f[i] = 1;
			if (nx0[i]) (f[i] += f[nx0[i]]) %= MOD;
			if (nx1[i]) (f[i] += f[nx1[i]]) %= MOD;
		}
	}
	int p = 0;
	for (int i = 1; i <= n; i++) if (str[i] == '1') {p = i; break;}
	printf("%d\n", (LL)p * f[p] % MOD);
	return 0;
}