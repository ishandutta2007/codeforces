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
const int N = 1e5 + 9;
int n, T, ans, res;
signed main()
{
	T = 1;
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read();
		ans = 0;
		ans += (n / 100), n %= 100;
		ans += (n / 20), n %= 20;
		ans += (n / 10), n %= 10;
		ans += (n / 5), n %= 5;
		ans += n, n %= 1;
		cout << ans << endl;
	}
	return 0;
}