#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef float f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}

template <int NMAX, int MMAX>
class MaxFlowMinCost {
public:
    MaxFlowMinCost() { m = 0; }

    inline void setN(int _n) { n = _n; }
    inline void setS(int _s) { s = _s; }
    inline void setT(int _t) { t = _t; }

    inline int getN() { return n; }
    inline int getS() { return s; }
    inline int getT() { return t; }

    void clear() {
        m = 0;
        for (int i = 1; i <= n; ++ i)
            graph[i].clear();
    }

    void reset() {
        for (int i = 0; i < m; ++ i)
            edges[i].flow = 0;
    }

    void addEdge(int from, int to, int cap, int cost) {
        edges[m ++] = Edge(from, to, 0, cap, cost);
        edges[m ++] = Edge(to, from, 0, 0, -cost);

        graph[from].push_back(m - 2);
        graph[to].push_back(m - 1);
    }

    inline pair <ll, ll> computeFlow() {
        return JohnsonDinic();
    }
private:
    struct Edge {
        int from, to;
        int flow, cap, cost;

        Edge(int _from = 0, int _to = 0, int _flow = 0, int _cap = 0, int _cost = 0):
            from(_from), to(_to), flow(_flow), cap(_cap), cost(_cost) {}
        inline int other(int node) {
            return from ^ to ^ node;
        }
    };

    int n, m, s, t;

    vector <int> graph[NMAX];
    Edge edges[2 * MMAX];

    const int INF = 1e9 + 15;

    int potentials[NMAX];
    bool vis[NMAX];
    int BellmanDP(int node) {
        if (vis[node])
            return potentials[node];
        if (node == s) {
            potentials[s] = 0;
            return 0;
        }
        vis[node] = true;

        potentials[node] = INF;
        for (auto edg: graph[node])
            if (edges[edg ^ 1].flow < edges[edg ^ 1].cap)
                potentials[node] = min(potentials[node], BellmanDP(edges[edg ^ 1].other(node)) + edges[edg ^ 1].cost);
        return potentials[node];
    }

    int dist[NMAX];
    int father[NMAX];
    priority_queue <pair <int, int> > _queue;

    bool Dijkstra() {
        memset(vis, 0, (n + 1) * sizeof(bool));
        for (int i = 1; i <= n; ++ i)
            dist[i] = INF;

        dist[s] = 0;
        _queue.push(make_pair(0, s));

        int node;
        while (!_queue.empty()) {
            node = _queue.top().second;
            _queue.pop();

            if (vis[node])
                continue;
            vis[node] = true;

            for (auto edge: graph[node]) {
                int other = edges[edge].other(node);
                int cost = edges[edge].cost + potentials[node] - potentials[other];

                if (edges[edge].flow < edges[edge].cap && dist[node] + cost < dist[other]) {
                    dist[other] = dist[node] + cost;
                    father[other] = edge;
                    _queue.push(make_pair(-dist[other], other));
                }
            }
        }

        for (int i = 1; i <= n; ++ i)
            dist[i] += (potentials[i] - potentials[s]);

        return vis[t];
    }

    pair <ll, ll> JohnsonDinic() {
        memset(potentials, 0, (n + 1) * sizeof(int));
        BellmanDP(t);

        ll flow = 0, cost = 0;
        while (Dijkstra()) {
            int node = t;
            int minimum = INF;
            int sum = 0;

            while (node != s) {
                minimum = min(minimum, edges[father[node]].cap - edges[father[node]].flow);
                sum += edges[father[node]].cost;
                node = edges[father[node]].other(node);
            }

            node = t;
            while (node != s) {
                edges[father[node]].flow += minimum;
                edges[father[node] ^ 1].flow -= minimum;
                node = edges[father[node]].other(node);
            }

            flow += minimum;
            cost += minimum * sum;

            memcpy(potentials, dist, (n + 1) * sizeof(int));
        }

        return make_pair(flow, cost);
    }
};

const int NMAX = 2005;
const int MMAX = 8005;

MaxFlowMinCost <NMAX, MMAX> f;

int ac[2005],bc[2005];
void solve() {
	int n,a,b;
	cin>>n>>a>>b;
	f.setN(n+4);
	f.setS(n+1);
	f.setT(n+4);
	f.addEdge(n+1, n+2, a, 0);
	f.addEdge(n+1, n+3, b, 0);
	fr(i,1,n) {
		double tol;
		cin>>tol;
		int cost=ll(tol*1e9);
		ac[i]=cost;
		f.addEdge(n+2, i, 1, -cost);
	}
	fr(i,1,n) {
		double tol;
		cin>>tol;
		int cost=ll(tol*1e9);
		bc[i]=cost;
		f.addEdge(n+3, i, 1, -cost);
		f.addEdge(i, n+4, 1, 0);
		f.addEdge(i, n+4, 1, llround(ac[i]*bc[i])/1e9);
	}
	cout<<-f.computeFlow().se/1e9<<endl;
}


signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}