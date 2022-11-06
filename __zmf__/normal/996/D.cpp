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
const int N = 1e5 + 9;
int n, a[N], ans, p[N], vis[N];
signed main()
{
	n = read();
	for (int i = 1; i <= n * 2; i++)
	{
		int x = read();
		a[i] = x;
		if(p[x] == 0) p[x] = i;
		else if(i - p[x] >= 2) 
		{
			ans += (i - p[x] - 1);
			for (int j = 1; j <= n; j++) vis[j] = 0;
			for (int j = p[x] + 1; j < i; j++)
			{
				if(vis[a[j]]) ans += 2;
				vis[a[j]] = 1;
			}
		//	cout << ans << endl;
		}
	}
	cout << ans / 2 << endl;
	return 0;
}