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
int n, ans;
struct Tree
{
	int c[N << 1];
	inline int lowbit(int x) {return x & (-x);}
	inline void Clear()
	{
		for (int i = 1; i <= n; i++) c[i] = 0;
	}
	inline void update(int x)
	{
		while(x <= n) c[x]++, x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x) res += c[x], x -= lowbit(x);
		return res;
	}
}c;
char s[N], t[N];
vector<int> pos[28];
int nowpos[28], now, cnt1, cnt2;
inline void solve()
{
	n = read(); ans = 1e18, now = 0;
	scanf("%s", s + 1); scanf("%s", t + 1);
	for (int i = 1; i <= 26; i++) pos[i].clear(), nowpos[i] = 0; 
	c.Clear();
	for (int i = 1; i <= n; i++) pos[s[i] - 'a' + 1].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t[i] - 'a'; j++) 
			if(nowpos[j] < pos[j].size()) 
			{
				int pp = pos[j][nowpos[j]], res = 0; res = pp - 1 - c.query(pp);
				ans = min(ans, now + res); 
			}
		int ch = t[i] - 'a' + 1;
		if(nowpos[ch] >= pos[ch].size()) break;
		int pp = pos[ch][nowpos[ch]]; nowpos[ch]++;
		now += pp - 1 - c.query(pp); c.update(pp);
	} 
	if(ans == 1e18) puts("-1");
	else printf("%lld\n", ans);
	return ;
}
signed main()
{
	int T = read();
	for (int ttt = 1; ttt <= T; ttt++) solve();
	return 0;
}