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
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e6+5;

int n,m,k;
int g[1003][1003];
int B[41][41];
int closest[1003][1003][41];

signed main(){
    IOS();
    cin>>n>>m>>k;
    for (int i =0 ; i<n; ++i){
        for (int j = 0; j<m; ++j) {
            cin>>g[i][j]; -- g[i][j];
        }
    }
//    vector<pii> G;
    memset(B, 0x3f, sizeof B);
    for (int i = 0; i<k; ++i) B[i][i] = 1;
    memset(closest, 0x3f, sizeof closest);
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            closest[i][j][g[i][j]] = 0;
            for (int kk = 0; kk<k; ++kk) {
                if (i) closest[i][j][kk] = min(closest[i][j][kk], closest[i-1][j][kk]+1);
                if (j) closest[i][j][kk] = min(closest[i][j][kk], closest[i][j-1][kk]+1);
                MN(B[g[i][j]][kk], 1+closest[i][j][kk]);
                MN(B[kk][g[i][j]], 1+closest[i][j][kk]);
            }
        }
        for (int j = m-1; j>=0; --j) {
            closest[i][j][g[i][j]] = 0;
            for (int kk = 0; kk<k; ++kk) {
                if (i) closest[i][j][kk] = min(closest[i][j][kk], closest[i-1][j][kk]+1);
                if (j<m-1) closest[i][j][kk] = min(closest[i][j][kk], closest[i][j+1][kk]+1);
                MN(B[g[i][j]][kk], 1+closest[i][j][kk]);
                MN(B[kk][g[i][j]], 1+closest[i][j][kk]);
            }
        }
    }
//    SORT_UNIQUE(G);
//    for (auto & p : G) B[p.f][p.s] = 1;
    for (int kk = 0; kk<k; ++kk) {
        for (int i = 0; i<k; ++i) {
            for (int j = 0; j<k; ++j) {
                B[i][j] = min(B[i][j], B[i][kk] + B[kk][j]);
            }
        }
    }
    vector<int> m1(k), m2(k);
    int q; cin>>q;
    bug(B[0][7]);
    while (q--) {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2; --r1; --c1; --r2; --c2;
        fill(ALL(m1), 1e8);
        fill(ALL(m2), 1e8);
        for (int lol = 0; lol<2; ++lol) {
            for (int i = r1-k; i<=r1+k; ++i) {
                if (i>=0 && i<n) {
                    int dst = abs(r1-i);
                    for (int j = c1-(k-dst); j<=c1+(k-dst); ++j) {
                        if (j>=0 && j<m) {
                            MN(m1[g[i][j]] , dst + abs(j-c1));
                        }
                    }
                }
            }
            if (!lol) {
                swap(m1,m2); swap(r1,r2); swap(c1,c2);
            }
        }
        int re = abs(r1-r2) + abs(c1-c2);
        for (int i = 0; i<k; ++i) {
            for (int j =0 ;j<k; ++j) {
                re = min(re, m1[i] + m2[j] + B[i][j]+1 - (i==j));
                if (m1[i] + m2[j] + B[i][j] == re)
                    bug(m1[i], m2[j], B[i][j]);
            }
        }
        cout<<re<<endl;
    }

}