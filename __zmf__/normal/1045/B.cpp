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
const int N = 2e5 + 9, mod = 1e9 + 7, base = 998244353;
int n, m, cnt;
int a[N], b[N], ans[N], p1[N], p2[N], pown[N]; 
inline void init()
{
	pown[0] = 1;
	for (int i = 1; i <= n; i++) pown[i] = pown[i - 1] * base % mod;
	for (int i = 1; i <= n - 1; i++) p1[i] = (p1[i - 1] * base + (a[i + 1] - a[i])) % mod;
	for (int i = n - 1; i >= 1; i--) p2[i] = (p2[i + 1] * base + (a[i + 1] - a[i])) % mod;
	return ;
}
inline int Hash1(int l, int r)
{
	return (p1[r] - p1[l - 1] * pown[r - l + 1] % mod + mod) % mod;
}
inline int Hash2(int l, int r)
{
	return (p2[l] - p2[r + 1] * pown[r - l + 1] % mod + mod) % mod;
}
inline bool check(int l, int r)
{
	int mid = (l + r) >> 1;
	int len = mid - l;
	return Hash1(l, mid - 1) == Hash2(r - len, r - 1);
}
signed main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = (a[1] + a[i]) % m;
	init();
	for (int i = 1; i <= n; i++)
	{
		int mid = (1 + i) >> 1;
		if(!check(1, i)) continue;
		if(i == n) 
		{
			ans[++cnt] = b[i]; continue;
		} 
		if(a[i + 1] + a[n] != b[i] + m) continue;
		if(!check(i + 1, n)) continue;
		ans[++cnt] = b[i];
	}
	cout << cnt << endl;
	sort(ans + 1, ans + cnt + 1);
	for (int i = 1; i <= cnt; i++) printf("%lld ", ans[i]);
	return 0;
}