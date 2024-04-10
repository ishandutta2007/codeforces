/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
*/
/*
  Credits -
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/ (namespace atcoder)
  Github source code of library - https://github.com/atcoder/ac-library/tree/master/atcoder
*/

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

void prt(const vi &ans){
    const lli n=sz(ans);
     for(int i=0;i<n;++i)
        cout<<ans[i]<<" \n"[i+1==n];
}

vi solve(const vector<vi> &e){
    const lli n=sz(e);
    vi d0(n,INF),par(n,-1);
    vii tinout(n,mp(-1,-1));
    lli tim=0;
    y_combinator([&](const auto &self,lli u,lli p,lli h)->void{
        par[u]=p;
        d0[u]=h;
        tinout[u].X=tim++;
        for(auto x:e[u]){
            if(x==p)
                continue;
            self(x,u,h+1);
        }
        tinout[u].Y=tim++;
    })(0,-1,0);

    auto isAnc=[&](const lli u,const lli v)->bool{
        return tinout[u].X<=tinout[v].X&&tinout[v].Y<=tinout[u].Y;
    };

    auto getCost=[&](const lli rt,const lli x)->ii{
        if(rt==-1)
            return mp(INF,0);
        vi d(n,INF);
        y_combinator([&](const auto &self,lli u,lli p,lli h)->void{
            d[u]=h;
            for(auto x:e[u]){
                if(x==p)
                    continue;
                self(x,u,h+1);
            }
        })(rt,-1,x);
        ii ans=mp(-INF,0);
        for(lli i=0;i<n;++i)
            ans=max(ans,mp(min(d[i],d0[i]),i));
        return ans;
    };

    auto getMinimumCost=[&](const lli m)->ii{
        ii ans=mp(INF,0);
        for(lli i=0;i<n;++i)
            ans=min(ans,mp(getCost(i,m).X,i));
        return ans;
    };

    vi answers(n,-1);

    lli curNode=getMinimumCost(0).Y;
    dbg(getMinimumCost(0),curNode);
    for(lli x=1;x<=n;++x){
        const auto c1=getCost(curNode,x);
        const auto c2=getCost(par[curNode],x);
        ii c3=mp(INF,0);
        lli cldNode=-1;
        for(auto v:e[curNode]){
            if(v==par[curNode])
                continue;
            if(isAnc(v,c1.Y)){
                c3=getCost(v,x);
                cldNode=v;
            }
        }
        answers[x-1]=min({c1.X,c2.X,c3.X});
        if(c2.X<min(c1.X,c3.X)){
            curNode=par[curNode];
            continue;
        }

        if(c3.X<c1.X){
            curNode=cldNode;
            continue;
        }
    }
    return answers;
}

vi bf(const vector<vi> &e){
    const lli n=sz(e);
    vi d0(n,INF),par(n,-1);
    y_combinator([&](const auto &self,lli u,lli p,lli h)->void{
        par[u]=p;
        d0[u]=h;
        for(auto x:e[u]){
            if(x==p)
                continue;
            self(x,u,h+1);
        }
    })(0,-1,0);

    auto getCost=[&](const lli rt,const lli x){
        if(u==-1)
            return INF;
        vi d(n,INF);
        y_combinator([&](const auto &self,lli u,lli p,lli h)->void{
            d[u]=h;
            for(auto x:e[u]){
                if(x==p)
                    continue;
                self(x,u,h+1);
            }
        })(rt,-1,x);
        lli ans=-INF;
        for(int i=0;i<n;++i)
            ans=max(ans,min(d[i],d0[i]));
        return ans;
    };

    auto getMinimumCost=[&](const lli m)->lli{
        lli ans=INF;
        for(lli i=0;i<n;++i)
            ans=min(ans,getCost(i,m));
        return ans;
    };

    vi ans;
    for(int i=0;i<n;++i)
        ans.pb(getMinimumCost(i+1));
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
cin>>T;while(T--)
{

    cin>>n;
    vector<vi> e(n);
    fo(i,n-1){
        lli u,v;
        cin>>u>>v;
        u--;v--;
        e[u].pb(v);
        e[v].pb(u);
    }

    prt(solve(e));
}   aryanc403();
    return 0;
}