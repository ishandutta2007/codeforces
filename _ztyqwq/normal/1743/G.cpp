// LUOGU_RID: 91773400
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int LIM = 300, MX = 12; // fib[MX] <= LIM
char fibs[15][LIM + 10];
int fib[50], m;
inline char readc(bool &fl)
{
	char c;
	while((c = getchar()) != '0' && c != '1')
		fl = true;
	return c;
}
char c[LIM + 10]; // c[pos - i]
int dp[LIM + 10]; // dp[pos - i]
inline void Init()
{
	fib[0] = fib[1] = 1;
	m = 1;
	while(fib[m - 1] + fib[m] <= 3000000)
		fib[m + 1] = fib[m - 1] + fib[m], m++;
	fibs[0][1] = '0', fibs[1][1] = '1';
	for(int i = 2; fib[i] <= LIM; i++)
	{
		for(int j = 1; j <= fib[i - 1]; j++)
			fibs[i][j] = fibs[i - 1][j];
		for(int j = fib[i - 1] + 1; j <= fib[i]; j++)
			fibs[i][j] = fibs[i - 2][j - fib[i - 1]];
		// cout << (fibs[i] + 1) << endl;
	}
	dp[0] = 1;
}
inline bool CheckMatch(int id)
{
	for(int i = 1; i <= fib[id]; i++)
		if(c[fib[id] - i] != fibs[id][i])
			return false;
	return true;
}
int pos = 0, sum = 1;
unordered_map<int, int> mplen, mpdp; // max long, dp
inline void Work(char C)
{
	if(C == '#')
	{
		printf("%d\n", dp[0]);
		return;
	}
	for(int i = LIM - 1; i >= 0; i--)
		c[i + 1] = c[i], dp[i + 1] = dp[i];
	c[0] = C, dp[0] = 0;
	pos++;
	int bantot = 0;
	for(int j = 0; fib[j] <= LIM && fib[j] <= pos; j++)
	{
		bool fl = CheckMatch(j);
		if(fl)
		{
			bantot = (bantot + dp[fib[j]]) % mod;
			if(j >= MX - 1)
			{
				int p = pos - fib[j] + 1, l = j;
				mplen[p] = j;
				if(mpdp.find(p - 1) == mpdp.end())
					mpdp[p - 1] = dp[fib[j]];
				while(true)
				{
					int prep = p - fib[l + 1];
					if(prep > 0 && mplen.find(prep) != mplen.end() && mplen[prep] == l + 1)
						mplen[prep] = l + 2, p = prep, l += 2;
					else
						break;
				}
			}
		}
	}
	for(int j = MX + 1; j <= m; j++)
	{
		int p = pos - fib[j] + 1;
		if(p > 0 && mplen.find(p) != mplen.end() && mplen[p] >= j)
			bantot = (bantot + mpdp[p - 1]) % mod;
	}
	dp[0] = (sum + mod - bantot) % mod;
	sum = (sum + dp[0]) % mod;
}
char tmps[1010];
int main()
{
	int n;
	scanf("%d", &n);
	Init();
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 1005; j++)
			tmps[j] = 0;
		scanf("%s", tmps + 1);
		int len = strlen(tmps + 1);
		for(int j = 1; j <= len; j++)
			Work(tmps[j]);
		Work('#');
	}
	return 0;
}