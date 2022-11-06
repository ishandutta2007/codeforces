 /*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 1e6 + 9;
int T, n, c, a[N];
bool vis[N];
int sum[N];
inline void solve()
{
	n = read(), c = read();
	for (int i = 1; i <= c; i++) vis[i] = sum[i] = 0;
	for (int i = 1; i <= n; i++) a[i] = read(), vis[a[i]] = 1, sum[a[i]] = 1;
	for (int i = 1; i <= c; i++) sum[i] += sum[i - 1];
	for (int i = 1; i <= c; i++) 
		if(vis[i])
		{
			for (int j = 1; j <= c / i; j++) 
			{
				int l = i * j, r = min(c, i * j + i - 1);
				if(sum[r] != sum[l - 1] && !vis[j]) 
				{
					puts("No"); return ;
				} 
			}
		}
	puts("Yes"); return ;
}
signed main()
{
	T = read();
	while(T--) solve();
	return 0;
}