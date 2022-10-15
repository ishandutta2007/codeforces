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

const int maxn = 1e3+5;

vector<int> g[maxn];
int sz[maxn];
int par[maxn];
int n; 

void dfs(int at){
    sz[at]=1;
    for (int v : g[at]){
        if (v != par[at]){
            par[v]=at;
            dfs(v);
            sz[at]+=sz[v];
        }
    }
}

int cent(int at){
    for (int v : g[at]){
        if (v!=par[at] && sz[v] >= ((n+1)/2)){
            return cent(v);
        }
    }
    return at;
}

int gp[maxn];
vector<int> gg[maxn];

void ddfs(int at){
    gp[at] = 1;
    for (int v : gg[at]){
        if (gp[v]==0) ddfs(v); 
    }
}

int nat = 1;
int val[maxn];

void dfsA(int at, int p){
    for (int v : g[at]){
        if (v!=p){
            val[v] = nat;
            cout<<at+1<<' '<<v+1<<' '<<(nat - val[at])<<endl;
            nat++;
            dfsA(v,at);
        }
    }
}

int A;

void dfsB(int at, int p){
    for (int v : g[at]){
        if (v!=p){
            val[v] = nat;
            cout<<at+1<<' '<<v+1<<' '<<(nat - val[at])*(A+1)<<endl;
            nat++;
            dfsB(v,at);
        }
    }
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    if (n==1) return 0;
    if (n==2){
        int a, b; cin>>a>>b;
        cout<<a<<' '<<b<<' '<<1<<endl; return 0;
    }
    REP(i,n-1){
        int u, v; cin>>u>>v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0);
    int c = cent(0);
    // debug(c);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int S=0;
    for (int v : g[c]){
        if (v == par[c]) continue;
        pq.push({sz[v],v}); S += sz[v];
    }
    if (n-S-1) pq.push({n-S-1,par[c]});
    // debug(pq.size());
    while (SZ(pq)>=3) {
        pii x = pq.top(); pq.pop(); pii y = pq.top(); pq.pop();
        gg[x.s].pb(y.s); gg[y.s].pb(x.s);
        pq.push({x.f+y.f,x.s});
    }
    A = pq.top().f; int id = pq.top().s; pq.pop();
    int B = pq.top().f; pq.pop();
    ddfs(id);
    // debug(A); debug(B);

    for (int v : g[c]){
        if (gp[v]){ // Group A
            val[v] = nat; 
            cout<<c+1<<' '<<v+1<<' '<<(nat - val[c])<<endl;
            nat++;
            dfsA(v,c);
        }
    }
    nat = 1;
    for (int v : g[c]){
        if (!gp[v]){
            val[v] = nat;
            cout<<c+1<<' '<<v+1<<' '<<(nat - val[c])*(A+1)<<endl;
            nat++;
            dfsB(v,c);
        }
    }
    // cout<<"DOFNEOFNEOFNEOFNEOFN"<<endl;
}