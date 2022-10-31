#include <bits/stdc++.h>
using namespace std;
int n, q, logn;
struct Edge
{
	int to, nxt;
}e[20000000];
int ecnt = 0, head[6000000];
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
int dep[400010], fa[400010];
void dfs(int u)
{
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(v == fa[u])
			continue;
		fa[v] = u, dep[v] = dep[u] + 1;
		dfs(v);
	}
}
int st[400010][25];
inline void stInit()
{
	logn = ceil(log2(n));
	for(int i = 1; i <= n; i++)
		st[i][0] = i;
	for(int i = 1; i <= logn; i++)
		for(int j = 1; j <= n; j++)
			st[j][i] = st[fa[st[j][i - 1]]][i - 1];
}
inline int LCA(int u, int v)
{
	if(dep[u] < dep[v])
		swap(u, v);
	int dt = dep[u] - dep[v];
	for(int i = logn; i >= 0; i--)
		if(dt >= (1 << i))
			dt -= (1 << i), u = fa[st[u][i]];
	for(int i = logn; i >= 0; i--)
		if(st[u][i] != st[v][i])
			u = fa[st[u][i]], v = fa[st[v][i]];
	return u;
}
int ch[400010][2];
int mx, MX;
inline int Hash(int u, int c, bool s) // if c == ch[u][0]: | 0, else : | 1
{
	// return ((u - 1) * 26 + c) << 1 | s;
	if(ch[u][0] == -1)
		ch[u][0] = c;
	else if(ch[u][0] != c && ch[u][1] == -1)
		ch[u][1] = c;
	if(c != ch[u][0] && c != ch[u][1])
		return MX;
	return ((u - 1) << 1 | (c == ch[u][1])) << 1 | s;
}
inline int Hash2(int u, bool s)
{
	return mx + ((u - 1) << 1 | s);
}
inline void SetFalse(int u)
{
	addedge(u, u ^ 1);
}
inline void Link(int u, int v)
{
	addedge(u, v), addedge(v ^ 1, u ^ 1);
}
inline void Equal(int u, int v)
{
	Link(u, v), Link(v, u);
}
char s[400010];
namespace _2SAT
{
	int dfn[6000000], low[6000000], dfn_cnt = 0;
	int scc_num[6000000], scc_cnt = 0;
	bool ins[6000000];
	stack<int> stk;
	vector<int> scc[6000000];
	void dfs(int u)
	{
		dfn[u] = low[u] = ++dfn_cnt;
		stk.push(u), ins[u] = true;
		for(int i = head[u]; i != -1; i = e[i].nxt)
		{
			int v = e[i].to;
			if(!dfn[v])
				dfs(v), low[u] = min(low[u], low[v]);
			if(ins[v])
				low[u] = min(low[u], dfn[v]);
		}
		if(low[u] == dfn[u])
		{
			scc_cnt++;
			int p;
			do
			{
				p = stk.top(), stk.pop(), ins[p] = false;
				scc_num[p] = scc_cnt, scc[scc_cnt].push_back(p);
			} while(p != u);
		}
	}
	vector<int> g[6000000];
	int d[6000000];
	queue<int> q;
	inline bool Solve(bool *ans, int n)
	{
		for(int i = 0; i < n; i++)
			if(!dfn[i])
				dfs(i);
		for(int i = 0; i < n; i += 2)
			if(scc_num[i] == scc_num[i ^ 1])
				return false;
		for(int i = 0; i < n; i++)
			for(int j = head[i]; j != -1; j = e[j].nxt)
			{
				int v = e[j].to;
				if(scc_num[i] != scc_num[v])
				{
					g[scc_num[i]].push_back(scc_num[v]);
					d[scc_num[v]]++;
				}
			}
		for(int i = 1; i <= scc_cnt; i++)
			if(!d[i])
				q.push(i);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(auto x: scc[u])
				if(!ans[x])
					ans[x ^ 1] = true;
			for(auto v: g[u])
				if((--d[v]) == 0)
					q.push(v);
		}
		return true;
	}
}
bool ans[6000000];
int main()
{
	memset(head, -1, sizeof(head)), ecnt = 0;
	scanf("%d %d", &n, &q);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	fa[1] = 1, dep[1] = 0;
	dfs(1), stInit();
	memset(head, -1, sizeof(head)), ecnt = 0;
	mx = n * 2 * 2;
	MX = mx + q * 2; // MX: FALSE, MX + 1: TRUE
	SetFalse(MX);
	memset(ch, -1, sizeof(ch));
	for(int qi = 1; qi <= q; qi++)
	{
		int x, y;
		scanf("%d %d %s", &x, &y, s + 1);
		int len = strlen(s + 1), lca = LCA(x, y), dx = dep[x] - dep[lca], dy = dep[y] - dep[lca];
		vector<int> vec;
		while(x != lca)
			vec.push_back(x), x = fa[x];
		while(y != lca)
			vec.push_back(y), y = fa[y];
		vec.push_back(lca);
		for(int i = 0; i <= (dy >> 1); i++)
			swap(vec[dx + i], vec[dx + dy - i]);
		for(int i = 1; i <= len; i++)
		{
			int u = vec[i - 1];
			if(s[i] == s[len + 1 - i])
			{
				// for(int j = 0; j < 26; j++)
				// 	if(s[i] - 'a' == j)
				// 		SetFalse(Hash(u, j, false));
				// 	else
				// 		SetFalse(Hash(u, j, true));
				Equal(Hash(u, s[i] - 'a', true), MX + 1);
			}
			else
			{
				// for(int j = 0; j < 26; j++)
				// 	if(s[i] - 'a' == j)
				// 	{
				// 		Link(Hash(u, j, true), Hash2(qi, true));
				// 		Link(Hash2(qi, true), Hash(u, j, true));
				// 	}
				// 	else if(s[len + 1 - i] - 'a' == j)
				// 	{
				// 		Link(Hash(u, j, true), Hash2(qi, false));
				// 		Link(Hash2(qi, false), Hash(u, j, true));
				// 	}
				// 	else
				// 		SetFalse(Hash(u, j, true));
				Equal(Hash(u, s[i] - 'a', true), Hash2(qi, true));
				Equal(Hash(u, s[len + 1 - i] - 'a', true), Hash2(qi, false));
			}
		}
	}
	for(int i = 1; i <= n; i++)
		if(ch[i][0] == -1)
			ch[i][0] = 0, ch[i][1] = 1;
		else if(ch[i][1] == -1)
			ch[i][1] = (ch[i][0] + 1) % 26;
	for(int i = 1; i <= n; i++)
		Equal(Hash(i, ch[i][0], true), Hash(i, ch[i][1], false));
	int N = n * 2 * 2 + q * 2 + 2;
	if(!_2SAT :: Solve(ans, N))
		printf("NO\n");
	else
	{
		printf("YES\n");
		// for(int i = 1; i <= n; i++)
		// 	for(int j = 0; j < 26; j++)
		// 		if(ans[Hash(i, j, true)])
		// 		{
		// 			putchar(j + 'a');
		// 			break;
		// 		}
		for(int i = 1; i <= n; i++)
		{
			putchar(ch[i][ans[Hash(i, ch[i][1], true)]] + 'a');
		}
		putchar('\n');
	}
	return 0;
}