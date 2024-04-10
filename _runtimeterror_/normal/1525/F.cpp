// max matching
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string) s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(char c) {
    string t = "'" + string(1,c) + "'";
    return t;
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for(size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}


template<typename T>
void debug_out(const char* name, T&& x) { 
    cerr << "[" << name << "] : " << to_string(x) << endl; 
}
template <typename H, typename... T>
void debug_out(const char* names, H&& arg1, T&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << "[";
    cerr.write(names, comma - names) << "] : " << to_string(arg1) <<" | ";
    debug_out(comma+1, args...);
}
#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


template<typename flow_t = long long>
struct Dinic {
    struct FlowEdge 
    {
        int v, u;
        flow_t cap, flow = 0;
        FlowEdge(int v, int u, flow_t cap) : v(v), u(u), cap(cap) {}
    };
    const flow_t flow_inf = numeric_limits<flow_t>::max()/2;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    // s -> source
    // t -> sink
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) 
    {
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
    }

    void add_edge(int v, int u, flow_t cap) 
    {
        // cout<<v<<" "<<u<<"\n";
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() 
    {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    flow_t dfs(int v, flow_t pushed) 
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            flow_t tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    flow_t flow() 
    {
        flow_t f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (flow_t pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
// .add_edge(u,v,cap);u->v
// .flow() == maxFlow

int _runtimeTerror_()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<set<int>> g(n+1),rg(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].insert(y);
        rg[y].insert(x);
    }
    vector<ll> x(k+1),y(k+1);
    for(int i=1;i<=k;++i)
        cin>>x[i]>>y[i];

    vector<ll> costs;
    vector<ll> move;
    // vertices - max_matching
    int left = -1,right = -1;
    auto get = [&](vector<set<int>> &g,bool rev)
    {
        left = right = -1;
        Dinic<ll> flow(2*n+3,0,2*n+1);
        for(int i=1;i<=n;++i)
        {
            flow.add_edge(0,i,1);
            flow.add_edge(i+n,2*n+1,1);
            for(auto j:g[i])
            {
                if(!rev)
                    flow.add_edge(i,j+n,1);
                else
                    flow.add_edge(j,i+n,1);
            }
        }
        auto u = flow.flow();
        for(int i=1;i<=n;++i)
        {
            if(left != -1)
                break;
            for(auto j:flow.adj[i])
            {
                if(flow.edges[j].flow == 1)
                {
                    left = i;
                    right = flow.edges[j].u - n;
                    break;
                }
            }
        }
        return u;
    };
    vector<int> want(k+1,0);
    for(int i=1;i<=k;++i)
    {   
        int uu = i;
        // debug(get(g,false));
        if(n - get(g,false) > i)
            costs.push_back(0),move.push_back(0),want[i] = 0;
        else
        {
            // debug(i);
            bool can = false;
            for(int i=1;i<=n;++i)
            {
                if(g[i].empty())
                    continue;
                auto u = g;
                g[i].clear();
                if(n - get(g,false) > uu)
                {
                    costs.push_back(1);
                    move.push_back(i);
                    // debug(uu,i);
                    can = true;
                    for(auto j:u[i])
                        rg[j].erase(i);
                    break;
                }
                g[i] = u[i];
            }
            // debug(i,can);
            if(can)
            {
                want[i] = 1;
                continue;
            }
            for(int i=1;i<=n;++i)
            {
                if(rg[i].empty())
                    continue;
                auto u = rg;
                rg[i].clear();
                if(uu == 4 && i == 3)
                {
                    // debug(get(rg,true));
                    // debug(left,right);
                }
                if(n - get(rg,true) > uu)
                {
                    costs.push_back(1);
                    move.push_back(-i);
                    can = true;
                    for(auto j:u[i])
                        g[j].erase(i);
                    break;
                }
                rg[i] = u[i];
            }
            // debug(i,can);
            if(can)
            {
                want[i] = 1;
                continue;
            }
            // debug(get(g,false));
            // debug(left);
            if(left < 0)
                exit(0);
            assert(left != -1);
            for(auto j:g[left])
                rg[j].erase(left);
            g[left].clear();
            for(auto j:rg[right])
                g[j].erase(right);
            rg[right].clear();
            costs.push_back(1);
            costs.push_back(1);
            move.push_back(left);
            move.push_back(-right);
            want[i] = 2;
        }
    }
    debug(want,move);
    for(int i=1;i<=k;++i)
        want[i] += want[i-1];
    vector<vector<ll>> dp(k+1,vector<ll>(2*n+1,-INF));
    dp[0][0] = 0;
    for(int i=1;i<=k;++i)
    {
        for(int j=0;j<=sz(costs);++j)
        {
            if(j < want[i])
            {
                dp[i][j] = -INF;
                continue;
            }
            for(int k=0;k<=j;++k)
            {
                amax(dp[i][j],dp[i-1][j-k] + max(0ll,x[i] - k * y[i]));
            }
        }
    }
    ll ans = -INF;
    int last = -1;
    for(int i=0;i<=2*n;++i)
    {
        if(dp[k][i] > ans)
            amax(ans,dp[k][i]),last = i;
    }
    // cout<<ans<<"\n";
    vector<int> val;
    val.push_back(0);
    for(int i=k-1;i>=0;--i)
    {
        for(int j=0;j<=2*n;++j)
        {
            if(j <= last && dp[i][j] + max(0ll,x[i+1] - (last-j)*y[i+1])== ans)
            {
                int k = last - j;
                ans -= max(0ll,x[i+1] - k * y[i+1]);
                debug(i,j);
                while(k--)
                {
                    val.push_back(move.back());
                    move.pop_back();
                }
                last = j;
            }
        }
        if(i)
            val.push_back(0);
    }
    debug(val);
    cout<<sz(val)<<"\n";
    reverse(all(val));
    for(auto j:val)
        cout<<j<<" ";
    // for(int i=1;i<=k;++i)
        // cout<<want[i]<<"\n";
    // cout<<flow.flow()<<"\n";
    // for(int i=1;i<=n;++i)
    // {
    //     for(auto j:flow.adj[i])
    //     {
    //         if(flow.edges[j].flow == 1)
    //         {
    //             cout<<i<<" "<<flow.edges[j].u-n<<"\n";
    //         }
    //     }
    // }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}