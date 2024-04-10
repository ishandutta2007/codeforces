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
const int N = 1009;
int n;
int cnt[9], ans;
char s[10];
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= 7; j++) cnt[j] += (s[j] - '0');
	}
	for (int i = 1; i <= 7; i++) ans = max(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}