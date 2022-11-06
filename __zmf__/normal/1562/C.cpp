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
const int N = 2e4 + 9;
int T;
int n, flag;
char s[N];
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); flag = 0;
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++)
			if(s[i] == '0') flag = 1;
		if(!flag)
		{
			printf("%d %d %d %d\n", 1, n - 1, 2, n);
			continue;
		}
		for (int i = 1; i <= n; i++)
			if(s[i] == '0')
			{
				if(i > n / 2) printf("%d %d %d %d\n", 1, i, 1, i - 1);
				else printf("%d %d %d %d\n", i + 1, n, i, n);
				break;
			}
	}
	return 0;
}