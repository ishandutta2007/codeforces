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
int n, flag, k, sum;
map<int, int> mp;
signed main()
{
	n = read(); k = read();
	for (int i = 1; i <= k; i++)
	{
		int a = read(), b = read();
		sum += b; flag += a * b;
	} 
	flag %= n;
	if(sum > n || (sum == n && flag != (n * (n + 1) / 2) % n)) puts("-1");
	else puts("1");
	return 0;
}