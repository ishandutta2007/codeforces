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
int n, flag;
char s[N];
inline void solve()
{
	n = read(); flag = 0;
	scanf("%s", s + 1);
	for (int i = 1; i < n; i++)
	{
		if(s[i] != s[i + 1]) flag = 1;
		if(s[i] < s[i + 1] || (s[i] == s[i + 1] && !flag))
		{
			for (int j = 1; j <= i; j++) putchar(s[j]);
			for (int j = i; j >= 1; j--) putchar(s[j]);
			puts(""); return ;
		}
	}
	for (int i = 1; i <= n; i++) putchar(s[i]);
	for (int i = n; i >= 1; i--) putchar(s[i]); puts("");
	return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}