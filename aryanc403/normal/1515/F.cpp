/* in the name of Anton */

/*
  Compete against Yourself.
  Author - Aryan (@aryanc403)
  Atcoder library - https://atcoder.github.io/ac-library/production/document_en/
*/

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

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

struct Node{
    priority_queue<ii> pq;
    lli lazy;
    Node():lazy(0){};
    void insert(ii x){
        x.X-=lazy;
        pq.push(x);
    }
    void add(lli x){
        lazy+=x;
    }
    ii top(){
        auto u=pq.top();
        u.X+=lazy;
        return u;
    }
    void pop(){
        pq.pop();
    }

    bool empty(){
        return pq.empty();
    }

    void merge(Node &p){
        while(!p.empty()){
            auto u=p.top();p.pop();
            insert(u);
        }
    }
    lli size(){
        return sz(pq);
    }
};

void merge(Node &a,Node &b){
    if(sz(a)<sz(b)){
        swap(a,b);
    }
    a.merge(b);
}

    lli T,n,i,j,k,in,l,r,u,v,x,y;
    lli m;
    string s;
    vi a;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{
    lli xy;
    cin>>n>>m>>xy;
    fo(i,n)
    {
        cin>>in;
        a.pb(in);
    }

    vii edges;
    dsu d(n);
    vector<Node> nodes(n);
    for(int i=0;i<m;++i){
        lli u,v;
        cin>>v>>u;
        u--;v--;
        edges.pb({u,v});
        nodes[u].insert({a[u]+a[v],i});
        nodes[v].insert({a[u]+a[v],i});
    }

    priority_queue<ii> pq;
    for(lli i=0;i<n;++i){
        pq.push({nodes[i].top().X,i});
    }

    vi ans;
    while(!pq.empty()){
        auto tp=pq.top().Y;pq.pop();
        if(d.leader(tp)!=tp)
            continue;
        auto &root=nodes[tp];
        if(root.empty())
            continue;
        auto cur=root.top().Y;root.pop();
        lli u=edges[cur].X,v=edges[cur].Y;
        u=d.leader(u);
        v=d.leader(v);
        if(u==v)
        {
            if(!root.empty())
                pq.push({root.top().X,tp});
            continue;
        }
        dbg(a[u],a[v],xy,u,v);
        if(a[u]+a[v]<xy)
            break;
        ans.pb(cur);
        nodes[u].add(a[v]-xy);
        nodes[v].add(a[u]-xy);
        d.merge(u,v);
        const auto newLead=d.leader(u);
        a[newLead]=a[u]+a[v]-xy;
        merge(nodes[newLead],nodes[v^u^newLead]);
        if(nodes[newLead].empty())
            continue;
        pq.push({nodes[newLead].top().X,newLead});
    }
    dbg(ans);
    if(sz(ans)!=n-1){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(auto x:ans)
        cout<<x+1<<" ";
}   aryanc403();
    return 0;
}