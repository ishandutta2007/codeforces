#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 207;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

namespace Dinic{
	#define sz(x) (int)(x).size()
    // indeksowany od 1
    // uzupeniamy [n, s, t] i dodajemy krawedzie
    typedef int T;
    const int N = 2005;
    const T INF = 1e9;
    
    struct edge {
        int a, b;
        T cap, flow;
    };
    
    int n, s, t, d[N], ptr[N], q[N];
    vector < edge > e;
    vector < int > g[N];
    
    void clear(){
    	e.clear();
    	for(int i = 1; i <= n; ++i)
    		g[i].clear();
    }
    
    int add_edge(int a, int b, T cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, cap, cap };
        g[a].push_back(sz(e));
        e.push_back(e1);
        g[b].push_back(sz(e));
        e.push_back(e2);
        return sz(e) - 2;
    }
    
    bool bfs() {
        int qh = 0, qt = 0;
        q[qt++] = s;
        memset(d + 1, -1, n * sizeof d[0]);
        d[s] = 0;
        while(qh < qt && d[t] == -1) {
            int v = q[qh++];
            for(int i = 0; i < sz(g[v]); ++i) {
                int id = g[v][i], to = e[id].b;
                if(d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }
    
    T dfs(int v, T flow) {
        if(flow <= 0)  return 0;
        if(v == t)  return flow;
        T res = 0;
        for(; ptr[v]<sz(g[v]); ++ptr[v]) {
            int id = g[v][ptr[v]], to = e[id].b;
            if(d[to] != d[v] + 1) continue;
            T pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            res += pushed;
            flow -= pushed;
            if(flow == 0) break;
        }
        return res;
    }
    
    T dinic(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        T flow = 0;
        for (;;) {
            if(!bfs())  break;
            memset(ptr, 0, (n + 1) * sizeof ptr[0]);
            flow += dfs(s, INF);
        }
        return flow;
    }
}

int n, m;
pair <PII, PII> in[N];

int nx, ny;
PII Ix[N], Iy[N];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i)
		scanf("%d %d %d %d", &in[i].st.st, &in[i].st.nd, &in[i].nd.st, &in[i].nd.nd);
	
	vector <int> xs = {n + 1}, ys = {n + 1};
	for(int i = 1; i <= m; ++i){
		xs.push_back(in[i].st.st);
		xs.push_back(in[i].nd.st + 1);

		ys.push_back(in[i].st.nd);
		ys.push_back(in[i].nd.nd + 1);
	}
	
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());

	int prv = 1;
	for(auto cx: xs){
		if(prv < cx)
			Ix[++nx] = {prv, cx - 1};
		prv = cx;
	}
	
	for(auto cy: ys){
		if(prv < cy)
			Iy[++ny] = {prv, cy - 1};
		prv = cy;
	}
	
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= nx; ++j)
			if(in[i].st.st <= Ix[j].st && Ix[j].nd <= in[i].nd.st)
				for(int k = 1; k <= ny; ++k)
					if(in[i].st.nd <= Iy[k].st && Iy[k].nd <= in[i].nd.nd)
						Dinic::add_edge(j + 1, k + nx + 1, Dinic::INF);
	
	for(int i = 1; i <= nx; ++i)
		Dinic::add_edge(1, i + 1, Ix[i].nd - Ix[i].st + 1);
	for(int i = 1; i <= ny; ++i)
		Dinic::add_edge(nx + i + 1, nx + ny + 2, Iy[i].nd - Iy[i].st + 1);	
	printf("%d\n", Dinic::dinic(nx + ny + 2, 1, nx + ny + 2));
	return 0;
}