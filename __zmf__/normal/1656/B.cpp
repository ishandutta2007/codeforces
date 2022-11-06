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
int T;
int n, a[N], k, flag;
map<int, int> mp;
inline void solve()
{
	n = read(); k = read(); mp.clear(); flag = 0;
	for (int i = 1; i <= n; i++) a[i] = read(), mp[a[i]] = 1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) 
		if(mp[a[i] + k]) flag = 1;
	if(flag) puts("Yes");
	else puts("No");
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}