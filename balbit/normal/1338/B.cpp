#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

vector<int> g[maxn];
bool lf[maxn];
int dep[maxn];
int XX[2];
int nlf = 0;
bool one = 1;
int aleaf = -1;
bool dp[maxn][4];
int re = 0;
void dfs(int v, int p) {
    if (SZ(g[v]) == 1) ++nlf;
    if (SZ(g[v]) == 1 && p != -1) dp[v][0] = 1;
    int nlch = 0;
    int nch = 0;
    for (int u : g[v]) {
        if (SZ(g[u]) == 1) nlch ++;
        if (u != p) {
            dep[u] = dep[v] + 1;

            dfs(u,v);
            nch++;
        }
    }
    if (nlch) re += nlch - 1;
    if (nch) for (int i = 0; i<4; ++i) {
        for (int me = 1; me <=2; ++me) {
            bool bp = 1;
            for (int u : g[v]) {
                if (u!=p) {
                    bp = bp & dp[u][i^me];
                }
            }
            if (bp) {dp[v][i] = 1; bug(v,i);}
        }
    }
    if (SZ(g[v]) == 1) {
        XX[dep[v]%2] ++;
    }
}

signed main(){
    IOS();
    int n; cin>>n;
    for (int i = 0; i<n-1; ++i) {
        int a,b; cin>>a>>b; --a; --b;
        g[a].pb(b); g[b].pb(a);
    }
    dfs(0,-1);
    if (XX[0] == 0 || XX[1] == 0) cout<<1<<' ';
    else{

        if (0&&*max_element(dp[0],dp[0]+4)) cout<<2<<' ';
        else cout<<3<<' ';
    }
    cout<<n-re-1<<endl;


}