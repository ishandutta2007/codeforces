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
const int N = 2e6 + 9;
int n;
char s[N];
int pre[N][2], nxt[N][2], s0, s1, ans, lst, l, r;
signed main()
{
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '0') s0 = i;
		else if(s[i] == '1') s1 = i;
		pre[i][0] = s1 + 1, pre[i][1] = s0 + 1; 
	}
	s0 = n + 1, s1 = n + 1;
	for (int i = n; i >= 1; i--)
	{
		if(s[i] == '0') s0 = i;
		else if(s[i] == '1') s1 = i;
		nxt[i][0] = s1 - 1, nxt[i][1] = s0 - 1;
	}
	for (int i = 1; i <= n; i++)
	{
		ans = 0, lst = 1;	
		for (int j = i; j <= n; j += i)
			if(pre[j][0] < pre[j][1])
			{
				int l = max(lst, pre[j][0]); 
				if(nxt[j][0] >= l + i - 1) 
				{
					++ans, lst = l + i; continue;
				}    
				l = max(lst, pre[j][1]);
				if(nxt[j][1] >= l + i - 1)
				{
					++ans, lst = l + i; continue;
				}
			}
			else
			{
				int l = max(lst, pre[j][1]); 
				if(nxt[j][1] >= l + i - 1) 
				{
					++ans, lst = l + i; continue;
				}    
				l = max(lst, pre[j][0]);
				if(nxt[j][0] >= l + i - 1)
				{
					++ans, lst = l + i; continue;
				}
			}
		printf("%lld ", ans);
	} 
	return 0;
}