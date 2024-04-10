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
const int N = 1e5 + 9, M = 1e5, mod = 998244353;
int sum0[N], sum1[N], sum2[N], n, f[N];
inline void add(int &x, int y) {x = (x + y) % mod;}
inline int pown(int x, int y) 
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
inline int Pow(int x, int y) 
{
	if(y == -1) return pown(x, mod - 2);
 	else return pown(x, y);
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		int x = read(), y = read();
		sum0[x] = y; 
		sum1[x] = x * y % mod;
		sum2[x] = x * x % mod * y % mod;
	}
	for (int i = 1; i <= M; i++) 
		for (int j = i * 2; j <= M; j += i)
			sum0[i] += sum0[j], add(sum1[i], sum1[j]), add(sum2[i], sum2[j]);
	for (int i = 1; i <= M; i++) 
	{
	//	int now = 0;
		int s0 = sum2[i], s1 = (sum1[i] * sum1[i] - sum2[i] + mod) % mod, t = sum0[i] % mod;
		if(sum0[i] < 2) continue;
	//	cout << sum0[i] << endl;
		add(f[i], s1 * Pow(2, sum0[i] - 3) % mod * t % mod);
	//	cout << f[i] << endl;
		add(f[i], s0 * Pow(2, sum0[i] - 2) % mod * (t - 1 + mod) % mod);
	//	cout << f[i] << endl;
	}
	for (int i = M; i >= 1; i--)
		for (int j = i * 2; j <= M; j += i)
			f[i] = (f[i] - f[j] + mod) % mod;
	cout << (f[1] % mod + mod) % mod << endl;
	return 0;
}