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
const int N = 1e6 + 9;
char a[N];
int nxt[N], j, len;
signed main()
{
	scanf("%s", a + 1);
	len = strlen(a + 1); j = 0;
	for (int i = 2; i <= len; i++)
	{
		while(j && a[j + 1] != a[i]) j = nxt[j];
		if(a[j + 1] == a[i]) j++; 
		nxt[i] = j;
	}
	int k = nxt[len], Max = 0;
	for (int i = 2; i <= len - 1; i++) Max = max(Max, nxt[i]);
	while(Max < k) k = nxt[k];
	if(!k) puts("Just a legend");
	else for (int i = 1; i <= k; i++) putchar(a[i]); 
	return 0;
}