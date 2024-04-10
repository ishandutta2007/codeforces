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

constexpr lli INF = 0xFFFFFFFFFFFFFFFLL;
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

constexpr lli mod = 1000000007L;
// constexpr lli maxN = 1000000007L;
constexpr int N=12;
constexpr int maxN = (1LL<<N)*N*N;
bitset<maxN> vis,dp;
int getIdx[1<<N];
int e[N];
int n,m,k;
vii edges;

#define colour(col,j) ((col>>(3*(j)))&7)
#define getPos(matches,j) ((matches>>(4*(j)))&15)

constexpr bool checkHamilPath(const lli matches,const lli col){
    return
        colour(col,getPos(matches,0))==colour(col,getPos(matches,1))   &&
        colour(col,getPos(matches,2))==colour(col,getPos(matches,3))   &&
        colour(col,getPos(matches,4))==colour(col,getPos(matches,5))   &&
        colour(col,getPos(matches,6))==colour(col,getPos(matches,7))   &&
        colour(col,getPos(matches,8))==colour(col,getPos(matches,9))   &&
        colour(col,getPos(matches,10))==colour(col,getPos(matches,11));
}

vi hamilPaths;

void preprocess(){

    auto hamilPathExists = [&](const lli path)->bool{
        vii matches;
        for(lli i=n-1;i>=0;i-=2)
            matches.pb({getPos(path,i),getPos(path,i-1)});
        auto checkEdge=[&](const lli u,const lli v)->bool{
            return e[u]&(1<<v);
        };
        do{
            if(!checkEdge(matches[0].X,matches[0].Y))
                continue;
            bool fl=true;
            for(lli i=0;i+1<n/2;++i){
                if(checkEdge(matches[i].X,matches[i+1].X)&&checkEdge(matches[i].Y,matches[i+1].Y))
                    continue;
                if(checkEdge(matches[i].X,matches[i+1].Y)&&checkEdge(matches[i].Y,matches[i+1].X))
                    continue;
                fl=false;
                break;
            }
            if(fl)
                return true;
        }while(next_permutation(all(matches)));
        return false;
    };

    auto runPath = y_combinator([&](const auto &run,int msk,lli path)->void{
        if(msk==0){
            if(hamilPathExists(path))
                hamilPaths.pb(path);
            return;
        }
        const int i=getIdx[msk&(-msk)];
        msk^=(1<<i);
        path=(path<<8)|(i<<4);
        int curj=msk;
        while(curj)
        {
            const int j=getIdx[curj&(-curj)];
            curj^=(1<<j);
            run(msk^(1<<j),path|j);
        }

    });
    runPath((1<<n)-1,0);
}

bool getAllPaths(const lli &col){
    for(auto matches:hamilPaths){
        if(checkHamilPath(matches,col)){
            return true;
        }
    }
    return false;
}

lli getAllComb(){
    lli ans=0;
    lli cur=0;
    y_combinator([&](const auto &run,const int bc,const lli col,const int s,const bool fl,lli cnt)->void{
        if(col>k)
            return;
        if(fl)
            cnt*=(k-col+1);
        for(int j=s;j<n;++j){
            if((cur>>(3*j))&7)
                continue;
            cur|=col<<(3*j);
            if(bc>1)
            {
                run(bc-1,col,j+1,false,cnt);
                if(bc&1)
                    run(bc-1,col+1,0,true,cnt);
            } else {
                ans+=cnt*getAllPaths(cur);
            }
            cur&=~(7LL<<(3*j));
            if(fl)
                break;
        }
    })(n,1,0,true,1);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    cin>>n>>m>>k;
    vi shuf(n);
    iota(all(shuf),0);
    shuffle(all(shuf),rng);
    for(int itr=0;itr<m;++itr){
        int u,v;
        cin>>u>>v;
        u--;v--;
        // u=shuf[u];
        // v=shuf[v];
        e[u]|=1<<v;
        e[v]|=1<<u;
        edges.pb({u,v});
    }
    memset(getIdx,-1,sizeof(getIdx));
    for(int i=0;i<n;++i)
        getIdx[1<<i]=i;
    preprocess();
    dbg(sz(hamilPaths));
    const lli ans=getAllComb();
    cout<<ans<<endl;
}   aryanc403();
    return 0;
}