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
const ll mod = 998244353;


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

const int maxn = 2e5+5;


int s[maxn];

ll QU(int e) {
    ll re = 0;
    for (++e; e>0; e-=e&-e) re += s[e];
    return re;
}

void MO(int e, int v) {
    for (++e; e<maxn; e+=e&-e) s[e] += v;
}

ll cnt[maxn];
int S[maxn], T[maxn];
ll fac[maxn], ifac[maxn];

signed main(){
    IOS();
    int n,m; cin>>n>>m;
    fac[0] = ifac[0] = 1;
    REP1(i,maxn-1) {
        fac[i] = fac[i-1] * (ll) i % mod;
        ifac[i] = inv(fac[i]);
    }

    REP(i,n) {
        cin>>S[i];
        ++cnt[S[i]];
        MO(S[i], 1);
    }
    REP(i,m) {
        cin>>T[i];
    }
    ll prod = 1;
    REP(i, maxn) {
        prod = (prod * fac[cnt[i]]) % mod;
    }
    prod = inv(prod);

    ll re = 0;

    REP(i, m) {
        if (i >= n) {
            // over! still here!!
            re += 1; break;
        }
        ll ba = fac[n-i-1] * prod % mod;
        ba *= QU(T[i]-1); ba %= mod;
        bug(ba);
        re += ba; re %= mod;

        if (cnt[T[i]] == 0) break;
        prod *= cnt[T[i]]; prod %= mod;
        cnt[T[i]]--;
//        prod *= inv(cnt[T[i]]); prod %= mod;
        MO(T[i], -1);
    }

    cout<<re % mod<<endl;

}