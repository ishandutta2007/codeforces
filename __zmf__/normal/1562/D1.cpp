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
const int N = 3e5 + 9;
int T;
int n, q;
char s[N];
int sum[N];
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(), q = read();
		scanf("%s", s + 1);
		for (int i = 1; i <= n; i++) 
		{
			int pos = -1;
			if(i & 1) pos = 1;
			if(s[i] == '-') pos = -pos;
			sum[i] = sum[i - 1] + pos;
		}
		for (int i = 1; i <= q; i++)
		{
			int l = read(), r = read();
			if(sum[r] - sum[l - 1] == 0) puts("0");
			else if((r - l + 1) % 2 == 1) puts("1");
			else puts("2");
		}
	}
	return 0;
}