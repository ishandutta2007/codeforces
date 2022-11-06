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
const int N = 1e6 + 9, mod = 1e9 + 7;
int n, p[N], ans, r;
inline void work()
{
	int res = 1, now = 0;
	for (int i = 0; i < r; i++)
	{
		int pep = n / p[i] - n / p[i + 1];
		res = res * pep % mod;
		pep--;
		for (int j = 1; j <= pep; j++) res = res * (now + j) % mod; 
		now = (now + pep + 1);
	}
	ans = (ans + res) % mod;
}
signed main()
{
	n = read();
	p[0] = 1;
	while(p[r] * 2 <= n) p[++r] = p[r - 1] * 2;
	work();
	if(p[r] * 3 / 2 > n) 
	{
		cout << ans << endl;
		return 0;
	}
	for (int i = r; i >= 1; i--) 
	{
		p[i] /= 2; p[i] *= 3;
		work();
	}
	cout << ans << endl;
	return 0;
}