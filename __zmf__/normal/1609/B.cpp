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
int n, q, ans;
char s[N], opt[5];
inline bool check(int x)
{
	if(x <= 0) return 0;
	if(s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c') return 1;
	return 0;
}
signed main()
{
	n = read(), q = read();
	scanf("%s", s + 1);
	for (int i = 1; i < n - 1; i++) 
		if(check(i)) ans++;
	for (int i = 1; i <= q; i++)
	{
		int pos = read();
		scanf("%s", opt + 1);
		if(check(pos - 2)) ans--;
		if(check(pos - 1)) ans--;
		if(check(pos)) ans--;
		s[pos] = opt[1];
		if(check(pos - 2)) ans++;
		if(check(pos - 1)) ans++;
		if(check(pos)) ans++;
		printf("%lld\n", ans);
	}
	return 0;
}