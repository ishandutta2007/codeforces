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
const int N = 1e5 + 9;
int T;
int n, a[N], id[N];
inline bool cmp(int x, int y) {return a[x] < a[y];}
inline void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	printf("%lld %lld\n", id[1], id[n]);
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}