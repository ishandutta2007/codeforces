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
const int N = 3e5 + 9;
int n, k;
int a[N];
map<int, int> mp;
map<int, int> id;
inline int lowbit(int x) {return x & (-x);}
inline int get(int x)
{
	int res = 0;
	while(x) res = lowbit(x), x -= res;
	return res;
}
int ch[N * 31][2], cnt, vis[N];
inline void Insert(int x) 
{
	int now = 0;
	for (int i = 31; i >= 0; i--)
	{
		int u = ((x >> i) & 1);
		if(!ch[now][u]) ch[now][u] = ++cnt;
		now = ch[now][u];
	}
}
inline int query(int x)
{
	int res = 0, now = 0;
	for (int i = 31; i >= 0; i--) 
	{
		int u = ((x >> i) & 1); u ^= 1;
		if(ch[now][u]) res += (1 << i), now = ch[now][u];
		else now = ch[now][!u];
	}
	return res;
}
inline void Clear()
{
	for (int i = 0; i <= cnt; i++) ch[i][0] = ch[i][1] = 0; cnt = 0;
	return ;
}
inline void solve(int l, int r)
{
	if(l > r) return ;
	int t = get(k), R = l, L = l;
	while(R <= r && get(a[R]) <= t) ++R;
	int nowl = R, nowr = R;
	while(nowl <= r) 
	{
		while(nowr <= r && get(a[nowr]) == get(a[nowl])) nowr++;
		--nowr; 
		for (int i = nowl; i <= nowr; i++) a[i] -= get(a[nowr]);
	//	if(l == 1 && r == n) cout << nowl << " " << nowr << endl;
		solve(nowl, nowr);
		nowl = nowr + 1; nowr = nowl;
	}
	--R; if(L > R) return ; mp.clear();
	for (int i = L; i <= R; i++) mp[a[i]] = i;
	int flag = 0;
	for (int i = L; i <= R; i++) 
	{
		int p = query(a[i]);
		Insert(a[i]);
		if(p >= k) 
		{
			int r = (p ^ a[i]);
			vis[i] = 1; vis[mp[r]] = 1; flag = 1; break;
		}
	}
	if(!flag) vis[L] = 1;
	Clear();
}
int to[N];
signed main()
{
	n = read(), k = read(); 
	for (int i = 1; i <= n; i++) a[i] = read(), id[a[i]] = i;
	if(k == 0)
	{
		cout << n << endl;
		for (int i = 1; i <= n; i++) printf("%lld ", i);
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) to[i] = id[a[i]];
	solve(1, n);
	cnt = 0;
	for (int i = 1; i <= n; i++) cnt += vis[i];
	if(cnt <= 1) 
	{
		puts("-1"); return 0;
	}
	else
	{
		cout << cnt << endl;
		for (int i = 1; i <= n; i++)
			if(vis[i]) printf("%lld ", to[i]);
	}
	return 0;
}