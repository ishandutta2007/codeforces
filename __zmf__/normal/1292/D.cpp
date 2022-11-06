/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 5009;
int n, m, cnt[N], res, ans; 
int f[N][N], pep[N], Max[N];
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		int x = read(); cnt[x]++; m = max(m, x);
	}
	for (int i = 1; i <= m; i++)
	{
		Max[i] = 1;
		int now = i, sum = 0;
		for (int j = 1; j <= i; j++) f[i][j] = f[i - 1][j], sum += f[i - 1][j];
		for (int j = 2; j <= now; j++)
			while(now % j == 0) f[i][j]++, now /= j, sum++;
		for (int j = 1; j <= i; j++)
			if(f[i][j]) Max[i] = j;
		res = res + sum * cnt[i];
	}
	while(1)
	{
		int pos = 1;
		for (int i = 1; i <= m; i++) pep[i] = 0;
		for (int i = 1; i <= m; i++) pep[Max[i]] += cnt[i];
		for (int i = 1; i <= m; i++)
			if(pep[i] > pep[pos]) pos = i;
		//cout << pos << " " << pep[pos] << endl;
 		if(pos == 1 || pep[pos] <= n / 2) break;
		res -= pep[pos]; res += (n - pep[pos]);
		for (int i = 1; i <= m; i++)
			if(Max[i] != pos) Max[i] = 1;
			else 
			{
				f[i][Max[i]]--;
				if(f[i][Max[i]] <= 0)
				{
					int flag = 0;
					for (int j = Max[i] - 1; j >= 1; j--)
						if(f[i][j])
						{
							Max[i] = j; flag = 1; break;
						}
					if(!flag) Max[i] = 1;
				}
			}
	}
	cout << res << endl;
	return 0;
}