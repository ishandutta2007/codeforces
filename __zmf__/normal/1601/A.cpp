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
const int N = 2e5 + 9;
int T, n, a[N], k;
int cnt[39], p; 
inline int Gcd(int x, int y)
{
	if(y == 0) return x;
	else return Gcd(y, x % y);
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); k = 0; p = 0;
		for (int i = 0; i < 30; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) a[i] = read();
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 30; j++)
				if((a[i] & (1 << j))) cnt[j]++;
		for (int i = 0; i < 30; i++) p = max(p, cnt[i]);
		for (int i = 0; i < 30; i++) p = Gcd(p, cnt[i]), k += cnt[i];
		if(k == 0)
		{
			for (int i = 1; i <= n; i++) printf("%lld ", i); 
			puts("");
			continue;
		}
		for (int i = 1; i <= p; i++)
			if(p % i == 0) printf("%lld ", i);
		puts("");
	}
	return 0;
}