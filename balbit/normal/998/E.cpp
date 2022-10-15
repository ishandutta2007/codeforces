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

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 998244353;


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

const int maxn = 1e5+5;

int g[3][3];

int Vova = 0;
int Bot = 0;

void dfs(int at) {
    if (at == 9) {
        bool ok = 0, ok2=0;
        REP(i,3) {
            if (g[i][0] == g[i][1] && g[i][1] == g[i][2]) ok=1;
        }
        REP(i,3) {
            if (g[0][i] == g[1][i] && g[1][i] == g[2][i]) ok2=1;
        }
        Vova+=ok;
        Bot += ok && ok2;
    }else{
        REP(i,3) {
            g[at/3][at%3]=i; dfs(at+1);
        }
    }
}

main(){
    IOS();
    #ifdef BALBIT
    dfs(0);
    cout<<Vova<<endl;
    bug(Bot);
    #endif
    ll n; cin>>n;
    ll freecol = mpow(mpow(3,n)-3,n); if (freecol<0) freecol+=mod;
    bug(freecol);
    ll neg = 1;
    ll Cni = 1;
    FOR(i,1,n+1){
        neg = -neg;
        Cni = Cni * (n-i+1) %mod * inv(i) % mod;
        bug(i,Cni);
        ll tmp = mpow(3,n-i);
        freecol = freecol + neg * 3 * Cni % mod * mpow(tmp-1,n) % mod;
        freecol %= mod;
        freecol = freecol + neg * (mpow(3,i)-3) * Cni % mod * mpow(tmp,n) % mod;
        freecol = freecol%mod; if (freecol<0) freecol += mod;
    }
    cout<<(mpow(3,n*n)-freecol+mod)%mod<<endl;
}