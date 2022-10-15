#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define y1 zck_is_king
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
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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


void GG(){cout<<"NO\n"; exit(0);}

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

const int maxn = 2e5+5;

vector<pii> g[maxn];
bool ban[maxn];
//int par[maxn];
int sz[maxn];
int targ, targ2;
int f[maxn];
int which[maxn];
pii gt, gt2;

int e = -1, e2 = -1;

void dfs(int v, int p) {
    sz[v] = 1;
    for (pii u : g[v]) {
        if (!ban[u.s] && u.f != p) {
            dfs(u.f, v);
            sz[v] += sz[u.f];
            if (sz[u.f] == targ || sz[u.f] == targ2) {
                pii ho = (sz[u.f] == targ?pii{u.f,v}:pii{v, u.f});
                if (e == -1) {
                    gt = ho;
                    e = u.s;
                }else{
                    gt2=ho;
                    e2=u.s;
                }
            }
        }
    }
}

//int run(int v, int p) {
//    for (pii u : g[v]) {
//        if (!ban[u.s] && u.f != p) return run(u.f, v);
//    }
//    return v;
//}

bool decomp(int v, int lv) {
    if (lv <= 1) return 1;
//    v = run(v, -1);
    gt = {-1, -1}; e = -1;
    gt2 = {-1, -1}; e2 = -1;
    targ = f[lv-2]; targ2 = f[lv-1];
    dfs(v, -1);
    if (e == -1) return 0;
    int E = e;
    ban[e] = 1;
    int A = gt.f, B = gt.s;
    int A2 = gt2.f, B2=gt2.s, E2 = e2;
    if (!decomp(A,lv-2)) {
        if (E2 == -1) {
            ban[E] = 0; return 0;
        }
        ban[E] = 0; ban[E2] = 1;
        if (!decomp(A2, lv-2) || !decomp(B2, lv-1)) {
            ban[E2]=0;
            return 0;
        }
        ban[E2]=0;
        return 1;
    }else{
        bool bb =  decomp(B, lv-1);
        ban[E] = 0;
        if (bb) return 1;
        else{
            return 0;
            if (E2 == -1) {
                ban[E] = 0; return 0;
            }
            ban[E] = 0; ban[E2] = 1;
            if (!decomp(A2, lv-2) || !decomp(B2, lv-1)) {
                ban[E2]=0;
                return 0;
            }
            ban[E2] = 0;
            return 1;
        }
    }


}

signed main(){
    IOS();
    memset(which, -1, sizeof which);
    f[0]=f[1]=1; which[1] = 0;
    for (int i = 2; ; ++i) {
        f[i] = f[i-1] + f[i-2];
        if (f[i] >= maxn) break;
        which[f[i]] = i;
    }
    int n; cin>>n;
    REP(i,n-1){
        int a,b; cin>>a>>b; --a; --b; g[a].pb({b,i}); g[b].pb({a,i});
    }
    if (which[n] == -1) GG();
    if (!decomp(0,which[n])) GG();
    cout<<"YES"<<endl;
}