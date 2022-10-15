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
//const ll mod = 1e9+7 ;
ll mod;

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

ll n;
ll g[maxn], f[maxn];
vector<int> pof;
int np[maxn][10];

void build(){
    {
        ll tp = mod;
        for (int i = 2; i<=sqrt(mod); ++i) {
            if (tp % i == 0) {
                pof.pb(i); bug(i);
                while (tp % i == 0) tp /= i;
            }
        }
        if (tp != 1) {
            pof.pb(tp); bug(tp);
        }
    }
    f[0]=1;
    for (int i = 1; i<maxn; ++i) {
        g[i] = i;
        while (__gcd(g[i],mod) != 1) g[i] /= __gcd(g[i],mod);
        f[i] = f[i-1] * g[i] % mod;

        int ti = i;
        for (int j = 0; j<SZ(pof); ++j) {
            np[i][j] = np[i-1][j];
            while (ti % pof[j] == 0) ++np[i][j], ti/=pof[j];
        }
    }
}

ll non_prime_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll C(int a, int b) {
    if (a < b || b < 0) return 0;
    ll re = f[a] * non_prime_inv(f[b] * f[a-b] % mod, mod) % mod;
    for (int j = 0; j<SZ(pof); ++j) {
        (re *= mpow(pof[j], np[a][j] - np[b][j] - np[a-b][j], mod)) %= mod;
    }
    return re;
}

inline int divv(int a, int b) {
    return a/b - ((a^b)<0 && a%b);
}

ll gt(ll R) {
    bug(R);
    if (R < 0) return 0;
    ll re = 0;
    for (int i = 0; i<=n; ++i) {
        ll me = C(n,i) * (C(i,divv(i-R,2))) % mod;
        re += me;
    }
    return (re % mod + mod) % mod;
}

signed main(){
    IOS();
    int l,r; cin>>n>>mod>>l>>r;
    build();
    bug(C(3,2), C(6,3));
    ll mr = gt(l), ml = gt(r+1);
    bug(ml, mr);
    cout<<(mr-ml+mod)%mod<<endl;


}