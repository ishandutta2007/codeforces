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
int a, b, x, T;
inline bool work(int a, int b)
{
	if(x == a || x == b) return 1;
	if(a == 0 || b == 0) return 0;
	if(x <= a && x % b == a % b) return 1;
	work(b, a % b);
}
inline void solve()
{
	a = read(), b = read(), x = read();
	if(a < b) swap(a, b);
	if(work(a, b)) puts("YES");
	else puts("NO");
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}