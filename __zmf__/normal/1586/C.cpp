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
const int N = 1e6 + 9;
int T, n, m;
int vis[N];
int t[N];
char s[N];
vector<int> G[N]; 
inline bool check(int x, int y){return x >= 1 && y >= 1 && G[x][y - 1] == 0;}
signed main() 
{	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++) 
			if(s[j] == '.') G[i].push_back(1);
			else G[i].push_back(0);
	}
	for (int i = 1; i <= m; i++)
	{
		vis[i] = 0;
		for (int j = 1; j <= n; j++) 
			if(check(j, i - 1) && check(j - 1, i)) vis[i] = 1;
	}
	for (int i = 1; i <= m; i++) vis[i] += vis[i - 1];
	int Q = read();
	for (int i = 1; i <= Q; i++)
	{
		int x = read(), y = read();
		if(vis[y] != vis[x]) puts("NO");
		else puts("YES");
	}
	return 0;
}