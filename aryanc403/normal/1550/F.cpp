/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
    #pragma GCC optimize ("-ffloat-store")
    #include<bits/stdc++.h>
    #define dbg(args...) 42;
#endif

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
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;


const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
#ifdef ARYANC403
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
#endif
}

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
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
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

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

using namespace atcoder;
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli n,q,s,d,i,in;
    cin>>n>>q>>s>>d;
    vi a;
    a.pb(-INF);
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    a.pb(INF);

    const lli N = 1e6+5,R=4;
    auto cost=[&](lli i,lli j){
        const lli dist=abs(a[i]-a[j]);
        return min(abs(dist-d),N-2);
    };

    vector<vii> edges(N);
    for(lli i=1;i<=n;++i){
        lli j=lower_bound(all(a),a[i]+d)-a.begin();
        for(lli k=0;k<=R;++k){
            const lli l=j-k,r=j+k;
            if(r<=n)
                edges[cost(i,r)].pb({i,r});
            if(l>=1)
                edges[cost(i,l)].pb({i,l});
        }

        j=lower_bound(all(a),a[i]-d)-a.begin();
        for(lli k=0;k<=R;++k){
            const lli l=j-k,r=j+k;
            if(r<=n)
                edges[cost(i,r)].pb({i,r});
            if(l>=1)
                edges[cost(i,l)].pb({i,l});
        }
    }

    vi ans(q);
    vector<vi> qur;
    for(lli i=0;i<q;++i){
        lli u,k;
        cin>>u>>k;
        qur.pb({k,u,i});
    }

    sort(all(qur));
    dsu dd(n+2);
    i=0;
    for(const auto &v:qur){
        while(i<=v[0]){
            for(auto x:edges[i]){
                dd.merge(x.X,x.Y);
            }
            i++;
        }
        ans[v[2]]=dd.same(s,v[1]);
    }

    for(auto x:ans)
        cout<<(x?"Yes":"No")<<endl;
}   aryanc403();
    return 0;
}