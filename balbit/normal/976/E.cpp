#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; --i)
#define REP1(i,n) FOR(i,1,n+1)
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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

const int maxn = 2e5+5;

bool tk[maxn];

signed main(){
    IOS();

    int n, a, b; cin>>n>>a>>b;
    MN(b,n);
    vector<pii> v(n);
    ll re = 0;
    vector<pii> bst;
    ll base = 0;
    REP(i,n) {
        cin>>v[i].f>>v[i].s; base += v[i].s;
        bst.pb({v[i].f-v[i].s,i});
    }
    if (b==0) {
        cout<<base<<endl;
        return 0;
    }
    sort(ALL(bst), greater<pii>());
    ll b1 = 0, b2 = 0;
    REP(i,b-1) {
        if (bst[i].f>0) b1+=bst[i].f, tk[bst[i].s]=1;
    }
    b2=b1; if (bst[b-1].f>0) b2+=bst[b-1].f;
    REP(i,n) {
        ll hpto = (ll)v[i].f << a;
        ll ex = b1; if (tk[i]) ex = b2-(v[i].f-v[i].s);
        MX(re, max(hpto-v[i].s,0ll)+ex);
    }
    cout<<re+base<<endl;

    // Make sure to check for edge cases, input bounds
}