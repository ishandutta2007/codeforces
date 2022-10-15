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

const int maxn = 1e6+5;

//int gt(vector<int> x){
//    int re = 0;
//    REP(i, SZ(x)) REP(j, i) {
//        if (x[i] == x[j]) re += i-j;
//    }
//    return re;
//}
//
//void go(vector<int> a) {
//    vector<vector<int> > bst;
//    int yay = -1;
//    do{
//        int t = gt(a);
//        if (t > yay) {
//            yay = t; bst.clear();
//        }
//        if (t == yay) {
//            bst.pb(a);
//        }
//    }while (next_permutation(ALL(a)));
//    cout<<yay<<endl;
//    bug(SZ(bst));
////    for (auto x : bst) {
////        for( int y : x) cout<<y<<' ';
////        cout<<endl;
////    }
//    cout<<"===="<<endl;
//}

ll cnt[maxn], fac[maxn];
ll dat[maxn];

signed main(){
    IOS();

//    array<int, 4> r;
//    REP(i,4) cin>>r[i];
//    vector<int> hi;
//    REP(i,4) {
//        REP(j, r[i]) hi.pb(i);
//        go(hi);
//    }
    fac [0] = 1;
    for (int i = 1; i<maxn; ++i) {
        fac[i] = fac[i-1] * (ll) i % mod;
    }
    int n; cin>>n;
    vector<int> a(n);
    REP(i,n) {
        cin>>a[i];
        ++cnt[a[i]];
    }
    for (int i = maxn-3; i >=1; --i) {
        cnt[i] += cnt[i+2];
    }
    ll re = 1;
    ll sigpos0 = 0, sigpos1 = 0;
    deque<pair<ll, int> > tmp;
    ll sig = 0;
    ll now = 0;
    REP1(i, maxn-1) {
//        cnt[i] %= mod;
        re *= fac[cnt[i]];
        re %= mod;

        if (i>1) {
            re *= fac[cnt[i]];
            re %= mod;

            sig += (i*2-2) * (ll)(now + cnt[i]) % mod * cnt[i] % mod;
        }

        if (i == 1) {
            now += cnt[i];
        }else{
            now += 2 * cnt[i];
        }

    }

    sig %= mod;

    sig *= inv(2); sig %= mod;

    cout<<sig%mod<<' '<<re<<endl;
}