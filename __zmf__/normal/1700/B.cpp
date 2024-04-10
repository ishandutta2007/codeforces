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
const int N = 1e5 + 9;
int n, T, ans;
char s[N], t[N];
inline void work()
{
	n = read();
	scanf("%s", s + 1);
	if(s[1] != '9')
	{
		for (int i = 1; i <= n; i++) printf("%d", (int)('9' - s[i]));
		puts("");
		return ;
	}
	else
	{
		int tui = 0;
		for (int i = 1; i <= n; i++) t[i] = '1'; 
		t[1] = '0' + 11;
		for (int i = n; i >= 1; i--) 
		{
			if(s[i] + tui > t[i])
			{
				s[i] = (t[i] + 10) - (s[i] + tui); tui = 1;
			} 
			else s[i] = t[i] - (s[i] + tui), tui = 0;
		}
		for (int i = 1; i <= n; i++) printf("%d", (int)s[i]);
		puts("");
		return ;
	}
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) work();
	return 0;
}