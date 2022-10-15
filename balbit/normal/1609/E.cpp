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

const int M = 4e5+5;

int a[M], b[M],c[M], ab[M], bc[M], abc[M];

char s[M];

void pull(int o) {
    int lc = o*2;
    int rc = o*2+1;
    a[o] = a[lc] + a[rc];
    b[o] = b[lc] + b[rc];
    c[o] = c[lc] + c[rc];
    ab[o] = min(a[o], b[o]);
    bc[o] = min(b[o], c[o]);
    MN(ab[o], min(ab[lc] + b[rc], a[lc] + ab[rc]));
    MN(bc[o], min(bc[lc] + c[rc], b[lc] + bc[rc]));
    abc[o] = min({a[o], b[o], c[o]});
    MN(abc[o], abc[lc] + c[rc]);
    MN(abc[o], a[lc] + abc[rc]);
    MN(abc[o], ab[lc] + bc[rc]);
}

void MO(int p, int which, int val, int o, int l, int r) {
    if (l > p || r < p) return;
    if (l == r) {
        a[o] = b[o] = c[o] = ab[o] = bc[o] = abc[o] = 0;
        if (which == 0) a[o] = 1;
        if (which == 1) b[o] = 1;
        if (which == 2) c[o] = 1;
        return;
    }
    int mid = (l+r)/2;
    MO(p, which, val, o*2, l, mid);
    MO(p, which, val, o*2+1, mid+1,r);
    pull(o);
}

signed main(){
    IOS();
    int n,q; cin>>n>>q;
    memset(s, 'z', sizeof s);
    REP(i,n) {
        cin>>s[i];
        MO(i, s[i] - 'a', 1, 1, 0, n-1);
    }
    REP(i,q) {
        int j; char c; cin>>j>>c; --j;
        MO(j, c - 'a', 1, 1, 0, n-1);
        cout<<abc[1]<<endl;
    }

}