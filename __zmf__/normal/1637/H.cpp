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
const int N = 5e5 + 9;
int n, T, c[N], p[N], w[N], ans;
inline int lowbit(int x) {return x & (-x);}
inline void add(int x, int v) 
{
	while(x <= n) c[x] += v, x += lowbit(x); return ;
}
inline int query(int x) 
{
	int res = 0;
	while(x) res += c[x], x -= lowbit(x);
	return res;
}
inline void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i] = read(); ans = 0;
	for (int i = 1; i <= n; i++) 
	{
		ans += (i - 1 - query(p[i]));  
		w[i] = (i - 1) - 2 * (p[i] - 1); 
		add(p[i], 1);
	} 
	for (int i = 1; i <= n; i++) c[i] = 0; 
	sort(w + 1, w + n + 1, [&](int x, int y){return x > y;});
	for (int i = 1; i <= n; i++) printf("%lld ", ans), ans -= w[i], ans -= (i - 1);
	printf("%lld\n", ans); return ;
}
signed main()
{
	T = read();
	for (int i = 1; i <= T; i++) solve();
	return 0;
}