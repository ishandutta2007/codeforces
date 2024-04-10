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

//const int maxn = 1e5+5;

ll dp[30004];
int to[30004];
ll pr[30004][4];

ll a[30004], b[30004];
int where[30004];
int whereb[30004];

signed main(){
    IOS();

    int n,q; cin>>n>>q;
    vector<pii> A,B;
    REP1(i,n) {
        cin>>a[i];
        A.pb({a[i], i});
    }
    REP1(i,n) {
        cin>>b[i];
        B.pb({b[i], i});
    }
    sort(ALL(A));
    sort(ALL(B));
    REP(i,n) {
        whereb[B[i].s] = i+1;
    }
    REP(i,n) {
        a[i+1] = A[i].f;
        b[i+1] = B[i].f;
        to[i+1] = whereb[A[i].s];
        where[A[i].s] = i+1;
    }

    REP1(i,n) {
        pr[i][0] = a[i] * b[i];
        if (i>1) pr[i][1] = a[i] * b[i-1] + b[i] * a[i-1];
        if (i > 2) pr[i][2] = a[i] * b[i-2] + a[i-1] * b[i] + a[i-2] * b[i-1];
        if (i > 2) pr[i][3] = a[i] * b[i-1] + a[i-1] * b[i-2] + a[i-2] * b[i];
    }

    REP1(i,n) {
        bug(i, a[i], b[i], to[i]);
    }

    REP(qq,q) {
        int x,y; cin>>x>>y;
        x = where[x]; y = where[y];
        swap(to[x], to[y]);
        REP1(i,n) {
            dp[i] = -inf;
            if (to[i] != i) MX(dp[i], pr[i][0] + dp[i-1]);
            if (i > 1 && to[i] != i-1 && to[i-1] != i) MX(dp[i], pr[i][1] + dp[i-2]);
            if (i>2) {
                if (to[i] != i-2 && to[i-1] != i && to[i-2] != i-1) MX(dp[i], pr[i][2] + dp[i-3]);
                if (to[i] != i-1 && to[i-1] != i-2 && to[i-2] != i) MX(dp[i], pr[i][3] + dp[i-3]);
            }
        }
        cout<<dp[n]<<endl;
    }

}