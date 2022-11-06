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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e6 + 9;
int n, k, c[N];
inline int lowbit(int x)
{
	return x & (-x);
}
inline void update(int x)
{
	while(x <= N)
	{
		c[x]++, x += lowbit(x);
	}
}
inline int query(int x)
{
	if(x == 0) return 0; 
	int qwq = 0;
	while(x)
	{
		qwq += c[x], x -= lowbit(x);
	}
	return qwq;
}
signed main()
{
	n = read(); k = read();
	k = min(k, n - k);
	int st = 1, res = 1;
	for (int i = 1; i <= n; i++)
	{
		int fi = (st + k - 1) % n + 1;
		if(fi > st) res += (query(fi - 1) - query(st) + 1);
		else res += (query(n) - query(st) + query(fi - 1) + 1);
		update(st);
		update(fi);
		st = fi;
		printf("%lld ", res);
	}
	return 0;
}