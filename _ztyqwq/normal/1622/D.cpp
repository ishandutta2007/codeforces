#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int C[5010][5010], p2[5010];
inline void InitC(int n)
{
	C[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= n; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
		p2[i] = (p2[i - 1] << 1) % mod;
}
int a[5010], m = 0;
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	InitC(n);
	string s;
	cin >> s;
	a[0] = 0;
	for(int i = 1; i <= n; i++)
		if(s[i - 1] == '1')
			a[++m] = i;
	a[m + 1] = n + 1;
	if(!k || k > m)
	{
		printf("1\n");
		return 0;
	}
	int ans = C[a[k + 1] - 1][k];
	for(int l = 2, r = k + 1; r <= m; l++, r++)
		ans = (ans + (C[a[r + 1] - a[l - 1] - 1][k] - C[a[r] - a[l - 1] - 1][k - 1] + mod) % mod) % mod;
	printf("%d\n", ans);
	return 0;
}