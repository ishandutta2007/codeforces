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
#define REP(i,n) for (int i = 0; i<n; ++i)
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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 2e6+5;

int V[maxn];
vector<int> g[maxn];
int dp[maxn][2];

int re = 0;

inline void upd(int &f1, int &f2, int nw) {
    if (nw > f1) {
        f2=f1; f1=nw;
    }else if (nw > f2) {
        f2=nw;
    }
}

int LIM = 0;
vector<int> ord;
int mp [maxn];
void predfs(int v, int p) {
    mp[v] = p;
    for (int u : g[v]) {
        if (u != p) {
            predfs(u,v);
        }
    }
    ord.pb(v);
}

inline void go(int v) {
    int p = mp[v];
    dp[v][0] = dp[v][1] = 0;
    int f01=0,f02=0,f11=0,f12=0;
    for (int u : g[v]) {
        if (u != p) {
            if (V[v] & 1) {
                MX(dp[v][0], min(dp[u][0], dp[u][1] + 1));
                upd(f01,f02,min(dp[u][0], dp[u][1] + 1));
            }
            if (V[v] & 2) {
                MX(dp[v][1], min(dp[u][1], dp[u][0] + 1));
                upd(f11,f12,min(dp[u][1], dp[u][0] + 1));
            }
        }
    }
    if (!(V[v] & 1) || f01 + f02 > LIM) {
        dp[v][0] = 10000000;
    }
    if (!(V[v] & 2) || f11 + f12 > LIM) {
        dp[v][1] = 10000000;
    }
}

signed main(){
    IOS();
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        REP(i,n) cin>>V[i], V[i] += !V[i]?3:0;
        REP(i,n) g[i].clear();
        REP(i,n-1) {
            int a,b; cin>>a>>b; --a; --b;
            g[a].pb(b); g[b].pb(a);
        }
        ord.clear();
        predfs(0,-1);
        int l = 0, r = n-1;
        while (l != r) {
            LIM = (l+r)/2;
            for (int x : ord) go(x);
            if (dp[0][0] < n || dp[0][1] < n) {
                r = LIM;
            }else{
                l = LIM+1;
            }
        }
        bug(l);
        cout<<(l+1)/2+1<<endl;
    }


}