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
const int N = 4e5 + 9, mod = 1e9 + 7;
int p[8], n, jp[N], inv[N], lenl, lenr, k[8];
char l[N], r[N];
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
inline void init()
{
	jp[0] = 1;
	for (int i = 1; i <= n + 1; i++) jp[i] = jp[i - 1] * i % mod;
	inv[n + 1] = Pow(jp[n + 1], mod - 2);
	for (int i = n; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
	return ;
}
inline int C(int x, int y) 
{
	if(x == -1 && y == -1) return 1;
	if(y == -1) return 0;
	return jp[x] * inv[y] % mod * inv[x - y] % mod;
}
inline int get(int x, int a, int b, int c, int d)
{
	if(a < 0 || b < 0 || c < 0 || d < 0) return 0;
	if(abs(b - c) > 1) return 0;
	if(!x && c > b) return 0;
	if(x && b > c) return 0;
	int cnt0, cnt1, len = b + c + 1;
	if(x == 0) cnt0 = len - len / 2, cnt1 = len / 2;
	else cnt0 = len / 2, cnt1 = len - len / 2;
	return C(d + cnt1 - 1, cnt1 - 1) * C(a + cnt0 - 1, cnt0 - 1) % mod;
}
inline int work(char s[], int len, int flag)
{
	if(len < n) return 0;
	if(len > n) return get(1, p[0], p[1], p[2], p[3]);
	int res = 0;
	for (int i = 0; i < 4; i++) k[i] = p[i]; 
	for (int i = 2; i <= len; i++)
	{
		if(s[i] == '1') 
		{
			if(s[i - 1] == '0') res = (res + get(0, k[0] - 1, k[1], k[2], k[3])) % mod; 
			else res = (res + get(0, k[0], k[1], k[2] - 1, k[3])) % mod;
		}
		int x = (s[i] - '0') + (s[i - 1] - '0') * 2;
		k[x]--;
	}
	if(k[0] == 0 && k[1] == 0 && k[2] == 0 && k[3] == 0 && flag) res = (res + 1) % mod;
	return res;
}
signed main()
{
	scanf("%s", l + 1);
	scanf("%s", r + 1);
	for (int i = 0; i < 4; i++) p[i] = read(), n += p[i]; ++n; init();
	lenl = strlen(l + 1); lenr = strlen(r + 1);
	printf("%lld\n", (work(r, lenr, 1) - work(l, lenl, 0) + mod) % mod);
	return 0;
}