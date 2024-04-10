/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
  https://codeforces.com/contest/4/submission/150120627
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include <bits/stdc++.h>
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
    vi a(n),hsh(n);
    for(auto &x:hsh)
        x=rnd(0,(1LL<<60));

    vi sub(n),par(n,-2);
    fo(i,n)
    {
        cin>>in;
        in--;
        a[i]=in;
        sub[i]=hsh[in]^hsh[i];
    }

    vi ans;
    vector<vii> e(n);
    map<ii,lli> edges;
    fo(i,m){
        lli u,v;
        cin>>u>>v;
        u--;v--;
        if(u>v)
            swap(u,v);
        e[u].pb({v,i});
        e[v].pb({u,i});
        edges[{u,v}]=edges[{v,u}]=i;
    }

    vector<map<lli,set<lli>>> nex(n);
    queue<lli> q;
    auto dfs=y_combinator([&](const auto &self,lli u,lli p)->lli{
        q.push(u);
        par[u]=p;
        dbg(p,u,a[u]);
        for(auto x:e[u]){
            auto it=find(all(e[x.X]),mp(u,x.Y));
            e[x.X].erase(it);
            sub[u]^=self(x.X,u);
        }
        if(p!=-1){
            const lli c=sub[u]^hsh[a[u]];
            nex[p][c].insert(u);
        }
        return sub[u];
    });

    auto change=[&](lli u,lli p){
        if(par[u]!=p)
            swap(u,p);
        const lli pp=par[p];
        dbg("swap",u,p);
        ans.pb(edges[{u,p}]);
        edges.erase({u,p});
        edges.erase({p,u});
        lli c=sub[u]^hsh[a[u]];
        nex[p][c].erase(u);
        if(nex[p][c].empty())
            nex[p].erase(c);

        if(pp!=-1){
            c=sub[p]^hsh[a[p]];
            nex[pp][c].erase(u);
            if(nex[pp][c].empty())
                nex[pp].erase(c);
        }
        sub[u]^=hsh[a[u]]^hsh[a[p]];
        swap(a[u],a[p]);

        if(sub[u]){
            c=sub[u]^hsh[a[u]];
            nex[p][c].insert(u);
        }

        if(pp!=-1&&sub[p]){
            c=sub[p]^hsh[a[p]];
            nex[pp][c].insert(p);
        }
        q.push(u);
        q.push(p);
        if(pp!=-1)
            q.push(par[p]);
    };

    auto solve=y_combinator([&](const auto &self)->void{
        while(!q.empty()){
            const lli cur=q.front();q.pop();
            dbg("queue",cur);
            if(nex[cur].empty())
                continue;
            auto it=nex[cur].find(hsh[a[cur]]);
            if(it==nex[cur].end())
                continue;
            const lli cld=*(it->Y.begin());
            change(cur,cld);
        }
    });

    for(lli i=0;i<n;i++){
        if(par[i]!=-2)
            continue;
        dbg("current",a);
        assert(dfs(i,-1)==0);
        solve();
    }
    dbg(a);
    // assert(edges.empty());
    for(auto x:ans)
        cout<<x+1<<" ";
    cout<<endl;
}   aryanc403();
    return 0;
}