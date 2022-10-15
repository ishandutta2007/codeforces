#include <bits/stdc++.h>
#define int ll
using namespace std;
#define ll long long
#define y1 zck_is_king
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
const ll mod = 998244353;


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

const int maxn = 2e5+5;

ll cnt[maxn];
ll mn[maxn];
bool np[maxn];
vector<int> pf[maxn]; // prime factorization

struct edge{
    int v, u, a, b;
};
vector<edge>g[maxn];

ll sig = 0;

void upd(int x, int dir) {
    for (int y : pf[x]) {
        cnt[y] += dir;
    }
}

void gt(int x) {
    for (int y : pf[x]) {
        MN(mn[y], cnt[y]);
    }
}

void dfs(int v, int p, ll pro) {
    sig += pro; sig %= mod;
    for (edge e : g[v]) {
        if (e.u != p) {
            upd(e.a, -1);
            upd(e.b, 1);
            gt(e.a); gt(e.b);
            dfs(e.u, v, pro * e.b % mod * inv(e.a) % mod);
            upd(e.b, -1);
            upd(e.a, 1);
        }
    }
}

signed main(){
    IOS();

    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            for (int j = i; j<maxn; j+=i) {
                int t = j;
                while (t % i == 0) {
                    t /= i; pf[j].pb(i);
                }
                if (j!=i) {
                    np[j] = 1;
                }
            }
        }
    }

    for (int x : pf[7]) bug(x);

    int T; cin>>T;
    while (T--) {
        int n; cin>>n;
        REP(i,n) g[i].clear();
        REP(i,n-1) {
            int u,v,a,b; cin>>u>>v>>a>>b; --u; --v;
            g[u].pb({u,v,a,b});
            g[v].pb({v,u,b,a});
        }

        REP(i,n+1) {
            mn[i] = cnt[i] = 0;
        }

        sig= 0;

        dfs(0, -1, 1);

        ll first = 1;
        REP(i,n+1) {
            REP(j, -mn[i]) {
                first *= i; first %= mod;
            }
        }
        sig %= mod;
        bug(sig, first);
        cout<<sig * first%mod<<endl;
    }

}