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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 5e5+5;

int np[maxn], mo[maxn];

signed main(){
    IOS();
    fill(mo, mo+maxn, 1);
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            mo[i]=-mo[i];
            for (int j = i+i; j<maxn; j+=i) {
                np[j] = 1; mo[j] = -mo[j];
            }
            ll sq = i*(ll)i;
            for (ll j = sq; j < maxn; j+=sq) mo[j]=0;
        }
    }
    bug(mo[2], mo[3], mo[4], mo[5], mo[6]);
    int n,q; cin>>n>>q;
    vector<ll> a(n);
    vector<vector<ll> > fac(n);
    for (int i = 0; i<n; ++i ) {
        cin>>a[i];
        for (int j = 1; j<=sqrt(a[i]); ++j) {
            if (a[i] % j == 0) {
                fac[i].pb(j);
                if (j * j != a[i]) fac[i].pb(a[i]/j);
            }
        }
    }
    ll pans =0 ;
    vector<int> st(n,0);
    vector<ll> nof(maxn);
    while (q-- ){
        int at; cin>>at; --at;
        for (ll F : fac[at]) {
            pans -= mo[F] * (nof[F] * (nof[F]-1) / 2);
            st[at]? nof[F] -- : nof[F]++;
            pans += mo[F] * (nof[F] * (nof[F]-1) / 2);
        }
        st[at] ^=1;
        cout<<pans<<endl;
    }


}