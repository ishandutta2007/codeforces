#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast", "unroll-loops")
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
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
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
 
const int maxn = 300;
 
vector<int> g[maxn];
int dp[maxn][maxn];
int D;
int n;
int w[maxn];

int f(int v, int d, int p){
    if (d >= n) return 0;
    if (dp[v][d]!=-1) return dp[v][d];
    if (d==0){
        int s = 0;
        for(int u: g[v]){
            if (u!=p) s+=f(u,D-1,v);
        }
        return dp[v][d] = max(f(v,d+1,p), s+w[v]);
    }
    if (d+d<D){
        int s = 0; for (int u : g[v]) if (u!=p) s += f(u, D-d-1,v);
        int re = 0;
        for (int u : g[v]){
            if (u!=p) MX(re, s-f(u,D-d-1,v)+f(u,d-1,v));
        }
        return dp[v][d] = max(f(v,d+1,p),re);
    }else{
        ll re = 0;
        for (int u : g[v]) if (u!=p) re += f(u,d-1,v);
        return dp[v][d] = re;
    }
}
 
main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
 
    cin>>n>>D; D++;
    REP(i,n) cin>>w[i];
    REP(i,n) REP(j,n) dp[i][j] = -1;
    REP(i,n-1){
        int a, b; cin>>a>>b; a--; b--;
        g[a].pb(b); g[b].pb(a);
    }
    // cout<<"ALIVE"<<endl;
    cout<<f(0,0,0)<<endl;
 
    
}