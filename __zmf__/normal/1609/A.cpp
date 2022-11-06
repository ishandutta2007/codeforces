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
const int N = 1e5 + 9;
int T, a[N], n;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		int res = 0, cnt = 0, ans = 0;
		for (int i = 1; i <= n; i++) a[i] = read(), res += a[i];
		for (int i = 1; i <= n; i++)
		{
			cnt = 0; 
			int now = res;
			for (int j = 1; j <= n; j++) 
				if(i != j) 
				{
					int qwq = a[j];
					while(qwq % 2 == 0) 
						qwq /= 2, now -= qwq, cnt++;
				}
			for (int j = 1; j <= cnt; j++) now += a[i], a[i] *= 2;
			for (int j = 1; j <= cnt; j++) a[i] /= 2;
			ans = max(ans, now);
		}
		printf("%lld\n", ans);
	}
	return 0;
}