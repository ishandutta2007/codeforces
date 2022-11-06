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
const int N = 2e5 + 9, P = 4e4;
map<int, int> mp;
int n, a[N];
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		bool flag = 0;
		mp.clear();
		n = read();
		for (int i = 0; i < n; i++) a[i] = read();
		for (int i = 0; i < n; i++)
		{
			int v = ((i + a[i]) % n + n) % n;
			if(mp[v])
			{
				flag = 1;
				puts("NO"); break;
			}
			mp[v] = 1;
		}
		if(!flag) puts("YES");
	}
	return 0;
}