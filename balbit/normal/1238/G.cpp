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
const ll mod = 1e9+87 ;


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

ll gogo(){
    int n,m,c, init;
    cin>>n>>m>>c>>init;
    multiset<pii> pq;// weight, amount
    vector<pair<int, pii> > ev;
    ev.pb({m, {0, 0}});
    REP(i,n) {
        int t,a,b; cin>>t>>a>>b;
        ev.pb({t, {b,a}});
    }
    sort(ALL(ev));
    ll prv = 0;
    ll re = 0;
    pq.insert({0, init});
    ll nat = init;

    auto crunch = [&](ll need, bool add) {
        while (need) {
            if (SZ(pq) == 0) {
                assert(0);
            }
            pii p = add?*pq.begin() : *pq.rbegin(); pq.erase(pq.find(p));

            int yum = min(need, p.s);
            p.s -= yum; need -= yum; nat-=yum;

            if (add) re += yum * p.f;

            bug(yum, p.f);
            if (p.s) {
                pq.insert(p);
            }
        }
        return 0;
    };

    for (auto E : ev) {
        ll tt = E.f;
        ll need = tt - prv;
        if (nat < need) return -1;
        crunch(need, 1);
        pq.insert(E.s);
        nat += E.s.s;
        if (nat > c) {
            crunch(nat - c, 0);
        }
        prv = E.f;
    }
    return re;
}

signed main(){
    IOS();
    int T; cin>>T;
    while (T--) {
        ll yo = gogo();
//        if (yo == -1)
            cout<<yo<<endl;
    }



}