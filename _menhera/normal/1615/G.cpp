#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2020 + 1;
// 1-based Vertex index
int vis[MAXN], par[MAXN], orig[MAXN], match[MAXN], aux[MAXN], t, N;
vector<int> conn[MAXN];
queue<int> Q;
void addEdge(int u, int v) {
	conn[u].push_back(v); conn[v].push_back(u);
}
void init(int n) {
	N = n; t = 0;
	for(int i=0; i<=n; ++i) {
		conn[i].clear();
		match[i] = aux[i] = par[i] = 0;
	}
}
void augment(int u, int v) {
	int pv = v, nv;
	do {
		pv = par[v]; nv = match[pv];
		match[v] = pv; match[pv] = v;
		v = nv;
	} while(u != pv);
}
int lca(int v, int w) {
	++t;
	while(true) {
		if(v) {
			if(aux[v] == t) return v; else aux[v] = t;
			v = orig[par[match[v]]];
		}
		swap(v, w);
	}
}
void blossom(int v, int w, int a) {
	while(orig[v] != a) {
		par[v] = w; w = match[v];
		if(vis[w] == 1) Q.push(w), vis[w] = 0;
		orig[v] = orig[w] = a;
		v = par[w];
	}
}
bool bfs(int u) {
	fill(vis+1, vis+1+N, -1); iota(orig + 1, orig + N + 1, 1);
	Q = queue<int> (); Q.push(u); vis[u] = 0;
	while(!Q.empty()) {
		int v = Q.front(); Q.pop();
		for(int x: conn[v]) {
			if(vis[x] == -1) {
				par[x] = v; vis[x] = 1;
				if(!match[x]) return augment(u, x), true;
				Q.push(match[x]); vis[match[x]] = 0;
			}
			else if(vis[x] == 0 && orig[v] != orig[x]) {
				int a = lca(orig[v], orig[x]);
				blossom(x, v, a); blossom(v, x, a);
			}
		}
	}
	return false;
}
int Match() {
	int ans = 0;
	// find random matching (not necessary, constant improvement)
	vector<int> V(N-1); iota(V.begin(), V.end(), 1);
	shuffle(V.begin(), V.end(), mt19937(0x94949));
	for(auto x: V) if(!match[x]){
		for(auto y: conn[x]) if(!match[y]) {
			match[x] = y, match[y] = x;
			++ans; break;
		}
	}
	for(int i=1; i<=N; ++i) if(!match[i] && bfs(i)) ++ans;
	return ans;
} // https://blog.kyouko.moe/20

struct UFD
{
    vector<int> ufd;
    UFD(int n): ufd(n) {iota(ufd.begin(), ufd.end(), 0); }
    int Find(int x){ if(x == ufd[x]) return x; return ufd[x] = Find(ufd[x]); }
    void Union(int a, int b){ ufd[Find(a)] = Find(b);}
};

