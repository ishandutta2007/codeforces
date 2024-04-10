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
const int mod = 998244353, N = 5009;
int T, n, a[N], head, tail, dp[N], lst[N], jc[N], inv[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline int C(int x, int y) {return jc[x] * inv[y] % mod * inv[x - y] % mod;}
inline void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	jc[0] = 1;
	for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
	inv[n] = Pow(jc[n], mod - 2);
	for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	head = tail = n;
	lst[0] = 1;
	while(head != 0) 
	{
		while(a[head] == a[tail]) head--;
		int pep = tail - head;
		for (int i = 0; i <= n; i++) dp[i] = 0;
		for (int i = pep + 1; i <= n; i++) dp[i - pep] = lst[i] * C(i - 1, pep);
		pep--;
		if(pep != 0) 
			for (int i = pep + 1; i <= n; i++) dp[i - pep + 1] = (dp[i - pep + 1] + lst[i] * C(i - 1, pep)) % mod;
		else 
			for (int i = 0; i <= n; i++) dp[i + 1] = (dp[i + 1] + lst[i]) % mod;
		pep = n - head;
		dp[n - pep + 1] = (dp[n - pep + 1] + dp[n - pep]) % mod, dp[n - pep] = 0;
		for (int i = 0; i <= n; i++) lst[i] = dp[i];
		tail = head;
	//	for (int i = 0; i <= n; i++) cout << lst[i] << " "; cout << endl;
	}
	cout << dp[1] << endl;
	memset(lst, 0, sizeof(lst));
	memset(dp, 0, sizeof(dp));
	return ;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}