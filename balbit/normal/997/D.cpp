#include <bits/stdc++.h>
#undef BALBIT
using namespace std;
#define ll long long
//#define int ll
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
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 4002;

int n, m, k;
ll dp[76][maxn];
int ways[2][76]; // number of ways to make a cycle of length K

int at=0;

ll C[80][80];
inline void f(ll &x){
    if (x >= mod) x -= mod;
}

inline void f(int &x){
    if (x >= mod) x -= mod;
}

void build(){
    C[0][0] = 1;
    for (int i = 0; i<80; ++i) for (int j = 0; j<=i; ++j) {
        if (!i || !j) {
            C[i][j] = 1;
        }else{
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}

int X[2][4005], Y[2][4005];

signed main(){
    IOS();
//    srand(time(0));

    build();
    bug(C[2][1], C[2][0], C[2][2]);
#ifndef BALBIT
    cin>>n>>m>>k;
//    if ( )
#else
    n=m=4000; k = 75;
#endif
    array<vector<pii>, 2> E;
    for (int i = 0; i<n-1; ++i) {
        int a,b;
#ifdef BALBIT
        a = i+1; b = rand() % (i+1);
#else
        cin>>a>>b; --a; --b;
#endif // BALBIT
        X[0][i]=a; Y[0][i] = b;
    }
    for (int i = 0; i<m-1; ++i) {
        int a,b;
#ifdef BALBIT
        a = i+1; b = rand() % (i+1);
#else
        cin>>a>>b; --a; --b;
#endif // BALBIT
        X[1][i] = a; Y[1][i] = b;
    }

    bug("ALIVE");
    clock_t t=clock();
    for (int B = 0; B < 2; ++B) {
        int N = B==0?n:m;
        for (int i = 0; i<N; ++i) {
    //        bug(B,i);
            memset(dp[0], 0, sizeof dp[0]);
            dp[0][i] = 1;
            ways[B][0] += 1;
            for (int L = 1; L <= k; ++L ) {
                memset(dp[L],0,sizeof dp[L]);

                for (int it = 0; it<N-1; ++it) {
    //                if (dp[L-1][X[B][it]]) {
                        dp[L][Y[B][it]] += dp[L-1][X[B][it]];
                        f(dp[L][Y[B][it]]);
    //                }
    //                if (dp[L-1][Y[B][it]]){
                        dp[L][X[B][it]] += dp[L-1][Y[B][it]];
                        f(dp[L][X[B][it]]);
    //                }
                }
//                if (!(L&0b11)) for (int i = 0; i<N; ++i) dp[L][i] %= mod;
//                 for (int it = 0; it<N; ++it) dp[L][it] %= mod;
                ways[B][L] += dp[L][i]%mod;
                f(ways[B][L]);
    //            bug(B,i,L,ways[B][i][L]);
            }
        }
    }
    bug((clock() - t) / (double)CLOCKS_PER_SEC);
    t = clock();
    bug("ALIVE");
    int re = 0;
    for (int tk = 0; tk <= k; ++tk) {
        re += ways[0][tk] * (ll) ways[1][k-tk] % mod * (ll)C[k][tk] % mod;
//                bug(tk,i,j,ways[0][i][tk], ways[1][j][k-tk], C[k][tk]);
        f(re);
    }
    bug((clock() - t) / (double)CLOCKS_PER_SEC);
    cout<<re<<endl;
}