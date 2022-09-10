#include<bits/stdc++.h>

using namespace std;

namespace Dinic {
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
    
    void clear() {
    	e.clear();
    	for(int i = 1; i <= n; ++i)
    		g[i].clear();
    }
    
    /* Edges can be added only using add_edge to use this function! */
    void clear_flow() {
    	for(int i = 0; i < (int)e.size(); i += 2)
    		e[i].flow = 0, e[i + 1].flow = e[i + 1].cap;
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

struct edge {
	int u, v;
	long long w;
};

namespace GHTree {
	int n;
	vector <int> p, w, c;
	vector <edge> tree;
	
	void dfs(int u) {
		c[u] = 1;
		for(const int &id: Dinic::g[u]) {
			int v = Dinic::e[id].b;
			if(!c[v] and Dinic::e[id].flow < Dinic::e[id].cap)
				dfs(v);
		}
	}
	
	/* Clears and runs */
	vector <edge> run(int _n, const vector <edge> &ed) {
		n = _n;
		tree.clear();
		p.resize(n + 1), w.resize(n + 1), c.resize(n + 1);

		for(const auto &e: ed) {
			Dinic::add_edge(e.u, e.v, e.w);
			Dinic::add_edge(e.v, e.u, e.w);
		}

		p[1] = 0, fill(p.begin() + 2, p.end(), 1);
		for(int i = 2; i <= n; ++i) {
			w[i] = Dinic::dinic(n, i, p[i]);
			fill(c.begin(), c.end(), 0);
			dfs(i);
			
			for(int j = i + 1; j <= n; ++j)
				if(c[j] && p[j] == p[i])	
					p[j] = i;
			
			if(p[p[i]] && c[p[p[i]]]) {
				int pi = p[i];
				swap(w[i], w[pi]);
				p[i] = p[pi];
				p[pi] = i;
			}
			
			Dinic::clear_flow();
		}
		
		tree.clear();
		for(int i = 1; i <= n; ++i) {
			if(p[i])
				tree.push_back(edge{i, p[i], w[i]});
		}

		return tree;
	}
}

const int N = 207;

int n, m;
vector <edge> ed;

int id[N];
vector <int> ans[N];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		ed.push_back(edge{u, v, w});
	}
	
	auto gh = GHTree::run(n, ed);
	sort(gh.begin(), gh.end(), [](edge a, edge b){
		return a.w > b.w;
	});
	
	for(int i = 1; i <= n; ++i)
		id[i] = i, ans[i] = { i };
	
	int s = 0;
	for(auto e: gh) {
		int eu = id[e.u], ev = id[e.v];
		s += e.w;
		for(auto v: ans[ev]) {
			id[v] = eu;
			ans[eu].push_back(v);
		}
	}
	
	int r = id[1];
	printf("%d\n", s);
	for(int i = 0; i < n; ++i)
		printf("%d%c", ans[r][i], " \n"[i + 1 == n]);
	return 0;
}