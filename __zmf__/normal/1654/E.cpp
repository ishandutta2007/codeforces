/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 1e5 + 9, M = 1e5;
int a[N], B, b[N], ans, now, n, res[N << 1];
signed main()
{
	n = read(); ans = 1; B = sqrt(n);
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 0; i <= 109; i++)
	{
		for (int j = 1; j <= n; j++) b[j] = a[j] - i * j;
		sort(b + 1, b + n + 1);
		now = 1;
		for (int j = 2; j <= n; j++) 
			if(b[j - 1] == b[j]) now++;
			else ans = max(ans, now), now = 1;
		ans = max(ans, now);
		for (int j = 1; j <= n; j++) b[j] = a[j] + i * j;
		sort(b + 1, b + n + 1);
		now = 1;
		for (int j = 2; j <= n; j++) 
			if(b[j - 1] == b[j]) now++;
			else ans = max(ans, now), now = 1;
		ans = max(ans, now);
	}
	int w;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= i + 1000 + 1 && j <= n; j++)
		{
			int t = a[i] - a[j]; w = t / (j - i);
			if(w * (j - i) == t) res[w + M]++, ans = max(ans, res[w + M] + 1);
		}
		for (int j = i + 1; j <= i + 1000 + 1 && j <= n; j++)
		{
			int t = a[i] - a[j]; w = t / (j - i);
			if(w * (j - i) == t) res[w + M]--;
		}
	}
	cout << n - ans << endl;
	return 0;
}