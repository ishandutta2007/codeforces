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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 3e5 + 9, INF = 1e9;
int T, n, nxt[N], ans[N], cnt;
vector<int> G[N];
struct point
{
	int a, b, id;
}p[N];
inline bool cmp1(point xxx, point yyy)
{
	return xxx.id - xxx.a < yyy.id - yyy.a;
}
inline bool cmp2(point xxx, point yyy)
{
	return xxx.id < yyy.id;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) p[i].id = i, p[i].a = read(), nxt[i] = -1;
	for (int i = 1; i <= n; i++) p[i].b = read();
	for (int i = 1; i <= n; i++) G[i + p[i].b].push_back(i);
	sort(p + 1, p + n + 1, cmp1);
	int lst = 0, nowlst = 0, now = 1;
	bool flag = 1;
	while(flag)
	{
		flag = 0;
		nowlst = 0;
		while(now <= n && p[now].id - p[now].a <= lst)
		{
			nxt[p[now].id] = lst;
			flag = 1;
			for (auto v : G[p[now].id]) nowlst = max(nowlst, v);
			++now;
		}
		lst = nowlst;
	}
	sort(p + 1, p + n + 1, cmp2);
	if(nxt[n] == -1) 
	{
		puts("-1"); return 0;
	}
	for (int i = nxt[n]; i; i = nxt[i]) ans[++cnt] = i, i += p[i].b;
	cout << cnt + 1 << endl;
	for (int i = 1; i <= cnt; i++) printf("%lld ", ans[i]);
	puts("0");
	return 0;
}