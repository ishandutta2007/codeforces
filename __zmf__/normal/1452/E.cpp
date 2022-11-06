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
const int N = 4009;
int n, m, k, ans, now;
int l[N], r[N], b[N]; 
signed main()
{
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) l[i] = read(), r[i] = read();
	for (int i = 1; i + k - 1 <= n; i++) 
	{
		memset(b, 0, sizeof(b));
		now = 0;
		for (int j = 1; j <= m; j++) now += max(0ll, min(r[j], i + k - 1) - max(l[j], i) + 1);
		for (int j = 1; j <= m; j++) 
			if(l[j] > i && r[j] > i + k - 1) 
			{
				if(i + k - 1 >= l[j]) 
				{
					int len = min(l[j] - i, r[j] - (i + k - 1)), end = max(l[j] - i, r[j] - (i + k - 1));
					b[i + 1]++; b[i + 1 + len]--;
					b[i + end + 1]--, b[i + 1 + len + end]++;
				}
				else 
				{
					b[l[j] - k + 1]++, b[(r[j] + 1) - k + 1]--;
					b[l[j] + 1]--; b[r[j] + 2]++;
				}
			}
		for (int j = i + 1; j <= n; j++) b[j] += b[j - 1];
		for (int j = i + 1; j <= n; j++) b[j] += b[j - 1];
		for (int j = i; j <= n; j++) ans = max(ans, now + b[j]);
	//	cout << i << " " << now << "------------------" << endl;
	//	for (int j = i; j <= n; j++) cout << b[j] << " "; cout << endl;
	}
	cout << ans << endl;
	return 0;
}