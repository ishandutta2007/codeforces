#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

#define mp make_pair
#define pb push_back

int dp[222][105];
int dp2[105];
char cc[555];
char c[111];
char a[111];
int alen, clen;

int main()
{
	#if 0
		freopen("a.in", "r", stdin);
		freopen("a.out", "w", stdout);
	#endif
	
	int b, d;
	scanf("%d %d\n", &b, &d);
	
	gets(a);
	gets(c);
	
	alen = strlen(a);
	clen = strlen(c);
	
	
	
	for (int i = 0; i < clen; i++)
	{
		cc[i] = cc[i+clen] = c[i];
	}
	
	for (int i = 0; i < clen; i++)
	{
		/*int p = i;
		for (int j = 0; j < alen; j++)
		{
			if (a[j] == c[p])
			{
				p++;
				dp2[i]++;
			}
			if (p == clen)
				p = 0;
		}
		
		cout << dp2[i] << endl;
		for (int j = 0; j <= alen; j++)
			for (int h = 0; h <= clen; h++)
				dp[j][h] = 0;*/
		dp[0][0] = dp[1][0] = dp[0][1] = 0;
		dp[0][clen] = 0;
		
		int v = 0;
		
		for (int j = 1; j <= alen; j++)
		{
			//dp[j][0] = 0;
			
			//if (dp[j][clen] % clen == 0)
			{
				//dp[j][0] = dp[j][clen];
			}
			for (int h = 1; h <= clen; h++)
			{
				int ind = (h + i) ;
				
				if (h && (cc[ind-1] == a[j-1]))
				{
					if (h == 1 || dp[j-1][h-1] > 0)
					dp[j][h] = dp[j-1][h-1] + 1;
					else
					dp[j][h] = dp[j-1][h];
				}
				else if (h)
				{
					dp[j][h] = dp[j-1][h];
				}
				
				if (h == 0)
				{
					//dp[j][h] = dp[j-1][h];
				}
				
				//cout << dp[j][h] << " ";
			}
			//cout << endl;
			if (dp[j][clen] % clen == 0)
			{
				dp[j][0] = max(dp[j-1][0], dp[j][clen]);
			}
		}
		//return 0;
		int ans = 0;
		int ind = 0;
		for (int j = 1; j <= clen; j++)
		{
			if (dp[alen][j] > ans)
			{
				ans = dp[alen][j];
				ind = j;
			}
		}
		dp2[i] = ans;
	}
	//cout << dp2[0];
	int len = 0;
	int curr = 0;
	
	for (int i = 0; i < b; i++)
	{
		len += dp2[curr];
		curr = dp2[curr] + curr;
		curr %= clen;
	}
	int ans = len / (clen*d);
	cout << ans;
	return 0;
}