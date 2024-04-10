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
const int N = 109;
int n, a[N];
char s[N];
signed main()
{
	n = read();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) a[i] = s[i] - '0' ;
	for (int i = 0; i <= 900; i++)
	{
		int cnt = 0, nowsum = 0;
		for (int j = 1; j <= n; j++)
		{
			nowsum += a[j];
			if(nowsum > i) break;
			else if(nowsum == i) nowsum = 0, cnt++;
		}
		if(nowsum != 0) continue;
		if(cnt == 1) continue;
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}