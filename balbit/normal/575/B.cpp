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

const int maxn = 1e5+5;
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

int dep[maxn], sz[maxn], fa[21][maxn];
int ds[maxn], us[maxn]; // Down sum, up sum
int id[maxn];
vector<int> g[maxn];
ll p2[(int)(1e6+5)];

void dfs1(int v){
    for (int u : g[v]){
        if (!dep[u]) {
            dep[u]=dep[v]+1;
            fa[0][u]=v;
            dfs1(u);
        }
    }
}

bool seen[maxn];
ll re = 0;

void dfs2(int v){
    seen[v]=1;
    for (int u : g[v]){
        if (!seen[u]){
            dfs2(u);
            ds[v]+=ds[u]; us[v]+=us[u];
        }
    }
    if (id[v]==1) {

        re += p2[ds[v]]-1+mod;
    }else if (id[v]==2){

        re += p2[us[v]]-1+mod;
    }
    re%=mod;
}

void build(){
    p2[0]=1;
    FOR(i,1,1e6+5){
        p2[i]=p2[i-1]*2 % mod;
    }
    FOR(i,1,21){
        REP(j,maxn){
            fa[i][j]=fa[i-1][fa[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if (dep[a]<dep[b]) swap(a,b);
    int need = dep[a]-dep[b];
    int j = 0;
    while (need){
        if (need&1) a = fa[j][a];
        j++; need/=2;
    }
    RREP(j,21){
        if (fa[j][a]!=fa[j][b]) {
            a = fa[j][a]; b = fa[j][b];
        }
    }
    if (a==b) return a;
    return fa[0][a];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    REP(i,21) fill(fa[i], fa[i]+maxn,-1);
    int n; cin>>n;
    vector<pair<pii, int> > v;
    REP(i,n-1){
        int a, b, t; cin>>a>>b>>t; a--; b--;
        v.pb({{a,b},t});
        g[a].pb(b); g[b].pb(a);
    }
    dep[0]=1;
    dfs1(0); build();
    REP(i,n-1){
        if (v[i].s==0) continue;
        int a = v[i].f.f, b = v[i].f.s;
        if (a == fa[0][b]){
            // cout<<"DOWN"<<endl;
            id[b]=2; // Going Down
        }else{
            // cout<<"DOWNUP"<<endl;
            id[a]=1; // Going Up
        }
    }
    int k; cin>>k;
    vector<int> vm;
    vm.pb(0);
    REP(i,k){
        int a; cin>>a; a--;
        
        int b = vm.back();
        // b -> a
        int c = lca(a,b);
        // cout<<a<<' '<<b<<' '<<c<<endl;
        us[b]++; us[c]--; 
        ds[a]++; ds[c]--;
        
        vm.pb(a);
    }
    dfs2(0);
    cout<<re<<'\n';
}