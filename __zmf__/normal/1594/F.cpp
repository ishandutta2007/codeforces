/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int __int128
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
int n,s,k;
inline void work() {
	s=read(); n=read(); k=read();
	if((s>=(n/k)*k+n||k>s)&&k!=s) puts("NO");
	else puts("YES");
	
}
signed main()
{
 	int T=read();
 	while(T--) work();
	return 0;
}