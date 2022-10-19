#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<vvpi> vvvpi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef complex<double> cd;
typedef vector<cd> vcd;

typedef unsigned int uint;

template<class C> void mini(C&a, C b){ a=min(a, b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end();it++)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(int) s; i<(int)(n); i++)
#define todo(v) v.begin(),v.end()
#define PI acos(-1.0)
#define fora(e,v) for(auto e : v)
const int mod = 31607;
const ll INF  = 1e18;
const double eps = 0.00000001;

int n;

int powmod(int a, int exp){
    if(exp == 0) return 1;
    int b = powmod(a,exp/2);
    b *= b;
    b %= mod;
    if(exp%2) b *= a;
    b %= mod;
    return b;
}

int inv(int a){
    return powmod(a,mod-2);
}

int inv1e4 = inv(1e4);

int INV[mod];

int dp[4][(1<<21)],aux[(1<<21)];

void nxt(int& msk, int& proba, vi& a){
    int j = 0;
    while(j < n and (msk & (1<<j))) {
        int psi = a[j] * inv1e4 % mod;
        proba *= INV[psi];
        proba %= mod;
        j++;
    }
    if(j < n) proba = (proba * a[j]) % mod * inv1e4, proba %= mod;
    msk++;
}

void F(){
    F1(x,mod-1) INV[x] = inv(x);
    cin>>n;
    vvi a(n,vi(n));
    F0(i,n) F0(j,n) cin>>a[i][j];
    F0(j,4) F0(i,(1<<n)) dp[j][i] = 1;

    int diag = n;
    int contradiag = n+1;

    vi fila_llena(n);
    F0(i,n){
        int proba = 1;
        int msk = 0;
        while(msk < (1<<n)){
            aux[msk] = proba;
            nxt(msk,proba,a[i]);
        }
        F0(msk,(1<<n)){
            F0(j,4){
                int mskp = msk;
                if(j&1) mskp |= (1<<i);
                if(j&2) mskp |= (1<<(n-i-1));
                dp[j][msk] *= aux[mskp] - aux[(1<<n)-1];
                dp[j][msk] %= mod;
            }
        }
        fila_llena[i] = aux[(1<<n)-1];
    }
    int alguna_fila = 1;
    F0(i,n) alguna_fila *= (1-fila_llena[i]), alguna_fila %= mod;
    alguna_fila = 1-alguna_fila;

    int res = 0;
    F0(j,4){
        F0(msk,(1<<n)){
            if(j == 0 and msk == 0) continue;
            if((__builtin_popcount(j) + __builtin_popcount(msk))%2) res += dp[j][msk];
            else res -= dp[j][msk];
            res %= mod;
        }
    }
    res += alguna_fila;
    res %= mod;
    if(res < 0) res += mod;
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    F();
    return 0;
}