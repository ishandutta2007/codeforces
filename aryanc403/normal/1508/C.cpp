/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

#include <vector>
#ifdef ARYANC403
    #include <header.h>
#else
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
    //#pragma GCC optimize ("-ffloat-store")
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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,w,wt;
    string s;
    vector<set<lli>> e;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

// Ref - https://codeforces.com/contest/1242/submission/79434053
// https://codeforces.com/blog/entry/79880?#comment-658108

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

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
set<lli> vis;
dsu d;
void dfs(int u) {
	vis.erase(u);
	int last = -1;
	while(1) {
		auto it = vis.upper_bound(last);
		if(it == vis.end()) break;
		last = *it;
		if(!e[u].count(last)) {
            dbg(last,u,0);
			d.merge(last,u);
			dfs(last);
		}
	}
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>n>>m;
    e.resize(n);
    vector<vi> edges;
    d=dsu(n);
    fo(i,m)
    {
        cin>>u>>v>>w;;
        u--;v--;
        e[u].insert(v);
        e[v].insert(u);
        edges.pb({w,u,v});
        wt^=w;
    }

    fo(i,n)
        vis.insert(i);
    while(!vis.empty()) {
        int u = *vis.begin();
        dfs(u);
    }

    bool fl=false;
    if(n*(n-1)/2-m>=n)
        fl=true;
    else {
        dsu dd(n);
        for(int i=0;i<n&&!fl;++i)
        for(int j=0;j<i&&!fl;++j){
            if(!e[i].count(j)){
                if(dd.same(i,j)){
                    fl=true;
                    break;
                }
                dd.merge(i, j);
            }
        }
    }
    dbg(d.groups(),wt,fl);
    dsu dd(n);
    lli ans=0;
    sort(all(edges));
    for(const auto &vv:edges){
        const lli w=vv[0],u=vv[1],v=vv[2];
        dbg(u,v,w);
        if(d.same(u, v))
        {
            if(w<=wt&&!fl&&!dd.same(u, v))
            {
                ans+=w;
                fl=true;
            }
            continue;
        }
        ans+=w;
        d.merge(u, v);
        dd.merge(u, v);
    }
    if(!fl)
        ans+=wt;
    cout<<ans<<endl;
    dbg(ans);
}   aryanc403();
    return 0;
}