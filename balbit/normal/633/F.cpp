#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
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

const int maxn = 1e6+5;

ll a[maxn], lc[maxn], sing[maxn], cs[maxn];
vector<int> g[maxn];
ll re = 0;
void dfs(int v, int p) {
    if (SZ(g[v]) == 1 && p != -1) {
        lc[v] = a[v];
        sing[v] = a[v];
        cs[v] = a[v];
        re = max(re, a[v]);
        return;
    }
    vector<pii> LC={{0,-1}}, SIN={{0,-2}}, CS={{0,-3}};
    for (int u : g[v]) {
        if (u != p) {
            dfs(u,v);
            LC.pb({lc[u],u});
            SIN.pb({sing[u],u});
            CS.pb({cs[u],u});
        }
    }
    sort(ALL(LC),greater<pii>());
    sort(ALL(SIN),greater<pii>());
    sort(ALL(CS),greater<pii>());
    lc[v] = a[v] + LC[0].f;
    sing[v] = max(LC[0].f + LC[1].f + a[v], SIN[0].f);
    cs[v] = CS[0].f + a[v];
    if (SIN[0].s != LC[0].s) cs[v] = max(cs[v], SIN[0].f+LC[0].f+a[v]);
    else cs[v] = max(cs[v], max(SIN[0].f+LC[1].f+a[v], SIN[1].f+LC[0].f+a[v]));

    re = max(re, SIN[0].f + SIN[1].f);
    if (SIN[0].s != LC[0].s && SIN[0].s != LC[1].s) re = max(re, SIN[0].f + a[v] + LC[0].f + LC[1].f);
    else{
        LC.pb({0,-5});
        SIN.pb({0,-6});
        if (SIN[0].s == LC[0].s) {
            re = max(re, SIN[0].f + a[v] + LC[2].f + LC[1].f);
        }
        if (SIN[0].s == LC[1].s) {
            re = max(re, SIN[0].f + a[v] + LC[0].f + LC[2].f);
        }
        if (SIN[1].s != LC[0].s && SIN[1].s != LC[1].s) {
            re = max(re, SIN[1].f + a[v] + LC[0].f + LC[1].f);
        }else{
            if (SIN[1].s == LC[0].s) {
                re = max(re, SIN[1].f + a[v] + LC[2].f + LC[1].f);
            }
            if (SIN[1].s == LC[1].s) {
                re = max(re, SIN[1].f + a[v] + LC[0].f + LC[2].f);
            }
            re = max(re, SIN[2].f + a[v] + LC[0].f + LC[1].f);
        }
    }

    if (CS[0].s != LC[0].s) {
        re = max(re, CS[0].f + LC[0].f + a[v]);
    }else{
        re = max(re, max(CS[1].f + LC[0].f + a[v], CS[0].f + LC[1].f + a[v]));
    }
}


signed main(){
    IOS();
    int n; cin>>n;
    for (int i =0; i<n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i<n-1; ++i) {
        int x,y; cin>>x>>y; --x; --y;
        g[x].pb(y); g[y].pb(x);
    }
    dfs(0,-1);
    cout<<re<<endl;
}