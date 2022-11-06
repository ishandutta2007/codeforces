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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 309;
char s[N];
int len, lena, lenb, x, tota, totb;
signed main()
{
	for (int i = 1; i <= 300; i++) putchar('a'); cout << endl;
	lena = read(), lena = 300 - lena;
	if(300 - lena == 0) return 0;
	for (int i = 1; i <= 300; i++) putchar('b'); cout << endl;
	lenb = read(), lenb = 300 - lenb;
	len = lena + lenb;
	if(300 - lenb == 0) return 0;
	for (int i = 1; i <= len - 1; i++)
	{
		for (int j = 1; j <= len; j++)
			if(j != i) putchar('a');
			else putchar('b');
		cout << endl;
		x = read();
		if(x == 0) return 0;
		if(x == lenb - 1) s[i] = 'b', totb++;
		else s[i] = 'a', tota++;
	}
	if(totb != lenb) s[len] = 'b';
	else s[len] = 'a';
	for (int i = 1; i <= len; i++) putchar(s[i]);
	cout << endl;
	return 0;
}