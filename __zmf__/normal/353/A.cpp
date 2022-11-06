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
int n, sum1, sum2, flag;
signed main()
{ 
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		int x = read(), y = read();
		sum1 += x, sum2 += y;
		if((x + y) % 2 == 1) flag = 1;
	}
	if((sum1 + sum2) % 2 != 0) puts("-1");
	else if(sum1 % 2 == 1 && flag == 0) puts("-1");
	else cout << sum1 % 2 << endl;
	return 0;
}