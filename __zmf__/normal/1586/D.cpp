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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 109;
int T, n, m, p[N];
signed main() 
{	
	n = read();
	for (int i = 1; i <= n - 1; i++)
	{
		printf("? ");
		for (int j = 1; j <= n - 1; j++) printf("1 ");
		printf("%lld\n", i + 1);
		fflush(stdout);
		int k = read();
		if(k == 0) 
		{
			p[n] = n - i + 1;
			break;
		} 
	}
	if(!p[n]) p[n] = 1;
	for (int i = 1; i <= n; i++)
		if(i != p[n])
		{
			int x = 1, y = 1;
			if(i > p[n]) y += (i - p[n]);
			else x += (p[n] - i);
			printf("?");
			for (int j = 1; j < n; j++) printf(" %lld", x);
			printf(" %lld\n", y);
			fflush(stdout);
			int k;
			scanf("%lld", &k);
			p[k] = i;
		}
	printf("! ");
	for (int i = 1; i <= n; i++) printf("%lld ", p[i]);
	puts("");
	fflush(stdout);
	return 0;
}