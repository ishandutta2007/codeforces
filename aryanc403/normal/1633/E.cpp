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

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
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

const lli INF = 1e10;
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

const int N = 50,M=300;
using va = array<ii,N>;
using vva = array<va,M*M>;
vva pointsMST;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    vector<vi> edges(m,vi(3));
    for(auto &v:edges){
        cin>>v[0]>>v[1]>>v[2];
        v[0]--;v[1]--;
    }
    sort(all(edges),[&](const vi &a,const vi &b){
        return a[2]<b[2];
    });

    map<lli,vii> changes;
    changes[-1];
    changes[0];
    changes[INF];
    for(lli i=0;i<m;++i)
        for(lli j=0;j<i;++j)
            changes[(edges[i][2]+edges[j][2])/2+1].pb(mp(i,j));

    vi c(m),pos(m);
    iota(all(c),0);
    iota(all(pos),0);

    auto swapIdx=[&](const lli u,const lli v){
        swap(c[pos[u]],c[pos[v]]);
        swap(pos[u],pos[v]);
    };

    va curMst;
    for(int i=0;i<N;++i)
        curMst[i].X=INF;
    curMst[0].X=-INF;
    vi changesPoints;
    for(const auto &cur:changes){
        for(const auto &x:cur.Y)
            swapIdx(x.X,x.Y);
        atcoder::dsu d(n);
        lli idxPos=1;
        for(const lli ed:c){
            const lli u=edges[ed][0],v=edges[ed][1];
            if(d.same(u,v))
                continue;
            curMst[idxPos].X=curMst[idxPos].Y=edges[ed][2];
            idxPos++;
            d.merge(u,v);
        }
        sort(all(curMst));
        for(lli i=1;i<n;++i)
            curMst[i].Y+=curMst[i-1].Y;
        pointsMST[sz(changesPoints)]=curMst;
        changesPoints.pb(cur.X);
    }

    lli ans=0;
    lli p,k,A,B,C,pvr=0;
    cin>>p>>k>>A>>B>>C;

    auto getMst=[&](const lli cur)->lli{
        const lli it=upper_bound(all(changesPoints),cur)-changesPoints.begin();
        const auto &mstEdges=pointsMST[it-1];
        const lli idx=upper_bound(all(mstEdges),mp(cur,-INF))-mstEdges.begin();
        lli mst=0;
        mst+=(idx-1)*cur-mstEdges[idx-1].Y;
        mst+=(mstEdges[n-1].Y-mstEdges[idx-1].Y)-cur*(n-idx);
        return mst;
    };
    for(lli i=0;i<k;++i){
        lli cur=0;
        if(i<p)
            cin>>cur;
        else
            cur=(A*pvr+B)%C;

        ans^=getMst(cur);
        pvr=cur;
    }

    cout<<ans<<endl;

}   aryanc403();
    return 0;
}