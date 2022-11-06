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
char s[9];
int a[9], len;
signed main()
{
	scanf("%s", s + 1); len = strlen(s + 1);
	for (int i = 1; i <= len; i++) a[i] = s[i] - 'a' + 1;
	if(len == 7) 
	{
		a[1] += 'v' - 'a' + 1;
		a[2] += 'a' - 'a' + 1;
		a[3] += 'm' - 'a' + 1;
		a[4] += 'p' - 'a' + 1;
		a[5] += 'i' - 'a' + 1;
		a[6] += 'r' - 'a' + 1;
		a[7] += 'e' - 'a' + 1;
	}
	else if(len == 6) 
	{
		a[1] += 's' - 'a' + 1;
		a[2] += 'l' - 'a' + 1;
		a[3] += 'a' - 'a' + 1;
		a[4] += 'y' - 'a' + 1;
		a[5] += 'e' - 'a' + 1;
		a[6] += 'r' - 'a' + 1;
	}
	else if(len == 5) 
	{
		a[1] += 'b' - 'a' + 1;
		a[2] += 'u' - 'a' + 1;
		a[3] += 'f' - 'a' + 1;
		a[4] += 'f' - 'a' + 1;
		a[5] += 'y' - 'a' + 1;
	}
	else if(len == 4) 
	{
		puts("none"); return 0;
	}
	else
	{
		a[1] += 't' - 'a' + 1;
		a[2] += 'h' - 'a' + 1;
		a[3] += 'e' - 'a' + 1;
	}
	for (int i = 1; i <= len; i++) cout << (char)((a[i] + 24) % 26 + 'a');
	return 0;
}