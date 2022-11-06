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
int n, e, T, a[N], ans, b[N];
inline bool Isprime(int x)
{
	if(x == 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}
inline void solve()
{
	n = read(), e = read(); ans = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		b[i] = Isprime(a[i]);
	}
	for (int i = 1; i <= e; i++)
	{
		int now = 0, r = i;
		for (int j = i; j <= n; j += e) 
			if(b[j] == 1)
			{
				int l = j - e, r = j + e;
				while(l >= 0 && a[l] == 1) l -= e; l += e;
				while(r <= n && a[r] == 1) r += e; r -= e;
			//	cout << l << " " << r << endl;
				l = (j - l) / e + 1; r = (r - j) / e + 1;
				ans += max(0ll, ((l * r) - 1));
			}
	}
	printf("%lld\n", ans); return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}