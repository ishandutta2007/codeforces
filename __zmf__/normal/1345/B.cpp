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
const int N = 1e5 + 9, P = 4e4;
int n, m, T, val[N];
signed main()
{
	T = read();
	for (int i = 1; i <= P; i++) val[i] = val[i - 1] + i - 1 + 2 * i;
	for (int ttt = 1; ttt <= T; ttt++)
	{
		int n = read(), cnt = 0;
		for (int i = P; i >= 1; i--) cnt += (n / val[i]), n %= val[i];
		cout << cnt << endl;
	}
	return 0;
}