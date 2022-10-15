#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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

ll w[maxn];

signed main(){
    IOS();
    ll n,k; cin>>n>>k; --k;
    for (int i = 2; i<=n; ++i) {
        ll p,wi; cin>>p>>wi;
        w[i-1] = w[p-1] ^ wi;
    }
    ll re = 0;
    sort(w, w+n);
    vector<ll> v(n);
    REP(i,n) v[i] = w[i];
    ll msk = 0;
    for (int m = 62; m>=0; --m) {
        ll V = re;
//        vector<ll> newv = v;
        msk |= (1ll<<m);
        int nof = 0;
        int j = 0;
        ll tadd = 0;
        for (int i = 0; i<=n; ++i) {
            if (i) if (i == n || (w[i] & msk) != (w[i-1] & msk)) {
                while (j<n && ((v[j] & msk) ^ V) < (w[i-1]&msk)) ++j;
                int J = j;
                while (j<n && ((v[j] & msk) ^ V) == (w[i-1]&msk)) ++j;
                tadd += nof * (ll) (j-J);
                nof = 0;
            }
            ++nof;
        }
        bug(tadd);
        if (k-tadd>=0 ) {
            re |= (1ll<<m);
            int st = 0, s1=-1;
            msk ^= (1ll<<m);
            for (int i = 0; i<=n; ++i) {
                if (i) if (i == n || (v[i]&msk) != (v[i-1] & msk) ) {
                    if (s1!=-1) rotate(v.begin() + st, v.begin()+s1, v.begin()+i);
                    st = i; s1=-1;
                }
                if (i != n && s1 == -1 && (v[i] & (1ll<<m))) {
                    s1 = i;
                }
            }
            msk ^= (1ll<<m);
            k -= tadd; //re = V;
        }
    }
    cout<<re<<endl;

}