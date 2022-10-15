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

const int gmx = 2520*1000+5;
const int maxn = 1003;
// int par[gmx];
// int len[gmx];


vector<int> g[maxn];
int deg[maxn];
int kv[maxn]; // Mod it first
bool seenat[gmx];
int clen[gmx];

stack<int> stk;
// int target = -1;

void dfs(int at, int nlen){
    if (clen[at]) return;
    // assert(!seenat[at]);
    int v = at/2520; int c = (at%2520 + kv[v]) % 2520; 
    int mm = (c)%deg[v];
    int to = g[v][mm];
    int toid = to*2520+c;
    seenat[at]=1;
    stk.push(at);
    if (seenat[toid]){ // Cycle detected
        if (clen[toid]) clen[at]=clen[toid]; 
        else {
            if (toid==at) {
                clen[at] = 1; return;
            }
            set<int> nn;
            while (stk.top()!=toid){
                nn.insert(stk.top()/2520); stk.pop();
            }
            nn.insert(to);
            clen[at]=nn.size();
        }
    }else{
        dfs(toid, nlen+1); 
        // assert(clen[toid]!=0);
        clen[at]=clen[toid];
    }
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    // setUp(gmx);
    REP(i,n){
        cin>>kv[i]; kv[i]%=2520; kv[i]=(kv[i]+2520)%2520;
    }
    REP(i,n){
        cin>>deg[i];
        REP(j, deg[i]){
            int to; cin>>to;
            g[i].pb(to-1);
        }
    }
    int q; cin>>q;
    while (q--){
        int x, y; cin>>x>>y; y%=2520; y = (y+2520)%2520;
        x--;
        while (!stk.empty()) stk.pop();
        dfs(x*2520+y,0);
        cout<<clen[x*2520+y]<<'\n';
    }
}