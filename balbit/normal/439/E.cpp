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

const int iinf = 1e9+5;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

int mo[maxn];
bool isp[maxn];
ll fac[maxn], ifac[maxn];

signed main(){
    IOS();
    fill(isp, isp+maxn, 1);
    fill(mo, mo+maxn, 1);
    fac[0] = ifac[0] = 1; for (int i = 1; i<maxn; ++i) fac[i] = fac[i-1] * i % mod, ifac[i] = inv(fac[i]);
    for (int i = 2; i<maxn; ++i) {
        if (isp[i]) {
            mo[i] = -mo[i];
            for (int j = i+i; j<maxn; j+=i) isp[j] = 0, mo[j] = -mo[j];
            ll sq = i*(ll)i;
            for (ll j = sq; j<maxn; j+=sq) {
                mo[j] = 0; // has squared prime factor
            }
        }
    }
    int q; cin>>q;
    for (int cnt = 0; cnt <q; ++cnt) {
        int n,f; cin>>n>>f;
        ll re = 0;
        for (int d = 1; d*d<=n; ++d) {
            if (n % d == 0) {
                if (mo[d] && n/d>=f) {
                    re += mo[d] * fac[n/d-1] * ifac[f-1] % mod * ifac[n/d-f] % mod;

                }
                if (mo[n/d] && d*d!=n && d>=f) {
                    re += mo[n/d] * fac[d-1] * ifac[f-1] % mod * ifac[d-f] % mod;

                }
            }
        }
        re = (re % mod + mod) % mod;
        cout<<re<<endl;
    }
}