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
bool v[31][31], p[31][31][31], t[31][31];
int n, T, ans;
char ww[10];
int s[10];
inline void solve()
{
	n = read(); ans = 0;
	memset(v, 0, sizeof(v)); memset(p, 0, sizeof(p)); memset(t, 0, sizeof(t));
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", ww + 1);
		int len = strlen(ww + 1); 
		for (int j = 1; j <= len; j++) s[j] = ww[j] - 'a' + 1;
		if(len == 1) ans = 1;
		else if(len == 2) 
		{
			if(v[s[2]][s[1]]) ans = 1;
			if(s[1] == s[2]) ans = 1;
			v[s[1]][s[2]] = 1; t[s[1]][s[2]] = 1;
		}
		else
		{
			if(p[s[3]][s[2]][s[1]]) ans = 1;
			if(t[s[3]][s[2]]) ans = 1;
			if(s[1] == s[3]) ans = 1;
			p[s[1]][s[2]][s[3]] = 1; v[s[1]][s[2]] = 1; 
		}
	} 
	if(ans) puts("YES");
	else puts("NO");
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}