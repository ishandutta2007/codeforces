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
int cnt, pr[N];
int n, x, now;
inline bool Isprime(int x) 
{
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}
inline void init()
{
	for (int i = 3; i <= 1e5; i++) 
		if(Isprime(i)) pr[++cnt] = i;
}
inline void solve()
{
	n = read(); 
	x = n; 
	now = 2; 
	while(now / 2 * (now + 1) <= n) 
	{
		if(x % 2 == 1)
		{
			printf("%lld\n", now); return ;
		}
		x /= 2; now *= 2;
	}
	while(x % 2 == 0) x /= 2;
	int r = sqrt(x);
	for (int i = 1; i <= cnt && r <= x; i++)
		if(x % pr[i] == 0) 
		{
			if(pr[i] * (pr[i] + 1) / 2 <= n) 
			{
				printf("%lld\n", pr[i]); 
				return ;
			}
			while(x % pr[i] == 0) x /= pr[i]; 
		}
	if(x * (x + 1) / 2 <= n && x != 1)
	{
		printf("%lld\n", x); return ;
	}
	puts("-1"); return ;
}
signed main()
{
	init();
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}