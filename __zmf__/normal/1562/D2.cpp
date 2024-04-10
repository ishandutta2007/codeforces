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
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 3e5 + 9;
int T;
int n, q;
char s[N];
int sum[N];
vector<int> G[N * 4];
inline int work(int l, int r)
{
	int val = sum[r] + sum[l - 1] + 2 * n;
	int pos = lower_bound(G[val].begin(), G[val].end(), l) - G[val].begin();
	return G[val][pos];
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(), q = read();
		scanf("%s", s + 1);
		for (int i = 0; i <= 4 * n; i++) G[i].clear();
		for (int i = 1; i <= n; i++) 
		{
			int pos = -1;
			if(i & 1) pos = 1;
			if(s[i] == '-') pos = -pos;
			sum[i] = sum[i - 1] + pos;
			G[sum[i] + sum[i - 1] + 2 * n].push_back(i);
		}
		for (int i = 1; i <= q; i++)
		{
			int l = read(), r = read();
			if(sum[r] - sum[l - 1] == 0) puts("0");
			else if((r - l + 1) % 2 == 1) 
			{
				puts("1");
				printf("%d\n", work(l, r));
			}
			else 
			{
				puts("2");
				printf("%d %d\n", l, work(l + 1, r));
			}
		}
	}
	return 0;
}