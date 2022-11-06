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
int n, ans;
multiset<int> s[2];
struct point
{
	int l, r, t;
}a[N];
inline bool cmp(point xxx, point yyy)
{
	return xxx.r < yyy.r;
}
signed main()
{
	n = read(); ans = n;
	for (int i = 1; i <= n; i++) a[i].l = read(), a[i].r = read(), a[i].t = read() - 1;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) 
		if(s[!a[i].t].lower_bound(a[i].l) == s[!a[i].t].end()) s[a[i].t].insert(a[i].r);
		else --ans, s[!a[i].t].erase(s[!a[i].t].lower_bound(a[i].l));
	cout << ans << endl;
	return 0;
}