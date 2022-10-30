#include <bits/stdc++.h>
using namespace std;
struct Edge
{
	int to, nxt;
}e[600010];
int head[300010], ecnt = 0;
inline void addedge(int from, int to)
{
	e[ecnt].to = to;
	e[ecnt].nxt = head[from];
	head[from] = ecnt++;
}
vector<int> g[300010];
vector< pair<int, int> > vec;
int cnt[300010];
int fa[300010];
void DFS(int u)
{
	for(int i = head[u]; i != -1; i = e[i].nxt)
	{
		int v = e[i].to;
		if(fa[v])
			continue;
		g[u].push_back(v);
		g[v].push_back(u);
		fa[v] = u;
		DFS(v);
	}
}
int GOAL;
void dfs(int u, bool flag)
{
	if(u == GOAL)
		flag = true;
	if(flag)
		return;
	for(auto v: g[u])
	{
		if(fa[v])
			continue;
		fa[v] = u;
		dfs(v, flag);
	}
}
namespace FastIO {
    const int SIZE=1<<16; char buf[SIZE], obuf[SIZE], str[64]; int bi=SIZE, bn=SIZE, opt;
    int read(char *s) {
        while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
        int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
    }
    bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n)return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
    void write(int x) {
        if(!x) obuf[opt++] = '0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
        if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}
    }
    void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf, 1, opt, stdout); opt=0;}}
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt=0;}
};
#define read(x) FastIO :: read(x)
#define write(x) FastIO :: write(x)
int main()
{
	memset(head, -1, sizeof(head));
	int n, m;
	read(n), read(m);
	while(m--)
	{
		int u, v;
		read(u), read(v);
		addedge(u, v);
		addedge(v, u);
	}
	int q;
	read(q);
	while(q--)
	{
		int u, v;
		read(u), read(v);
		vec.push_back({u, v});
		cnt[u]++, cnt[v]++;
	}
	int tot = 0;
	for(int i = 1; i <= n; i++)
		tot += (cnt[i] & 1);
	if(tot)
	{
		printf("NO\n");
		write(tot >> 1);
		FastIO :: Fflush();
		return 0;
	}
	fa[1] = 1;
	DFS(1);
	printf("YES\n");
	for(auto p: vec)
	{
		for(int i = 1; i <= n; i++)
			fa[i] = 0;
		int u = p.first, v = p.second;
		fa[u] = u;
		GOAL = v;
		dfs(u, false);
		stack<int> ans;
		while(v != u)
		{
			ans.push(v);
			v = fa[v];
		}
		ans.push(u);
		write(int(ans.size()));
		write('\n');
		while(!ans.empty())
			write(ans.top()), write(' '), ans.pop();
		write('\n');
	}
	FastIO :: Fflush();
	return 0;
}