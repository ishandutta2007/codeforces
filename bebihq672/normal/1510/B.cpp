#include <bits/stdc++.h>

using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 2010;
int _w;

namespace MCMF {
	const int MAXN = 100010;
	const int MAXM = 1000010;
	
	struct Edge {
		int u, v, c, f, w;
	};

	int n, m, s, t;
	int head[MAXN], nxt[MAXM];
	Edge edge[MAXM];

	void init( int _n ) {
		n = _n, m = 0;
		for( int i = 0; i < n; ++i )
			head[i] = -1;
	}
	int adde( int u, int v, int c, int w ) {
		int e = m;
		edge[m] = (Edge){u, v, c, 0, w};
		nxt[m] = head[u], head[u] = m++;
		edge[m] = (Edge){v, u, 0, 0, -w};
		nxt[m] = head[v], head[v] = m++;
		return e;
	}

	int res[MAXN], from[MAXN];
	int dis[MAXN];
	bool inq[MAXN];
	queue<int> q;

	bool spfa() {
		for( int i = 0; i < n; ++i )
			dis[i] = INF;
		dis[s] = 0, inq[s] = 1, q.push(s), res[s] = INF;
		while( !q.empty() ) {
			int u = q.front(); q.pop();
			inq[u] = 0;
			for( int i = head[u]; ~i; i = nxt[i] ) {
				Edge &e = edge[i];
				if( e.c > e.f && dis[u] + e.w < dis[e.v] ) {
					dis[e.v] = dis[u] + e.w;
					res[e.v] = min( res[u], e.c-e.f );
					from[e.v] = i;
					if( !inq[e.v] )
						inq[e.v] = 1, q.push(e.v);
				}
			}
		}
		return dis[t] != INF;
	}
	void augment() {
		int u = t, f = res[t];
		while( u != s ) {
			int i = from[u];
			edge[i].f += f;
			edge[i^1].f -= f;
			u = edge[i].u;
		}
	}
	int solve( int _s, int _t ) {
		s = _s, t = _t;
		int flow = 0, cost = 0;
		while( spfa() ) {
			flow += res[t];
			cost += res[t] * dis[t];
			augment();
		}
		return cost;
	}
}

int S, T, SS, TT, in[N], out[N], nid, g[N][N];

int add_edge( int u, int v, int l, int r, int w ) {
	int e = MCMF::adde(u, v, r-l, w);
	if( l ) {
		MCMF::adde(SS, v, l, 0);
		MCMF::adde(u, TT, l, 0);
	}
	return e;
}

int d, n, key[N];
vector<int> ans[N];

int input_pw() {
	static char str[N];
	_w = scanf( "%s", str );
	int len = (int)strlen(str);
	reverse(str, str+len);
	int x = 0;
	for( char *p = str; *p; p++ )
		x = (x << 1) | (*p - '0');
	return x;
}

int main() {
	_w = scanf( "%d%d", &d, &n );
	memset(key, 0, sizeof key);
	for( int i = 1; i <= n; ++i ) {
		int x = input_pw();
		key[x] = 1;
	}
	nid = 0;
	S = nid++;
	T = nid++;
	SS = nid++;
	TT = nid++;
	for( int i = 0; i < (1<<d); ++i )
		in[i] = nid++, out[i] = nid++;
	MCMF::init(nid);
	for( int i = 0; i < (1<<d); ++i ) {
		if( key[i] ) {
			add_edge( in[i], out[i], 1, INF, 0 );
		} else {
			add_edge( in[i], out[i], 0, INF, 0 );
		}
		add_edge( out[i], T, 0, INF, 0 );
	}
	add_edge(T, S, 0, INF, 0);
	add_edge(S, in[0], 0, INF, 1);
	memset(g, -1, sizeof g);
	for( int i = 0; i < (1<<d); ++i ) {
		for( int j = 0; j < d; ++j ) {
			int ni = i | (1<<j);
			if( i == ni ) continue;
			g[i][j] = add_edge( out[i], in[ni], 0, INF, 1 );
		}
	}
	printf( "%d\n", MCMF::solve(SS, TT) - 1 );
	for( int i = 0; i < (1<<d); ++i )
		for( int j = 0; j < d; ++j )
			if( g[i][j] != -1 ) {
				int eid = g[i][j];
				int cnt = MCMF::edge[eid].f;
				while( cnt-- )
					ans[i].push_back(j);
			}
	bool first = true;
	bool first_path = true;
	while( ans[0].size() ) {
		int u = 0;
		if( first_path ) {
			first_path = false;
		} else {
			printf(" R");
		}
		while( ans[u].size() ) {
			int bit = ans[u].back();
			ans[u].pop_back();
			if( first ) {
				first = false;
			} else {
				putchar(' ');
			}
			printf( "%d", bit );
			u |= 1<<bit;
		}
	}
	puts("");
	return 0;
}