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
const int N = 5009;
int n, w, h, dp[5009], to[5009], ans[5009];
struct point
{
	int w, h, id;
}p[N];
inline bool cmp(point xxx, point yyy)
{
	if(xxx.w != yyy.w) return xxx.w < yyy.w;
	else return xxx.h < yyy.h;
}
signed main()
{
	n = read(); w = read(), h = read();
	for (int i = 1; i <= n; i++) p[i].w = read(), p[i].h = read(), p[i].id = i;
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		if(p[i].w > w && p[i].h > h)
		{
			dp[i] = 1, to[i] = 0;
			for (int j = 1; j < i; j++)
				if(p[i].w > p[j].w && p[i].h > p[j].h && dp[j] + 1 > dp[i]) to[i] = j, dp[i] = dp[j] + 1; 
		//	cout << p[i].id << endl;
		}
	int pos = 0;
	for (int i = 1; i <= n; i++)
		if(dp[pos] <= dp[i]) pos = i;
	cout << dp[pos] << endl;
	int x = pos;
	for (int i = 1; i <= dp[pos]; i++)
		ans[i] = x, x = to[x];
	for (int i = dp[pos]; i >= 1; i--) cout << p[ans[i]].id << " "; 
	return 0;
}