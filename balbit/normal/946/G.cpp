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

const int iinf = 1e9+10;
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


signed main(){
    IOS();
    int n; cin>>n;
    vector<ll> lis(n+2,inf);
    vector<pair<ll, ll> > rev;
    vector<ll> a(n);
    REP(i,n){
        cin>>a[i]; a[i] -= i;
        ll it = upper_bound(ALL(lis),a[i]) - lis.begin();
//        bug(it);
        rev.pb({it, lis[it]});
        lis[it] = min(lis[it],a[i]);
    }
    ll ls = lower_bound(ALL(lis),inf) - lis.begin();

    vector<ll> lds(n,-inf);
    REP(i,n) a[i] ++;
    lis[rev[n-1].f] = rev[n-1].s;
    for (int i = n-1; i>=1;i--){
        int it = upper_bound(ALL(lds),a[i], greater<ll>()) - lds.begin();
        bug(it);
        lds[it] = a[i];
        lis[rev[i-1].f] = rev[i-1].s;
        MX(ls, rev[i-1].f + upper_bound(ALL(lds),rev[i-1].s,greater<ll>()) - lds.begin() + 1);
        MX(ls, upper_bound(ALL(lis),a[i]) - lis.begin() + it + 1);
    }
    bug(ls);
    if (ls == n) cout<<0<<endl;
    else cout<<n-ls-1<<endl;
}