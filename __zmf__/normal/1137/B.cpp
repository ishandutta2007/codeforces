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
const int N = 5e5 + 9, mod = 1e9 + 7;
int n, m;
int cntn[5], cntm[5], qwq[5], ans[N], now;
int Hash[N], pown[N];
char s[N], t[N];
inline int getHash(int l, int r)
{
	return (Hash[r] - Hash[l - 1] * pown[r - l + 1] % mod + mod) % mod;
}
signed main()
{
	scanf("%s", s + 1); scanf("%s", t + 1); n = strlen(s + 1), m = strlen(t + 1);
	int len = m;
	for (int i = 1; i <= n; i++) cntn[s[i] - '0']++;
	for (int i = 1; i <= m; i++) cntm[t[i] - '0']++;
	for (int i = 1; i <= m; i++) Hash[i] = (Hash[i - 1] * 23 + t[i] - '0') % mod;
	pown[0] = 1;
	for (int i = 1; i <= m; i++) pown[i] = pown[i - 1] * 23 % mod;
	for (int i = 1; i < m; i++)
		if(getHash(1, i) == getHash(m - i + 1, m)) 
			len = m - i; 
//	cout << len << endl;
	for (int i = m - len + 1; i <= m; i++) qwq[t[i] - '0']++;
	if(cntn[0] < cntm[0] || cntn[1] < cntm[1]) 
	{
		for (int i = 1; i <= n; i++) putchar(s[i]); puts("");
		return 0;
	}
	cntn[0] -= cntm[0], cntn[1] -= cntm[1];
	for (int i = 1; i <= m; i++) putchar(t[i]);
//	cout << cntn[0] << " " << cntn[1] << endl;
	while(cntn[0] >= qwq[0] && cntn[1] >= qwq[1])
	{
		for (int i = m - len + 1; i <= m; i++) putchar(t[i]);
		cntn[0] -= qwq[0], cntn[1] -= qwq[1];
	}
	for (int i = 1; i <= cntn[0]; i++) putchar('0');
	for (int i = 1; i <= cntn[1]; i++) putchar('1');
	return 0;
}