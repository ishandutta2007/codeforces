/*
	
	
	
	
	
	
	
	
	
	
	
	
					                  ever17 
*/
//#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
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
	while (ch <= '9' && ch >= '0')sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 2e5 + 9;
int dcnt, n, rcnt, now, vis[N], rnow, dnow;
char a[N];
signed main()
{
	dnow = 0, rnow = 0;
	n = read();
	scanf("%s", a + 1);
	for (int i = 1; i <= n; i++)
		if(a[i] == 'D') dcnt++;
		else rcnt++;
	now = 0;
	while(dcnt > 0 && rcnt > 0)
	{
		now = now % n + 1;
		if(vis[now] == 1) continue;
		if(a[now] == 'D')
		{
			if(rnow) rnow--, dcnt--, vis[now] = 1;
			else dnow++;
		}
		else
		{
			if(dnow) dnow--, rcnt--, vis[now] = 1;
			else rnow++;
		}
	//	now = now % n + 1;
	//	for (int i = 1; i <= n; i++) cout << vis[i] << " " ;cout << endl;
	}
	if(dcnt) puts("D");
	else puts("R");
	return 0;
}