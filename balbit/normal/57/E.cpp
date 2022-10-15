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

const int maxn = 1e5+5;

bool has[2005][2005];
int CEN = 1000;

vector<pii> active;
vector<pii> P;
vector<int> his;

void nextlay(){
    vector<pii> nw;
    for (pii p : active) {
        for (pii dir : P) {
            int nx = p.f + dir.f, ny = p.s + dir.s;
            if (!has[nx][ny]) {
                has[nx][ny] = 1;
                nw.pb({nx, ny});
            }
        }
    }
    active.swap(nw);
    his.pb(SZ(active));
}

ll boi(ll a, ll d, ll n) {
    // starting, diff, number of terms
    a %= mod; d %= mod; n %= mod;
    return (a + a + d*(n-1)) % mod * n % mod * inv(2) % mod;
}

signed main(){
    IOS();

    for (int i = -2; i<=2; ++i) for (int j = -2; j<=2; ++j) {
        if (abs(i) + abs(j) == 3) {
            P.pb({i,j});
        }
    }
    ll k, n; cin>>k>>n;

    active.pb({CEN, CEN});
    has[CEN][CEN] = 1;
    his.pb(1);

    REP(i,n) {
        int x,y; cin>>x>>y;
        has[CEN-x][CEN-y] = 1;
    }

    REP(tt, 100) {
        nextlay();
    }

    if (k < SZ(his)) {
        ll sig = 0;
        REP(j, k+1) {
            bug(j, his[j]);
            sig += his[j];
        }
        cout<<sig<<endl;
        return 0;
    }

    ll sig = 0;
    for (ll t : his) sig += t;
    ll df = his.back() - his[SZ(his)-2]; // assume we continue this df forever

    ll adon = boi(his.back()+df, df, k - SZ(his) + 1);
    bug(sig, df, adon);
    cout<<(sig + adon)%mod<<endl;


}