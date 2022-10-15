#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 2503;

double dst[maxn][maxn];

int n;

double mem[maxn][maxn][2];

int f(int x){
    return (x+n)%n;
}

double dp(int l, int r, bool b){ 
    // b == 0  -> starting from l, clockwise
    // b == 1 -> starting from r, counterclockwise
    if (mem[l][r][b]) return mem[l][r][b];
    if (f(l+1)==r) return 0;
    // if (b==1 && f())
    if (!b){
        mem[l][r][b] = max(dst[l][f(r-1)] + dp(l,f(r-1),1),
                           dst[l][f(l+1)] + dp(f(l+1), r, 0));
    }else{
        mem[l][r][b] = max(dst[f(l+1)][r] + dp(f(l+1), r, 0),
                           dst[r][f(r-1)] + dp(l,f(r-1),1));
    }
    return mem[l][r][b];
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<pii> v;
    REP(i,n){
        int x, y; cin>>x>>y;
        v.pb({x,y});
    }
    REP(i,n){
        REP(j,n){
            dst[i][j] = hypot(v[i].f-v[j].f, v[i].s-v[j].s);
        }
    }
    double re = 0;
    REP(i,n) REP(j,n){
        if (i!=j) {
            MXTO(re, dst[i][j] + dp(i,j,0) + dp(j,i,0));
            // if (re > 5){
            //     cout<<i <<' '<<j<<endl; return 0;
            // }
        }
    }
    cout<<fixed<<setprecision(12)<<re<<'\n';
}