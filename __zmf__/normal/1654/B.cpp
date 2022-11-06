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
int n, T, cnt[N];
char a[N];
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		scanf("%s", a + 1);
		n = strlen(a + 1);
		for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) cnt[a[i]]++;
		for (int i = 1; i <= n; i++)
		{
			cnt[a[i]]--;
			if(!cnt[a[i]]) 
			{
				for (int j = i; j <= n; j++) putchar(a[j]); 
				break;
			}
		}
		puts("");
	}
	return 0;
}