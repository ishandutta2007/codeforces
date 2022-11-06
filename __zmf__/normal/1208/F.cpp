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
const int N = 3e6 + 9;
int n, a[N], cnt[N], ans, id[N];
inline void add(int x, int p)	
{
	if(cnt[x] >= 2) return ;
	if(id[x] == p) return ;
	cnt[x]++; id[x] = p;
	if(x == 0) return ;
	for (int i = 0; i <= 21; i++) 
		if(x & (1 << i)) add(x - (1 << i), p);
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = n; i >= 1; i--)
	{
		int res = 0;
		for (int j = 21; j >= 0; j--)
			if(!(a[i] & (1 << j)))
			{
				if(cnt[res + (1 << j)] >= 2) res += (1 << j);
			}
		if(cnt[res] >= 2) ans = max(ans, res + a[i]);
	//	if(res + a[i] == 96206) cout << i << " " << a[i] << " " << res << endl;
		add(a[i], i);
	}
	cout << ans << endl;
	return 0;
}