int main()
{
    int N; cin >> N;
    vector<int> V(N); for(int&x: V) cin >> x;
    vector<pair<int, int> > ft;
    int from = -1;
    for(int i=0; i<N; ++i)
    {
        if(V[i] == 0)
        {
            if(from == -1) from = i;
        }
        else
        {
            if(from != -1) ft.emplace_back(from, i-1);
            from = -1;
        }
    }
    if(from != -1) ft.emplace_back(from, N-1);

    if(ft.size() == 1 && ft[0].first == 0 && ft[0].second == N-1)
    {
        for(int i=0; i<N; ++i) cout << (i/2)+1 << " ";
        cout << endl;
        return 0;
    }

    vector<pair<int, int>> ov, av;

    for(auto [f, t]: ft)
    {
        if(f == 0)
        {
            for(int i=0; i+1<=t; i += 2) V[i] = V[i+1] = -1;
            if(t%2 == 0) V[t] = V[t+1];
        }
        else if(t == N-1)
        {
            for(int i=t; i-1>=f; i -= 2) V[i] = V[i-1] = -1;
            if((t-f)%2 == 0) V[f] = V[f-1];
        }
        else
        {
            if((t-f+1)%2 == 0) av.emplace_back(f, t);
            else ov.emplace_back(f, t);
        }
    }
    int K = 600; UFD ufd(K+1); init(K);
    vector<bool> used(K+1); vector<int> cooked(K+1);
    // first, run used check
    for(int i=0; i<N-1; ++i) if(V[i] == V[i+1] && V[i] > 0) used[V[i]] = 1;
    // second, run UFD

    vector<pair<int, int>> raw;
    for(auto [f, t]: ov)
    {
        int s = V[f-1], e = V[t+1];
        if(ufd.Find(s) == ufd.Find(e))
        {
            cooked[s] = s; used[s] = 1;
            V[f] = V[f-1];
            for(int i=f+1; i<=t; ++i) V[i] = -1;
        }
        else raw.emplace_back(f, t);
        ufd.Union(s, e);
    }
    // third, check used on cooked
    for(int i=1; i<=K; ++i) if(cooked[i]) cooked[ufd.Find(i)] = cooked[i];
    for(int i=1; i<=K; ++i) if(cooked[ufd.Find(i)]) used[i] = 1;

    // fourth, add edge
    vector<vector<int>> added(K+1, vector<int>(K+1, -1));
    for(int i=0; i<(int)av.size(); ++i)
    {
        auto [f, t] = av[i]; int s = ufd.Find(V[f-1]), e = ufd.Find(V[t+1]);
        if(used[s] || used[e]) continue;
        if(added[s][e] != -1) continue;
        if(s == e) continue;
        added[s][e] = added[e][s] = i;
        addEdge(s, e);
    }
    Match();
    vector<int> root(K+1);
    for(int i=1; i<=K; ++i) if(match[i] && match[i] > i)
    {
        int s = i, e = match[i];
        auto [f, t] = av[added[s][e]];
        V[f] = V[f-1]; V[t] = V[t+1];
        used[V[f-1]] = used[V[t+1]] = 1;
        for(int j=f+1; j<=t-1; ++j) V[j] = -1;
    }
    for(auto [f, t]: av) if(V[f] == 0) for(int j=f;j<=t;++j) V[j] = -1;

    // check for ov
    // raw forms forest
    vector<vector<tuple<int, int, int>>> conn(K+1);
    for(auto [f, t]: raw)
    {
        int s = V[f-1], e = V[t+1];
        // cout << f << " " << t << " " << s << " " << e << endl;
        conn[s].emplace_back(e, f, t);
        conn[e].emplace_back(s, f, t);
    }
    function<void(int, int)> dfs = [&](int a, int p)
    {
        // cout << "!" << a << endl;
        for(auto [b, f, t]: conn[a]) if(b != p)
        {
            if(V[f] == 0)
            {
                for(int i=f; i<=t; ++i) V[i] = -1;
                if(V[f-1] == b) V[f] = b;
                else V[t] = b;
            }
            dfs(b, a);
        }
    };
    // for(auto x: V) cout << x << " ";
    // cout << endl;


    for(int i=1; i<=K; ++i) if(ufd.Find(i) == i)
    {
        int p = i;
        if(cooked[p]) p = cooked[p];
        else for(int i=1; i<=K; ++i) if(used[i] && ufd.Find(i) == p) p = i;
        dfs(p, -1);
    }
    for(int i=0; i<N-1; ++i) if(V[i] == V[i+1] && V[i] > 0) used[V[i]] = 1;

    int tp = 1;
    for(int i=0; i<N-1; ++i) if(V[i] == -1)
    {
        while(tp <= K && used[tp]) ++tp;
        assert(V[i+1] == -1);
        V[i] = V[i+1] = tp;
        if(tp <= K) used[tp] = 1;
        ++tp;
    }
    for(auto x: V) cout << x << " ", assert(x > 0);
    cout << endl;
}