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

vector<vector<int> > lft[20];

vector<pii> re;


signed main(){
    IOS();

    int n; cin>>n;
//    auto cmp = [&](vector<int> a, vector<int> b){return SZ(a) < SZ(b);};
//    priority_queue<vector<int>, vector<vector<int> >, decltype(cmp)> pq(cmp);

    for (int i = 0; i<n; ++i) {
        lft[0].pb({i+1});
    }
    int big = 0;
    int piles = 0;
    for (int i = 0; ; ++i) {
        if (SZ(lft[i]) < 1) {
            big = i-1; break;
        }
        while (SZ(lft[i]) >= 2) {
            vector<int> a = lft[i].back(); lft[i].pop_back();
            vector<int> b = lft[i].back(); lft[i].pop_back();
            for (int j = 0; j<SZ(a); ++j) {
                re.pb({a[j], b[j]});
            }
            for (int y : b) a.pb(y);
            lft[i+1].pb(a);
        }
        piles += SZ(lft[i]) == 1;
    }
    bug(piles);
//    return 0;
    vector<int> bg = lft[big][0];
    lft[big].pop_back();
    for (int i = 0; piles > 2; ++i) {
        while (SZ(lft[i]) >= 2) {
            vector<int> a = lft[i].back(); lft[i].pop_back();
            vector<int> b = lft[i].back(); lft[i].pop_back();
            for (int i = 0; i<SZ(a); ++i) {
                re.pb({a[i], b[i]});
            }
            for (int y : b) a.pb(y);
            lft[i+1].pb(a);
            piles --;
        }
        if (SZ(lft[i])==1) {
            vector<int> ex;
            for (int j = 0; j<SZ(lft[i][0]); ++j) {
                re.pb({lft[i][0][j], bg.back()}); ex.pb(bg.back());bg.pop_back();
            }
            for (int y : lft[i][0]) ex.pb(y);
            lft[i+1].pb(ex);
        }
    }
    cout<<SZ(re)<<endl;
    for (pii & p : re) cout<<p.f<<' '<<p.s<<endl;
}