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
const int N = 1e5 + 9, K = 1500000 - 5;
int n, x[N], y[N], nowx, nowy, tim, a[N], p[N], ans[N];
inline int pf(int x)
{
	return x * x;
}
signed main()
{
	srand(time(0));
	n = read();
	for (int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	tim = 0;
	while(1)
	{
		nowx = 0, nowy = 0;
		for (int i = 1; i <= n; i++) a[i] = i;
	    random_shuffle(a + 1, a + n + 1);
		tim++;
		for (int i = 1; i <= n; i++)
		{
			int valx = pf(nowx - x[a[i]]) + pf(nowy - y[a[i]]), valy = pf(nowx + x[a[i]]) + pf(nowy + y[a[i]]);
			if(valx < valy) 
			{
				ans[a[i]] = -1;
				nowx -= x[a[i]], nowy -= y[a[i]];
			}
			else
			{
				ans[a[i]] = 1;
				nowx += x[a[i]], nowy += y[a[i]];
			}
		}
		//cout << nowx << " " << nowy << endl;
		if(pf(nowx) + pf(nowy) <= K * K)
		{
			for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
			return 0;
		}
	}
	return 0;
}