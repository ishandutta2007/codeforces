#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') 
	{
		if(ch == '-') nega = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		sum = sum * 10 + ch - '0'; ch = getchar();
	}
	return sum * nega;
}
const int N = 1e5 + 9, M = 29, Mas = (1 << 21) + 1;
int n, m, a[N];
int cnt[M][M];
int dp[Mas], pep[Mas];
char s[N];
int main()
{
	n = read(), m = read();
	scanf("%s", s);
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 0; i < n; i++) a[i] = s[i] - 'a';
	for (int i = 0; i < n - 1; i++) 
	{
		++cnt[a[i]][a[i + 1]];
		++cnt[a[i + 1]][a[i]]; 
	}
	dp[0] = 0;
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < m; j++)
			if((i & (1 << j))) ++pep[i];
	for (int i = 0; i < (1 << m); i++)
		for (int j = 0; j < m; j++)
			if(!(i & (1 << j)))
			{
				int res = dp[i];
				for (int k = 0; k < m; k++) 
					if(k != j)
					{
						if(!(i & (1 << k))) res -= (pep[i] + 1) * cnt[j][k]; 
						else res += (pep[i] + 1) * cnt[j][k];
					}
				dp[(i ^ (1 << j))] = min(dp[(i ^ (1 << j))], res);
			}
	cout << dp[(1 << m) - 1] << endl;
	return 0;
}