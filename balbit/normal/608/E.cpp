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



signed main(){
    IOS();

    int n; cin>>n; --n;
    string a,b; cin>>a>>b;
    for (char &c : b) {
        if (c == 'N' || c == 'S') {
            c ^= 'N'; c ^= 'S';
        }else{
            c ^= 'E'; c ^= 'W';
        }
    }
    bug(a,b);
    ll h1 = 0, h2 = 0;
    ll pp = 1;
    for (int i = n-1; i>=0; --i) {
        bug(a[i], a[i] - 'A');
        h1 += (a[i] - 'A') * pp;
        h2 = h2 * 26 + (b[i] - 'A');
        h2 %= mod; h1 %= mod;
        bug(h1, h2);
        if (h1 == h2) {
            cout<<"NO"<<endl; return 0;
        }
        pp = pp * 26 % mod;
    }
    cout<<"YES"<<endl; //return 1;



}