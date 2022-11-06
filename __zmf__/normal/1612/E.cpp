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
const int N = 2e5 + 9;
const long double eps = 0.00000000000000001;
int n, m[N], k[N], pos, Max, Maxm;
long double ans;
struct point
{
	int id; long double p;
}s[N];
inline bool cmp(point xxx, point yyy) 
{
	return (xxx.p - yyy.p) > eps;
}
inline long double get(int x)
{
	long double res = 0;
	for (int i = 1; i <= Maxm; i++) s[i].p = 0, s[i].id = i;
	for (int i = 1; i <= n; i++)
		if(k[i] < x) s[m[i]].p += k[i] * 1.00000000000 / x * 1.000000000000;
		else s[m[i]].p += 1.00000000000;
	sort(s + 1, s + Maxm + 1, cmp);
	for (int i = 1; i <= x; i++) res += s[i].p;
	return res;
} 
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) m[i] = read(), k[i] = read(), Max = max(Max, k[i]), Maxm = max(Maxm, m[i]);
	ans = -10000000;
	for (int i = 1; i <= Max; i++) 
	{
		long double now = get(i); 
		if(ans < now) 
		{
			ans = now, pos = i; 
		}
	}
	get(pos);
	printf("%lld\n", pos);
	for (int i = 1; i <= pos; i++) printf("%lld ", s[i].id);
	return 0;
}