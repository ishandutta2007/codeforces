#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

struct DSU{
    int par[100005];

    //No union by rank 
    void setUp (int n){
        for (int i=0; i<n; i++) par[i]=i; //From 0
    }

    int find(int x){
        if (x==par[x]){
            return x;
        }
        else{
            par[x]=find(par[x]);
            return par[x];
        }
    }

    void merge(int a, int b){
        par[find(a)]=par[find(b)];
    }
};

int pos[maxn];

vector<int> g[maxn];
bool vis[maxn];

bool ok(int at, int type){
    vis[at]=1;
    if (pos[at]==-1) pos[at]=type;
    if (pos[at]!=type) return 0;
    for (int v : g[at]){
        if (pos[v]!=-1 && pos[v]!=type^1) return 0;
        if (!vis[v]){
            if (!ok(v,type^1)){
                return 0;
            }
        }
    }
    return 1;
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fill(pos, pos+maxn,-1);
    int n, m; cin>>n>>m;
    vector<pii> dis;
    DSU d1; d1.setUp(n+1);
    DSU d2; d2.setUp(n+1);
    int tt = n;
    map<pii, bool> seen;
    REP(i,m){
        int a, b, c;
        cin>>a>>b>>c;
        // a = d1.find(a); b = d1.find(b);
        if (c==1){
            if (d1.find(a)!=d1.find(b)) tt--;
            d1.merge(a,b);
        }else{
            dis.pb({a,b});
        }
    }

    for (auto &x : dis){
        int a = d1.find(x.f); int b = d1.find(x.s);
        if (a==b){
            cout<<0<<endl; return 0;
        }
        if (seen[{a,b}] || seen[{b,a}]) continue;
        seen[{a,b}]=1;
        if (d2.find(a)!=d2.find(b) ) {
            tt--;
            d2.merge(a, b);
        }
        g[a].pb(b); g[b].pb(a);
    }
    // debug(tt);
    FOR(i,1,n+1){
        if (d1.find(i)==i){
            if (!vis[i] && !ok(i,0)){
                cout<<0<<endl; return 0;
            }
        }
    }
    cout<<mpow(2,tt-1)<<'\n';
    
}