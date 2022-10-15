#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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

const int maxn = 1e6+5;


signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        ll n,w; cin>>n>>w;
        vector<pii> v;
        ll w2 = (w+1)/2;
        bool done = 0;
        REP(i,n) {
            ll a; cin>>a;
            if (done) continue;
            if (a >= w2 && a <= w) {
                cout<<1<<'\n'<<i+1<<endl;
                done = 1;
            }
            if (a < w2) {
                v.pb({i+1,a});
            }
        }
        if (!done) {
            ll s = 0;
            vector<int> re;
            for (auto & p : v) {
                s += p.s;
                re.pb(p.f);
                if (s >= w2) {
                    break;
                }
            }
            if (s >= w2 && s <= w) {
                cout<<SZ(re)<<endl;
                for (auto x : re) cout<<x<<' ';
                cout<<endl;
            }else{
                cout<<-1<<endl;
            }
        }
    }

}