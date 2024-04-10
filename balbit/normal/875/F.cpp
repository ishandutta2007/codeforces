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

vector<pii> g[maxn];

int par[maxn];
bool ex[maxn];

int find (int x ) {
    if (x == par[x]) return x; return par[x] = find(par[x]);
}

signed main(){
    IOS();

    int n,m; cin>>n>>m;
    REP1(i,n) {
        par[i] = i;
    }
    vector<pair<int, pii> > v;
    ll re = 0;
    REP(i,m) {
        int a,b,w; cin>>a>>b>>w;
        re += w;
        v.pb({w,{a,b}});
    }
    sort(ALL(v)); reverse(ALL(v));
    for (auto u : v) {
        int a = u.s.f, b = u.s.s;
        a = find(a); b = find(b);
        if (a!=b) {
            if (ex[a] && ex[b]) re -= u.f;
            else {
            par[a] = b; ex[b] |= ex[a];

            }
        }else{
            if (!ex[a]) {
                ex[a] = 1;
            }else re -= u.f;
        }
    }
    cout<<re<<endl;
}