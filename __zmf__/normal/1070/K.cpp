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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int n, k;
int a[N], sum, now, cnt, p;
int ans[N]; 
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
	if(sum % k != 0)
	{
		puts("No"); return 0;
	}
	sum /= k;
	for (int i = 1; i <= n; i++)
	{
		now += a[i]; cnt++; 
		if(now == sum) 
		{
			ans[++p] = cnt; cnt = now = 0;
		}
		if(now > sum)
		{
			puts("No"); return 0;
		}
	}
	puts("Yes");
	for (int i = 1; i <= p; i++) printf("%lld ", ans[i]);
	return 0;
}