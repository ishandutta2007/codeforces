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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1009;
int n, k, ans = 0, now = 1, pp, res;
int vis[N][N];
signed main() 
{	
	n = read(), k = read();
	while(now < n)
	{
		ans++;
		now *= k;
	}
	cout << ans << endl;
	now /= k; 
	for (int i = 1; i <= now; i++)
		for (int j = i + 1; j <= now; j++)
		{
			pp = now / k;
			while((i - 1) / pp == (j - 1) / pp) pp /= k;  
			res = 1;
			while(pp % k == 0) pp /= k, res++;
			vis[i][j] = res;
		}
	int l = now + 1, r = min(n, now * 2);
	while(l <= n)
	{
		for (int i = l; i <= r; i++)
			for (int j = i + 1; j <= r; j++)
			{
				pp = now / k;
				while((i - 1) / pp == (j - 1) / pp) pp /= k;
				res = 1;
				while(pp % k == 0) pp /= k, res++;
				vis[i][j] = res;
			}
		l = r + 1, r = min(n, l + now - 1);
		
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if(!vis[i][j]) printf("%lld ", ans);
			else printf("%lld ", vis[i][j]);
		}
	return 0;
}