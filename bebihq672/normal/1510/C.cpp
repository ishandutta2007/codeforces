#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int N = 100010;
int _w;

int n, m;
set<pii> edge;

namespace G {
	int head[N], nxt[N*4], to[N*4], eid;
	void init() {
		eid = 0;
		for( int i = 1; i <= n; ++i ) head[i] = -1;
	}
	void link( int u, int v ) {
		to[eid] = v, nxt[eid] = head[u], head[u] = eid++;
		to[eid] = u, nxt[eid] = head[v], head[v] = eid++;
	}
}

bool vis[N], stk[N];
int pa[N];

void remove( int u, int v ) {
	if( u > v ) swap(u, v);
	edge.erase( pii(u, v) );
}

void dfs( int u, int fa ) {
	// printf( "u = %d\n", u );
	using namespace G;
	pa[u] = fa, stk[u] = true, vis[u] = true;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( v == fa ) continue;
		if( stk[v] ) {
			remove(u, v);
			for( int o = u; o != v; o = pa[o] ) {
				remove(o, pa[o]);
			}
		} else if( vis[v] == false ) {
			dfs(v, u);
		}
	}
	stk[u] = false;
}

void solve() {
	for( int i = 1; i <= n; ++i )
		vis[i] = stk[i] = false;
	for( int i = 1; i <= n; ++i )
		if( vis[i] == false )
			dfs(i, 0);
}

vector<int> g[N];

struct Edge{
	int u, v;
};

bool visit[101010];
vector<Edge> ans;

int ddfs(int x, int fa)
{
	visit[x] = 1;
	vector<int> sons;
	bool wtf = 0;
	for(int to: g[x])
	if(to != fa)
	{
		int ret = ddfs(to, x);
		if(ret == to && g[x].size() % 2 == 1 && !wtf)
		{
			wtf = 1;
		}
		else
		{
			sons.push_back(ret);
		}
	}
	while(!sons.empty())
	{
		if(sons.size() == 1)
		{
			if(fa == -1)
			{
				ans.push_back({x, sons[0]});
			}
			return sons[0];
		}
		ans.push_back({sons[sons.size() - 1], sons[sons.size() - 2]});
		sons.pop_back();
		sons.pop_back();
	}
	return x;
}

int main() {
	while( scanf( "%d%d", &n, &m ) != -1 ) {
		if( n == 0 && m == 0 ) break;
		G::init();
		edge.clear();
		for( int i = 0; i < m; ++i ) {
			int si;
			_w = scanf( "%d", &si );
			int last = -1;
			while( si-- ) {
				int now;
				_w = scanf( "%d", &now );
				if( last != -1 ) {
					G::link(last, now);
					int u = last;
					int v = now;
					if( u > v ) swap(u, v);
					edge.insert( pii(u, v) );
				}
				last = now;
			}
		}
		solve();
		for( int i = 1; i <= n; ++i )
			g[i].clear();
		for( pii e : edge ) {
			g[e.first].push_back( e.second );
			g[e.second].push_back( e.first );
		}

		// TODO
		
		ans.clear();
		
		// cerr << "wtf" << endl;
		
		for(int i = 0; i <= n; i++)
			visit[i] = 0;
		
		for(int i = 1; i <= n; i++)
		if(visit[i] == 0)
		{
			ddfs(i, -1);
		}
		
		printf( "%d\n", (int)ans.size() );
		for( Edge e : ans )
			printf( "%d %d\n", e.u, e.v );
	}
	return 0;
}