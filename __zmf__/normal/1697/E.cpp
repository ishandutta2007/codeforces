/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
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
const int N = 109, mod = 998244353;
int n, vis[N], dp[N], col[N], tmp[N], ans;
struct point
{
	int x, y;
}p[N];
inline int dis(int s, int t) {return abs(p[s].x - p[t].x) + abs(p[s].y - p[t].y);}
inline void draw(int now, int d)
{
	for (int i = 1; i <= n; i++) 
		if(now != i)
			if(dis(i, now) == d && !col[i]) {col[i] = 1, draw(i, d);}
	return ;
}
inline bool check(int d)
{
	for (int i = 1; i <= n; i++)
		if(col[i])
		{
			for (int j = 1; j <= n; j++)
				if(j != i)
				{
					if(col[j] && dis(i, j) != d) return 0;
					if(!col[j] && dis(i, j) <= d) return 0;
				}
		}
	return 1;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i].x = read(), p[i].y = read();
	dp[0] = 1;
	for (int i = 1; i <= n; i++) 
		if(!vis[i]) 
		{
			int Min = 1e9;
			memset(tmp, 0, sizeof(tmp));
			for (int j = n; j >= 1; j--) tmp[j] = dp[j - 1];
			for (int j = 1; j <= n; j++) 
				if(i != j) Min = min(Min, dis(i, j));
			memset(col, 0, sizeof(col)); col[i] = 1;
			draw(i, Min);
			if(check(Min)) 
			{
				int cnt = 0;
				for (int j = 1; j <= n; j++)
					if(col[j]) vis[j] = 1, cnt++;
				//cout << i << " " << cnt << endl;
				for (int j = n; j >= cnt; j--) tmp[j] = (tmp[j] + dp[j - cnt]) % mod;
			}
			for (int j = 0; j <= n; j++) dp[j] = tmp[j];
		}
	int now = 1;
	for (int i = 1; i <= n; i++) 
	{
		now = now * (n - i + 1) % mod; 
		ans = (ans + now * dp[i] % mod) % mod; 
	}
	cout << ans << endl;
	return 0;
}