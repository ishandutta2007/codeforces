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
const int N = 109;
int k, n;
int a[N];
signed main()
{
	k = read(), n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int cnt1 = k, cnt2 = 2 * k, cnt3 = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = min(cnt1, a[i] / 4);
		a[i] -= 4 * tmp;
		cnt1 -= tmp;
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = min(cnt2, a[i] / 2);
		a[i] -= 2 * tmp;
		cnt2 -= tmp;
		tmp = min(cnt1, a[i] / 2);
		a[i] -= 2 * tmp;
		cnt1 -= tmp, cnt3 += tmp;
	}
	cnt3 += (cnt1 * 2 + cnt2);
	for (int i = 1; i <= n; i++)
	{
		int tmp = min(cnt3, a[i]);
		a[i] -= tmp;
		cnt3 -= tmp;
	}
	for (int i = 1; i <= n; i++)
		if(a[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0; 
}