/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
*/

#include <algorithm>
#include <cassert>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>


#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {
namespace internal {

struct scc_graph {
  public:
    explicit scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder


namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    explicit scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder


#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    #define dbg(args...) 42;
    #define endl "\n"
#endif

// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;
template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// X.find_by_order(k) return kth element. 0 indexed.
// X.order_of_key(k) returns count of elements strictly less than k.

const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFLL;
const lli SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    map<lli,lli> types;
    vector<vi> e(n);
    fo(i,m)
    {
        lli t,u,v;
        cin>>t>>u>>v;
        u--;v--;
        e[u].pb(v);
        e[v].pb(u);
        types[u*n+v]=types[v*n+u]=t;
    }

    auto NO=[&](){
        cout<<"NO"<<endl;
        exit(0);
    };

    vii ans(n,mp(-1,0));

    // x < y
    auto cmp=[&](const lli x,const lli y)->bool{
        if(!types.count(x*n+y))
            return false;
        const lli t=types[x*n+y];
        if(ans[x].X)
            // x is L
            return t==1;
        return t==2;
    };

    auto toposort=y_combinator([&](const auto &self)->void{
        atcoder::scc_graph g(n);
        for(lli x=0;x<n;++x)
            for(auto y:e[x])
                if(cmp(x,y))
                    g.add_edge(x,y);

        auto scc = g.scc();
        lli idx=0;
        for(const auto &v:scc){
            if(sz(v)>1)
                NO();
            ans[v[0]].Y=idx++;
        }
    });

    auto dfs=y_combinator([&](const auto &dfs,lli u,lli c)->void{
        if(ans[u].X!=-1){
            if(ans[u].X==c)
                return;
            NO();
        }
        ans[u].X=c;
        for(auto x:e[u])
            dfs(x,c^1);
    });

    for(lli i=0;i<n;++i){
        if(ans[i].X!=-1)
            continue;
        dfs(i,0);
    }
    toposort();
    cout<<"YES"<<endl;
    for(auto x:ans)
        cout<<"RL"[x.X]<<" "<<x.Y<<endl;
}   aryanc403();
    return 0;
}