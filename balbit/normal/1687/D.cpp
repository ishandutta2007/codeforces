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
const ll inf = 0x3f3f3f3f3f3f3f3f;
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

int ps[maxn];
bool A[maxn];
int close[maxn];

signed main(){
    IOS();

    int n; cin>>n;

    int smol = maxn, big = -1;

    REP(i,n) {
        int t; cin>>t;
        A[t] = 1;
        MN(smol, t); MX(big, t);
    }

    for (int j = 1; j<maxn; ++j) {
        ps[j] = A[j] + ps[j-1];
    }

    vector<ll> go;


    for (int i = 1; i<maxn; ++i) {
        if (A[i]) {
            for (int t = 1; t <= 2000000; ++t) { // (t+1)^2 >= (x)
                if (i-t >= 0 && A[i-t]) break;
                if (SQ(t+1) - i >= 0) {
                    go.pb(SQ(t+1) - i);
                }
            }
        }
    }
    go.pb(0);
    SORT_UNIQUE(go);

    ll re = inf;
    {
        ll ha = max(big - smol, 1ll);
        while (SQ(ha) + ha < big) {
            ++ha;
        }
        MN(re, max(0ll, SQ(ha) - smol));
    }
    bug(re);

    for (ll x : go) {
//        bug(x);
        if (x < re) {
            ll frst = x + smol;
            ll y = sqrt(frst) + 1e-6;
            while (y*y > frst) --y;
            assert(y*y <= frst && SQ(y+1) > frst);
            ++y;
            while (y*y-y < x+big) {
                if (ps[min(maxn-1,y*y-1-x)] - ps[max(0ll, y*y-y-x)]) {
                    goto nope;
                }
                ++y;
            }
            bug(x);
            MN(re, x); break;
            nope:;
        }
    }
    cout<<re<<endl;
}