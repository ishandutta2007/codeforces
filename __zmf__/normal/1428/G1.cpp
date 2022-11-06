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
const int N = 1e6 + 9, M = 1e6;
int k, pp, now, v[N], f[N];
signed main()
{
	k = read(); now = 3;//pp = k - 1;
	for (int i = 0; i <= 5; i++) v[i] = read();
	for (int i = 0; i <= M; i++) 
	{
		int cnt = 0, x = i;
		while(x) 
		{
			if((x % 10) % 3 == 0) f[i] += (x % 10) / 3 * v[cnt];
			x /= 10; cnt++;
		}
	}
	for (int i = 0; i <= 5; i++) 
	{
		pp = 3 * (k - 1);
		int w;
		for (int t = 1; t <= pp; t = t * 2) 
		{
			w = t * now;
			for (int j = M; j >= w; j--) f[j] = max(f[j], f[j - w] + t * v[i]); 
			pp -= t;
		}
		w = pp * now;
		for (int j = M; j >= w; j--) f[j] = max(f[j], f[j - w] + pp * v[i]);
		now *= 10;
	}
	int q = read();
	for (int i = 1; i <= q; i++)
	{
		int x = read(); printf("%lld\n", f[x]);
	}
	return 0;
}