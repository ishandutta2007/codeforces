/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
*/

//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e6 + 9;
int n, pt = 1, lst = 1;
char s[N], t[N];
struct SAM
{
	int nxt[28];
	int cnt, link, len;
}tree[N << 1];
vector<int> G[N << 1];
inline void add(int c) 
{
	int now = ++pt; tree[now].len = tree[lst].len + 1;
	for (;lst && !tree[lst].nxt[c]; lst = tree[lst].link) tree[lst].nxt[c] = now;
	if(!lst) tree[now].link = 1;
	else 
	{
		int q = tree[lst].nxt[c];
		if(tree[q].len == tree[lst].len + 1) tree[now].link = q;
		else 
		{
			int cl = ++pt; 
			tree[cl] = tree[q]; tree[cl].len = tree[lst].len + 1; tree[cl].cnt = 0;
			for (;lst && tree[lst].nxt[c] == q; lst = tree[lst].link) tree[lst].nxt[c] = cl;
			tree[q].link = tree[now].link = cl;
		}
	}
	lst = now; tree[now].cnt = 1; return ;
}
inline void dfs(int u) 
{
	for (auto v : G[u])  
	{
		dfs(v); 
		tree[u].cnt += tree[v].cnt; 
	}
	return ;
}
inline bool check(int x, int y) 
{
	if(x % y != 0) return 0;
	for (int i = 1; i < x / y; i++) 
		for (int j = 1; j <= y; j++) 
			if(t[j + y * i] != t[j]) return 0;
	return 1;
}
inline void work()
{
	scanf("%s", t + 1); 
	int len = strlen(t + 1), now = 1, ans = 0, l = 0;
	int qwq = len;
	for (int i = 1; i <= len; i++) 
		if(check(len, i)) 
		{
			qwq = i; break;
		} 
	for (int i = 1; i <= len - 1 + qwq; i++) 
	{
		int nc;
		bool flag = 0;
		if(i <= len) nc = t[i] - 'a' + 1;
		else nc = t[i - len] - 'a' + 1;
		while(!tree[now].nxt[nc] && now != 1) now = tree[now].link;
		while(tree[tree[now].link].len >= len - 1 && now != 1) now = tree[now].link;
		l = min(tree[now].len, l);
		//if(tree[now].len >= len - 1 && tree[now].nxt[nc]) flag = 1; 
		if(tree[now].nxt[nc]) now = tree[now].nxt[nc], l++; 
		if(l >= len) ans += tree[now].cnt;
	//	if(flag) cout << i << " " << tree[now].cnt << endl;
	} 
	printf("%d\n", ans);
}
signed main()
{
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) add(s[i] - 'a' + 1);
	for (int i = 1; i <= pt; i++) G[tree[i].link].push_back(i); 
	//for (int i = 1; i <= pt; i++) cout << tree[i].cnt << " "; cout << endl;
	dfs(1);
//	for (int i = 1; i <= pt; i++) cout << tree[i].cnt << endl;
	int TT = read();
	for (int i = 1; i <= TT; i++) work();
	return 0;
}