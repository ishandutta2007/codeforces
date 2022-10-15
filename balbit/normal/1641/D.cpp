#include <bits/stdc++.h>
//#define int ll
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

vector<vector<int> > all;
vector<int> a[maxn];
vector<pii> who[maxn]; // {index, popcount}

int yay[maxn <<5];
int wei[maxn];

int nin = 0; // number of things inside set

void upd(int x, int dir) {
    nin += dir;
    for (pii p : who[x]) {
        yay[p.f] += dir;
    }
}

int get(int x) {
    // return the number of things diff from me
    int re = 0;
    for (pii p : who[x]) {
        re += (p.s?1:-1) * yay[p.f];
    }
    return nin - re;
}

unsigned ll H[maxn*5];

signed main(){
    IOS();

    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

    int n; cin>>n;

    REP(i,n*5) {
        H[i]=rnd();
        bug (i, H[i]);
    }

    int m; cin>>m;

    vector<int> alla;

    REP(i,n) {
        a[i].resize(m);
        REP(j,m) cin>>a[i][j], alla.pb(a[i][j]);
        cin>>wei[i];
        sort(ALL(a[i]));
    }

    SORT_UNIQUE(alla);

    REP(i,n) {
        for (int &x : a[i]) {
            x = lower_bound(ALL(alla), x) - alla.begin();
        }
    }

    vector<unsigned ll> all;

    REP(i,n) {
        REP1(msk, (1<<m)-1) {
            unsigned ll tt = 0;
            REP(j,m) {
                if (msk & (1<<j)) {
                    tt ^= H[a[i][j]];
                }
            }
            all.pb(tt);
        }
    }

    SORT_UNIQUE(all);

    REP(i,n) {
        REP1(msk, (1<<m)-1) {
            unsigned ll tt = 0;
            REP(j,m) {
                if (msk & (1<<j)) {
                    tt ^= H[a[i][j]];
                }
            }
            who[i].pb({lower_bound(ALL(all), tt) - all.begin(), __builtin_popcount(msk)%2});
        }
    }

    vector<pii> where;

    REP(i,n) {
        upd(i,1);
        where.pb({wei[i], i});
    }

    sort(ALL(where));
//    return 0;

    int re = 2000000004;
    int at = n-1;
    REP(i,n) {

        while (get(where[i].s) > 0) {
            bug(at);
            MN(re, wei[where[i].s] + wei[where[at].s]);
            upd(where[at].s, -1);
            --at;
        }
    }
    if (re == (2000000004)) re = -1;
    cout<<re<<endl;
}