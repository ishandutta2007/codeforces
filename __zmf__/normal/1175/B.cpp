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
const int INF = 1e12, N = 1e5 + 9;
int sta[N], m, ans, top, k;
char opt[10];
signed main()
{
	m = read();
	top++, sta[top] = 1;
	for (int i = 1; i <= m; i++)
	{
		scanf("%s", opt);
		if(opt[0] == 'a') ans = ans + sta[top];
		else if(opt[0] == 'e') top--;
		else k = read(), top++, sta[top] = min(INF, sta[top - 1] * k);
	}
	if(ans >= 1ll << 32) puts("OVERFLOW!!!");
	else printf("%lld\n", ans);
	return 0;
}