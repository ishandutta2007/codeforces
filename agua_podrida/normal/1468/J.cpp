#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

vector<int, int> &
getVector(const unordered_map<ll, int> &trad, vector<map<int, int>> &g, int dst, int &prox, ll res, int v, int i);

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define INF 1e18
#define todo(v) v.begin(),v.end()
#define eps 0.000000001
#define mod 1000000007
#define PI acos(-1.0)


struct persistentDSU{
    persistentDSU(int n){
        p.resize(n);
        F0(i,n) p[i] = i;
        s = vi(n,1);
        comp = n;
    }

    int find(int u){
        while(u != p[u]) u = p[u];
        return u;
    }

    void unite(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;
        comp--;
        if(s[u] < s[v]) swap(u,v);
        p[v] = u;
        s[u] += s[v];
    }

    vi p;
    vi s;
    int comp;
};

struct edge{
    edge(int u, int v, ll c) : u(u), v(v), c(c) {}

    bool operator<(edge e) const {
        return c < e.c;
    }

    int u;
    int v;
    ll c;
};


void j(){
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<edge> e;
    int u,v;
    ll c;
    F0(i,m){
        cin>>u>>v>>c;
        u--; v--;
        e.pb(edge(u,v,c));
    }
    sort(todo(e));
    persistentDSU uf(n);
    int i = 0;
    while(i < m and e[i].c <= k){
        uf.unite(e[i].u,e[i].v);
        i++;
    }
    if(uf.comp == 1){
        ll res = k-e[i-1].c;
        if(i < m) mini(res,e[i].c-k);
        cout<<res<<'\n';
        return;
    }
    ll costo = 0;
    while(i < m){
        if(uf.find(e[i].u) != uf.find(e[i].v)){
            uf.unite(e[i].u,e[i].v);
            costo += e[i].c-k;
        }
        i++;
    }
    cout<<costo<<'\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../input.txt","r",stdin);
    //freopen("../output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) j();
    return 0;
}