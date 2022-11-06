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
const int N = 2e5 + 9;
int a[N], vis[N], res[N];
int ans[N], cnt;
int n, T;
inline void solve()
{
	n = read(); cnt = 0;
	for (int i = 1; i <= n; i++) a[i] = read(), vis[i] = 0; vis[0] = 0;
	int now = 0;
	for (int i = n; i >= 1; i--) 
	{
		vis[a[i]] = 1;
		while(vis[now]) ++now; 
		res[i] = now;
	}
	int l = 1; now = 0; for (int i = 0; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) 
	{
		vis[a[i]] = 1; 
		while(vis[now]) ++now;
	//	cout << now << " ";
		if(now == res[l]) 
		{
			ans[++cnt] = now; //cout << now << endl;
			for (int j = 0; j <= now; j++) vis[j] = 0;
			now = 0; l = i + 1;
		}
	} //cout << endl;
	printf("%lld\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%lld ", ans[i]);
	puts("");
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}